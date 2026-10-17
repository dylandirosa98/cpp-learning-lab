#!/usr/bin/env python3

from __future__ import annotations

import argparse
import json
import os
import re
import shutil
import subprocess
import sys
import textwrap
import webbrowser
from pathlib import Path


ROOT = Path(__file__).resolve().parents[1]
LESSONS = ROOT / "lessons"
STARTERS = ROOT / "starters"
WORKSPACES = ROOT / "workspaces"
SOLUTIONS = ROOT / "solutions"
STATE = ROOT / ".course"
PROGRESS_FILE = STATE / "progress.json"
BUILD = STATE / "build"


def load_lessons() -> list[dict]:
    lessons = []
    for path in sorted(LESSONS.glob("*.json")):
        lesson = json.loads(path.read_text())
        lesson["key"] = path.stem
        lessons.append(lesson)
    return sorted(lessons, key=lambda item: item["order"])


def normalize_lesson_id(value: str) -> str:
    compact = value.strip().lower().replace("lesson", "").strip()
    parts = compact.replace("_", ".").split(".")
    if len(parts) == 2 and (parts[0].isdigit() or len(parts[0]) == 1 and parts[0].isalpha()):
        chapter = f"{int(parts[0]):02d}" if parts[0].isdigit() else parts[0]
        if parts[1] == "x":
            return f"{chapter}_x"
        if parts[1].isdigit():
            return f"{chapter}_{int(parts[1]):02d}"
    if compact.endswith("x") and compact[:-1].isdigit():
        return f"{int(compact[:-1]):02d}_x"
    return compact


def lesson_by_id(value: str) -> dict:
    key = normalize_lesson_id(value)
    for lesson in load_lessons():
        if lesson["key"] == key:
            return lesson
    raise SystemExit(f"Unknown lesson: {value}. Run './course list' to see valid IDs.")


def display_id(lesson: dict) -> str:
    return lesson["id"]


def display_progress_key(key: str) -> str:
    match = re.fullmatch(r"([a-zA-Z]+|\d+)_([a-zA-Z]+|\d+)", key)
    if match is None:
        return key
    chapter, lesson = match.groups()
    chapter = chapter.upper() if chapter.isalpha() else str(int(chapter))
    lesson = lesson.lower() if lesson.isalpha() else str(int(lesson))
    return f"{chapter}.{lesson}"


def workspace_path(lesson: dict) -> Path:
    chapter = lesson["id"].split(".")[0]
    chapter_directory = f"{int(chapter):02d}" if chapter.isdigit() else chapter.upper()
    return WORKSPACES / chapter_directory / lesson["key"]


def load_progress() -> dict:
    if not PROGRESS_FILE.exists():
        return {"completed": [], "hintsViewed": {}}
    return json.loads(PROGRESS_FILE.read_text())


def save_progress(progress: dict) -> None:
    STATE.mkdir(exist_ok=True)
    PROGRESS_FILE.write_text(json.dumps(progress, indent=2) + "\n")


def run_git(*args: str) -> subprocess.CompletedProcess[str]:
    return subprocess.run(
        ["git", *args], cwd=ROOT, capture_output=True, text=True
    )


def git_sync_lesson(lesson: dict, source_dir: Path) -> bool:
    if os.environ.get("COURSE_NO_SYNC"):
        return True
    try:
        relative_source = source_dir.resolve().relative_to(WORKSPACES.resolve())
    except ValueError:
        return True
    if relative_source != workspace_path(lesson).relative_to(WORKSPACES):
        return True
    if run_git("rev-parse", "--is-inside-work-tree").returncode != 0:
        print("Git sync skipped: this folder is not a Git repository.")
        return True
    if run_git("remote", "get-url", "origin").returncode != 0:
        print("Git sync skipped: no origin remote is configured.")
        return True
    try:
        sync_repository(f"Complete lesson {lesson['id']} and save course work")
    except SystemExit as error:
        print(f"Lesson checks passed, but synchronization did not finish:\n{error}")
        return False
    return True


def checked_git(*args: str) -> subprocess.CompletedProcess[str]:
    result = run_git(*args)
    if result.returncode != 0:
        detail = result.stderr.strip() or result.stdout.strip()
        raise SystemExit(
            f"Git sync failed during git {args[0]}:\n{detail}\n"
            "Your files/local commits are preserved. Resolve the reported issue and run './course sync' again."
        )
    return result


def snapshot_course(message: str) -> None:
    checked_git("add", "--all")
    changed = run_git("diff", "--cached", "--quiet")
    if changed.returncode == 1:
        checked_git("commit", "-m", message)
        print("Saved course work locally (including unfinished exercises).")
    elif changed.returncode != 0:
        raise SystemExit(f"Could not inspect staged changes: {changed.stderr.strip()}")


def merge_remote_progress() -> bool:
    """Only auto-resolve the append-only progress data, never learner code."""
    progress_path = str(PROGRESS_FILE.relative_to(ROOT))
    conflicts = run_git("diff", "--name-only", "--diff-filter=U").stdout.splitlines()
    if conflicts != [progress_path]:
        return False
    try:
        ours = json.loads(checked_git("show", f":2:{progress_path}").stdout)
        theirs = json.loads(checked_git("show", f":3:{progress_path}").stdout)
        if (set(ours) | set(theirs)) - {"completed", "hintsViewed"}:
            return False
        completed = list(dict.fromkeys(ours.get("completed", []) + theirs.get("completed", [])))
        hints = dict(ours.get("hintsViewed", {}))
        for key, value in theirs.get("hintsViewed", {}).items():
            hints[key] = max(hints.get(key, 0), value)
        save_progress({"completed": completed, "hintsViewed": hints})
    except (ValueError, TypeError, OSError):
        return False
    checked_git("add", "--", progress_path)
    checked_git("commit", "--no-edit")
    print("Combined progress from both machines.")
    return True


def sync_repository(message: str = "Sync course work across machines") -> None:
    if run_git("rev-parse", "--is-inside-work-tree").returncode != 0:
        raise SystemExit("This folder is not a Git repository. Clone it with git instead of downloading a ZIP.")
    if run_git("remote", "get-url", "origin").returncode != 0:
        raise SystemExit("No origin remote is configured. Clone the GitHub repository first.")

    branch = checked_git("branch", "--show-current").stdout.strip()
    if not branch:
        raise SystemExit("Git sync stopped: detached HEAD. Switch to your working branch first.")
    git_dir = Path(checked_git("rev-parse", "--absolute-git-dir").stdout.strip())
    if any((git_dir / name).exists() for name in ("MERGE_HEAD", "rebase-merge", "rebase-apply", "CHERRY_PICK_HEAD")):
        raise SystemExit("Git sync stopped: finish the existing merge/rebase/cherry-pick first. No files were overwritten.")
    if checked_git("ls-files", "--unmerged").stdout.strip():
        raise SystemExit("Git sync stopped: resolve existing Git conflicts first.")

    setup_all()
    snapshot_course(message)
    # Never rewrite shared history, force-push, or hide edits in an autostash.
    # A clean local snapshot is retained even when offline/authentication fails.
    for attempt in range(3):
        checked_git("fetch", "origin")
        remote_ref = f"refs/remotes/origin/{branch}"
        if run_git("rev-parse", "--verify", remote_ref).returncode == 0:
            merged = run_git("merge", "--no-edit", remote_ref)
            if merged.returncode != 0 and not merge_remote_progress():
                conflicts = run_git("diff", "--name-only", "--diff-filter=U").stdout.strip()
                raise SystemExit(
                    "Git sync needs a manual merge; both versions are preserved.\n"
                    + (f"Conflicting files:\n{conflicts}\n" if conflicts else merged.stderr + merged.stdout)
                    + "Resolve conflicts, git add the resolved files, and git commit; then run './course sync'."
                )
        setup_all()
        snapshot_course("Prepare course workspaces after sync")
        pushed = run_git("push", "-u", "origin", branch)
        if pushed.returncode == 0:
            print(f"Git sync complete: saved, pulled, and pushed origin/{branch}.")
            return
        detail = pushed.stderr.strip() or pushed.stdout.strip()
        if attempt < 2 and any(reason in detail for reason in ("non-fast-forward", "fetch first")):
            continue
        raise SystemExit(
            f"Local work is saved, but pushing failed:\n{detail}\n"
            "Run './course sync' again after fixing connectivity/authentication."
        )


def ensure_workspace(lesson: dict, announce: bool = True) -> Path:
    source = STARTERS / lesson["key"]
    destination = workspace_path(lesson)
    legacy = WORKSPACES / lesson["key"]
    if legacy.exists():
        if destination.exists():
            # Git moves source files but leaves ignored compiler outputs behind.
            # Those leftovers are not a second learner workspace.
            remaining = run_git("ls-files", "--cached", "--others", "--exclude-standard", "--", str(legacy.relative_to(ROOT)))
            if remaining.returncode != 0 or remaining.stdout.strip():
                raise SystemExit(
                    f"Both old and new workspace paths contain work for {lesson['id']}: "
                    f"{legacy.relative_to(ROOT)} and {destination.relative_to(ROOT)}"
                )
        else:
            destination.parent.mkdir(parents=True, exist_ok=True)
            legacy.rename(destination)
            if announce:
                print(f"Moved {legacy.relative_to(ROOT)} to {destination.relative_to(ROOT)}")
    if not destination.exists():
        destination.parent.mkdir(parents=True, exist_ok=True)
        shutil.copytree(source, destination)
        if announce:
            print(f"Created {destination.relative_to(ROOT)}")
    return destination


def setup_all() -> None:
    WORKSPACES.mkdir(exist_ok=True)
    for lesson in load_lessons():
        ensure_workspace(lesson)
    print("All course workspaces are ready.")


def strip_cpp_comments(content: str) -> str:
    content = re.sub(r"/\*.*?\*/", "", content, flags=re.DOTALL)
    return re.sub(r"//.*", "", content)


def normalized_cpp_code(content: str) -> str:
    return "\n".join(line.strip() for line in strip_cpp_comments(content).splitlines() if line.strip())


def compact_cpp(content: str) -> str:
    # Canonical single-space form. Kept for compatibility; concept checks
    # in source_rule_failures use token_regex for style-insensitive matching.
    stripped = strip_cpp_comments(content).replace("\r\n", "\n").replace("\r", "\n")
    return re.sub(r"\s+", " ", stripped).strip()


def token_regex(token: str) -> re.Pattern[str] | None:
    # Style-insensitive matcher for a source token: every gap between
    # non-whitespace characters matches any whitespace run (including none),
    # so formatter wrapping, indentation, and brace placement never matter.
    # Identifier boundaries are guarded so `std::string` does not match
    # inside `std::string_view` and `extern` does not match `external`.
    chars = [char for char in strip_cpp_comments(token) if not char.isspace()]
    if not chars:
        return None
    pattern = r"\s*".join(re.escape(char) for char in chars)
    prefix = r"(?<![\w])" if re.match(r"\w", chars[0]) else ""
    suffix = r"(?![\w])" if re.match(r"\w", chars[-1]) else ""
    return re.compile(prefix + pattern + suffix)


def top_block_comment(content: str) -> tuple[str, str] | None:
    if not content.startswith("/*"):
        return None
    end = content.find("*/")
    if end < 0:
        return None
    end += 2
    return content[:end], content[end:]


def refresh_instructions() -> None:
    setup_all()
    preserved = []
    for lesson in load_lessons():
        starter_directory = STARTERS / lesson["key"]
        workspace_directory = workspace_path(lesson)
        for starter in sorted(starter_directory.iterdir()):
            if starter.suffix not in {".cpp", ".h"}:
                continue
            workspace = workspace_directory / starter.name
            starter_content = starter.read_text()
            workspace_content = workspace.read_text()
            if normalized_cpp_code(starter_content) == normalized_cpp_code(workspace_content):
                workspace.write_text(starter_content)
                continue
            starter_parts = top_block_comment(starter_content)
            workspace_parts = top_block_comment(workspace_content)
            if starter_parts is None or workspace_parts is None:
                preserved.append(str(workspace.relative_to(ROOT)))
                continue
            workspace.write_text(starter_parts[0] + workspace_parts[1])
            preserved.append(str(workspace.relative_to(ROOT)))
    print("Workspace instructions refreshed.")
    if preserved:
        print("Preserved learner code in:")
        for path in preserved:
            print(f"- {path}")


def print_wrapped(text: str, indent: str = "") -> None:
    width = max(60, shutil.get_terminal_size((100, 24)).columns - len(indent))
    print(textwrap.fill(text, width=width, initial_indent=indent, subsequent_indent=indent))


def show_lesson(lesson: dict) -> None:
    ensure_workspace(lesson, announce=False)
    print(f"\n{lesson['id']} - {lesson['title']}")
    print("=" * (len(lesson["title"]) + len(lesson["id"]) + 3))
    print(f"LearnCpp: {lesson['url']}")
    print(f"Estimated challenge time: {lesson['estimatedMinutes']} minutes\n")
    print("Original recap")
    for paragraph in lesson["recap"]:
        print_wrapped(paragraph, "  ")
    print("\nObjectives")
    for item in lesson["objectives"]:
        print_wrapped(item, "  - ")
    print("\nWatch for")
    for item in lesson["warnings"]:
        print_wrapped(item, "  - ")
    print("\nChallenge")
    print_wrapped(lesson["challenge"], "  ")
    if lesson.get("behaviorTests"):
        print("\nTesting")
        print("The checker calls your functions with multiple inputs and checks their results.")
        print("No source-token checks or console formatting requirements apply.")
    else:
        print("\nExpected output")
        print("```text")
        print("\n".join(lesson["expectedOutput"]))
        print("```")
    print(f"\nWorkspace: {workspace_path(lesson)}")


def list_lessons() -> None:
    progress = load_progress()
    completed = set(progress.get("completed", []))
    print("\nLearnCpp Companion\n")
    previous_chapter = None
    for lesson in load_lessons():
        chapter = lesson["id"].split(".")[0]
        if chapter != previous_chapter:
            if previous_chapter is not None:
                print()
            print(f"Chapter {chapter}")
            previous_chapter = chapter
        marker = "[x]" if lesson["key"] in completed else "[ ]"
        print(f"{marker} {lesson['id']:<4} {lesson['title']:<52} {lesson['estimatedMinutes']:>2} min")


def source_rule_failures(lesson: dict, source_dir: Path) -> list[str]:
    failures = []
    for rule in lesson.get("sourceChecks", []):
        path = source_dir / rule["file"]
        if not path.exists():
            failures.append(f"Missing required file: {rule['file']}")
            continue
        content = strip_cpp_comments(path.read_text())
        for token in rule.get("contains", []):
            pattern = token_regex(token)
            if pattern is None:
                continue
            if not pattern.search(content):
                failures.append(f"{rule['file']} must contain: {token}")
        for token in rule.get("notContains", []):
            pattern = token_regex(token)
            if pattern is None:
                continue
            if pattern.search(content):
                failures.append(f"{rule['file']} must not contain: {token}")
    return failures


def compile_and_run(lesson: dict, source_dir: Path) -> tuple[bool, str]:
    compiler = shutil.which("g++")
    if compiler is None:
        return False, "g++ is not installed or is not on PATH."

    lesson_build = BUILD / lesson["key"]
    lesson_build.mkdir(parents=True, exist_ok=True)
    executable = lesson_build / "challenge"
    if lesson.get("behaviorTests"):
        # Trusted drivers live outside the editable workspace. They include its
        # main.cpp with main renamed, then exercise the learner's public functions.
        sources = [str(ROOT / source) for source in lesson["behaviorTests"]]
        sources += [str(source_dir / source) for source in lesson["sources"] if source != "main.cpp"]
    else:
        sources = [str(source_dir / source) for source in lesson["sources"]]
    command = [
        compiler,
        "-std=c++20",
        "-Wall",
        "-Wextra",
        "-Wpedantic",
        "-g",
        f"-I{source_dir}",
        *sources,
        "-o",
        str(executable),
    ]
    build = subprocess.run(command, capture_output=True, text=True)
    if build.returncode != 0:
        return False, f"Compilation failed:\n{build.stderr.rstrip()}"
    if build.stderr.strip() and not lesson.get("behaviorTests"):
        return False, f"Compile warnings must be fixed:\n{build.stderr.rstrip()}"

    if lesson.get("behaviorTests"):
        for case in lesson.get("testCases", [{"args": [], "exitCode": 0}]):
            args = case.get("args", [])
            try:
                run = subprocess.run([str(executable), *args], capture_output=True, text=True, timeout=5)
            except subprocess.TimeoutExpired:
                return False, f"Behavioral test timed out (arguments: {args})."
            expected_status = case.get("exitCode", 0)
            if run.returncode != expected_status:
                detail = run.stderr.strip() or run.stdout.strip()
                return False, (
                    f"Behavioral tests failed (arguments: {args}): expected exit status "
                    f"{expected_status}, got {run.returncode}.\n{detail}"
                )
        warnings = f"\nCompiler warnings (not a test failure):\n{build.stderr.rstrip()}" if build.stderr.strip() else ""
        return True, "All behavioral tests passed." + warnings

    try:
        run = subprocess.run([str(executable)], capture_output=True, text=True, timeout=5)
    except subprocess.TimeoutExpired:
        return False, "The program did not finish within five seconds."
    if run.returncode != 0:
        return False, f"Program exited with status {run.returncode}:\n{run.stderr.rstrip()}"
    if run.stderr:
        return False, f"Unexpected diagnostic output must be removed or disabled:\n{run.stderr.rstrip()}"

    expected = "\n".join(lesson["expectedOutput"]) + "\n"
    if run.stdout != expected:
        return False, f"Output did not match.\n\nExpected:\n{expected}\nActual:\n{run.stdout}"

    failures = source_rule_failures(lesson, source_dir)
    if failures:
        return False, "Concept checks failed:\n- " + "\n- ".join(failures)
    return True, "All checks passed."


def check_lesson(lesson: dict, source_dir: Path | None = None, mark: bool = True) -> bool:
    source_dir = source_dir or ensure_workspace(lesson)
    print(f"Checking {lesson['id']} from {source_dir.relative_to(ROOT)}...")
    passed, message = compile_and_run(lesson, source_dir)
    print(message)
    if passed and mark:
        progress = load_progress()
        completed = progress.setdefault("completed", [])
        if lesson["key"] not in completed:
            completed.append(lesson["key"])
            save_progress(progress)
            print("Progress saved.")
        if not git_sync_lesson(lesson, source_dir):
            return False
    return passed


def show_hint(lesson: dict, requested: int | None) -> None:
    progress = load_progress()
    viewed = progress.setdefault("hintsViewed", {})
    if requested is None:
        requested = min(viewed.get(lesson["key"], 0) + 1, len(lesson["hints"]))
    if requested < 1 or requested > len(lesson["hints"]):
        raise SystemExit(f"Hint number must be between 1 and {len(lesson['hints'])}.")
    viewed[lesson["key"]] = max(viewed.get(lesson["key"], 0), requested)
    save_progress(progress)
    print(f"Hint {requested}/{len(lesson['hints'])}: {lesson['hints'][requested - 1]}")


def show_solution(lesson: dict) -> None:
    print("Reference solutions are for review after a real attempt.")
    print(f"Solution directory: {SOLUTIONS / lesson['key']}")


def reset_lesson(lesson: dict, assume_yes: bool) -> None:
    destination = workspace_path(lesson)
    if destination.exists() and not assume_yes:
        answer = input(f"Replace all edits in {destination.relative_to(ROOT)}? [y/N] ").strip().lower()
        if answer != "y":
            print("Reset cancelled.")
            return
    if destination.exists():
        shutil.rmtree(destination)
    ensure_workspace(lesson)


def show_progress() -> None:
    lessons = load_lessons()
    completed = set(load_progress().get("completed", []))
    catalog_keys = {lesson["key"] for lesson in lessons}
    catalog_completed = completed & catalog_keys
    print(f"Completed {len(catalog_completed)}/{len(lessons)} lessons")
    chapters = dict.fromkeys(lesson["id"].split(".")[0] for lesson in lessons)
    for chapter in chapters:
        chapter_lessons = [lesson for lesson in lessons if lesson["id"].startswith(f"{chapter}.")]
        chapter_completed = sum(lesson["key"] in completed for lesson in chapter_lessons)
        print(f"Chapter {chapter}: {chapter_completed}/{len(chapter_lessons)}")
    list_lessons()
    uncataloged = sorted(completed - catalog_keys)
    if uncataloged:
        print("\nCompleted lessons not in this course catalog")
        for key in uncataloged:
            print(f"[x] {display_progress_key(key)}")


def next_lesson() -> dict | None:
    completed = set(load_progress().get("completed", []))
    return next((lesson for lesson in load_lessons() if lesson["key"] not in completed), None)


def open_clion() -> None:
    setup_all()
    launcher = shutil.which("clion")
    if launcher is None:
        raise SystemExit(f"CLion launcher was not found. Open this directory manually: {ROOT}")
    subprocess.Popen([launcher, str(ROOT)], stdout=subprocess.DEVNULL, stderr=subprocess.DEVNULL)
    print(f"Opening {ROOT} in CLion.")


def verify_solutions() -> None:
    failed = []
    for lesson in load_lessons():
        if not check_lesson(lesson, SOLUTIONS / lesson["key"], mark=False):
            failed.append(lesson["id"])
    if failed:
        raise SystemExit(f"Solution verification failed: {', '.join(failed)}")
    print("All reference solutions passed.")


def interactive() -> None:
    setup_all()
    while True:
        list_lessons()
        choice = input("\nLesson ID, 'next', 'progress', 'open', or 'quit': ").strip().lower()
        if choice in {"q", "quit", "exit"}:
            return
        if choice == "open":
            open_clion()
            continue
        if choice == "progress":
            show_progress()
            continue
        lesson = next_lesson() if choice == "next" else lesson_by_id(choice)
        if lesson is None:
            print("All available lessons are complete.")
            continue
        show_lesson(lesson)
        while True:
            action = input("\n[read] original, [check], [hint], [solution], [back]: ").strip().lower()
            if action in {"b", "back"}:
                break
            if action in {"r", "read"}:
                webbrowser.open(lesson["url"])
            elif action in {"c", "check"}:
                check_lesson(lesson)
            elif action in {"h", "hint"}:
                show_hint(lesson, None)
            elif action in {"s", "solution"}:
                show_solution(lesson)
            else:
                print("Unknown action.")


def build_parser() -> argparse.ArgumentParser:
    parser = argparse.ArgumentParser(description="Interactive LearnCpp companion")
    subparsers = parser.add_subparsers(dest="command")
    subparsers.add_parser("setup")
    subparsers.add_parser("refresh-instructions")
    subparsers.add_parser("list")
    subparsers.add_parser("progress")
    subparsers.add_parser("next")
    subparsers.add_parser("open")
    subparsers.add_parser("verify-solutions")
    subparsers.add_parser("sync")
    for name in ("lesson", "read", "check", "solution"):
        command = subparsers.add_parser(name)
        command.add_argument("lesson_id")
    hint = subparsers.add_parser("hint")
    hint.add_argument("lesson_id")
    hint.add_argument("number", nargs="?", type=int)
    reset = subparsers.add_parser("reset")
    reset.add_argument("lesson_id")
    reset.add_argument("--yes", action="store_true")
    return parser


def main() -> None:
    args = build_parser().parse_args()
    if args.command is None:
        interactive()
    elif args.command == "setup":
        setup_all()
    elif args.command == "refresh-instructions":
        refresh_instructions()
    elif args.command == "list":
        list_lessons()
    elif args.command == "progress":
        show_progress()
    elif args.command == "next":
        lesson = next_lesson()
        if lesson is None:
            print("All available lessons are complete.")
        else:
            show_lesson(lesson)
    elif args.command == "open":
        open_clion()
    elif args.command == "verify-solutions":
        verify_solutions()
    elif args.command == "sync":
        sync_repository()
    else:
        lesson = lesson_by_id(args.lesson_id)
        if args.command == "lesson":
            show_lesson(lesson)
        elif args.command == "read":
            webbrowser.open(lesson["url"])
            print(f"Opened {lesson['url']}")
        elif args.command == "check":
            if not check_lesson(lesson):
                raise SystemExit(1)
        elif args.command == "hint":
            show_hint(lesson, args.number)
        elif args.command == "solution":
            show_solution(lesson)
        elif args.command == "reset":
            reset_lesson(lesson, args.yes)


if __name__ == "__main__":
    main()
