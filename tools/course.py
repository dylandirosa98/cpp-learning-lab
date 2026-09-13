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
    if len(parts) == 2 and parts[0].isdigit() and parts[1] == "x":
        return f"{int(parts[0]):02d}_x"
    if compact.endswith("x") and compact[:-1].isdigit():
        return f"{int(compact[:-1]):02d}_x"
    if len(parts) == 2 and parts[0].isdigit() and parts[1].isdigit():
        return f"{int(parts[0]):02d}_{int(parts[1]):02d}"
    return compact


def lesson_by_id(value: str) -> dict:
    key = normalize_lesson_id(value)
    for lesson in load_lessons():
        if lesson["key"] == key:
            return lesson
    raise SystemExit(f"Unknown lesson: {value}. Run './course list' to see valid IDs.")


def display_id(lesson: dict) -> str:
    return lesson["id"]


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


def git_sync_lesson(lesson: dict, source_dir: Path) -> None:
    if os.environ.get("COURSE_NO_SYNC"):
        return
    try:
        relative_source = source_dir.resolve().relative_to(WORKSPACES.resolve())
    except ValueError:
        return
    if relative_source != Path(lesson["key"]):
        return
    if run_git("rev-parse", "--is-inside-work-tree").returncode != 0:
        print("Git sync skipped: this folder is not a Git repository.")
        return
    if run_git("remote", "get-url", "origin").returncode != 0:
        print("Git sync skipped: no origin remote is configured.")
        return

    paths = [str(source_dir.relative_to(ROOT)), str(PROGRESS_FILE.relative_to(ROOT))]
    status = run_git("status", "--porcelain", "--", *paths)
    if not status.stdout.strip():
        print("Git sync: lesson is already committed.")
        return

    added = run_git("add", "--", *paths)
    if added.returncode != 0:
        print(f"Git sync failed while staging: {added.stderr.strip()}")
        return
    committed = run_git(
        "commit", "--only", "-m", f"Complete lesson {lesson['id']}", "--", *paths
    )
    if committed.returncode != 0:
        print(f"Git sync failed while committing: {committed.stderr.strip()}")
        return

    branch = run_git("branch", "--show-current").stdout.strip()
    pushed = run_git("push", "-u", "origin", branch)
    if pushed.returncode != 0:
        print("Git commit saved locally, but push failed:")
        print(pushed.stderr.strip())
        print("Run './course sync' after resolving the remote changes or authentication.")
        return
    print("Git sync: committed and pushed.")


def sync_repository() -> None:
    if run_git("rev-parse", "--is-inside-work-tree").returncode != 0:
        raise SystemExit("This folder is not a Git repository. Clone it with git instead of downloading a ZIP.")
    if run_git("remote", "get-url", "origin").returncode != 0:
        raise SystemExit("No origin remote is configured. Clone the GitHub repository first.")

    pulled = run_git("pull", "--rebase", "--autostash")
    if pulled.returncode != 0:
        detail = pulled.stderr.strip() or pulled.stdout.strip()
        raise SystemExit(f"Git sync failed:\n{detail}")
    print(pulled.stdout.strip() or "Repository is up to date.")
    setup_all()


def ensure_workspace(lesson: dict, announce: bool = True) -> Path:
    source = STARTERS / lesson["key"]
    destination = WORKSPACES / lesson["key"]
    if not destination.exists():
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
    return re.sub(r"\s*([{}])\s*", r"\1", strip_cpp_comments(content))


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
        workspace_directory = WORKSPACES / lesson["key"]
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
    print("\nExpected output")
    print("```text")
    print("\n".join(lesson["expectedOutput"]))
    print("```")
    print(f"\nWorkspace: {WORKSPACES / lesson['key']}")


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
        content = compact_cpp(path.read_text())
        for token in rule.get("contains", []):
            if compact_cpp(token) not in content:
                failures.append(f"{rule['file']} must contain: {token}")
        for token in rule.get("notContains", []):
            if compact_cpp(token) in content:
                failures.append(f"{rule['file']} must not contain: {token}")
    return failures


def compile_and_run(lesson: dict, source_dir: Path) -> tuple[bool, str]:
    compiler = shutil.which("g++")
    if compiler is None:
        return False, "g++ is not installed or is not on PATH."

    lesson_build = BUILD / lesson["key"]
    lesson_build.mkdir(parents=True, exist_ok=True)
    executable = lesson_build / "challenge"
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
    if build.stderr.strip():
        return False, f"Compile warnings must be fixed:\n{build.stderr.rstrip()}"

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
        git_sync_lesson(lesson, source_dir)
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
    destination = WORKSPACES / lesson["key"]
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
    print(f"Completed {len(completed)}/{len(lessons)} lessons")
    for chapter in sorted({lesson["id"].split(".")[0] for lesson in lessons}, key=int):
        chapter_lessons = [lesson for lesson in lessons if lesson["id"].startswith(f"{chapter}.")]
        chapter_completed = sum(lesson["key"] in completed for lesson in chapter_lessons)
        print(f"Chapter {chapter}: {chapter_completed}/{len(chapter_lessons)}")
    list_lessons()


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
