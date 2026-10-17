import io
import json
import shutil
import subprocess
import tempfile
import unittest
from contextlib import ExitStack, redirect_stdout
from pathlib import Path
from unittest.mock import patch

from tools import course


@unittest.skipUnless(shutil.which("git"), "git is required")
class SyncTest(unittest.TestCase):
    def git(self, root, *args):
        result = subprocess.run(["git", *args], cwd=root, capture_output=True, text=True)
        self.assertEqual(result.returncode, 0, result.stderr)
        return result.stdout.strip()

    def setUp(self):
        self.temp = tempfile.TemporaryDirectory()
        self.addCleanup(self.temp.cleanup)
        self.base = Path(self.temp.name)
        self.remote = self.base / "remote.git"
        self.git(self.base, "init", "--bare", "--initial-branch=main", str(self.remote))
        self.a = self.base / "desktop"
        self.git(self.base, "clone", str(self.remote), str(self.a))
        self.configure(self.a)
        (self.a / "lessons").mkdir()
        (self.a / ".course").mkdir()
        (self.a / ".course/progress.json").write_text(json.dumps({"completed": [], "hintsViewed": {}}))
        (self.a / "exercise.cpp").write_text("// initial learner code\n")
        self.git(self.a, "add", "--all")
        self.git(self.a, "commit", "-m", "Initial course")
        self.git(self.a, "push", "-u", "origin", "main")
        self.b = self.base / "laptop"
        self.git(self.base, "clone", str(self.remote), str(self.b))
        self.configure(self.b)

    def configure(self, root):
        self.git(root, "config", "user.name", "Sync Test")
        self.git(root, "config", "user.email", "sync@example.invalid")
        self.git(root, "config", "commit.gpgsign", "false")
        self.git(root, "config", "core.hooksPath", str(self.base / "no-hooks"))

    def context(self, root):
        stack = ExitStack()
        for name, path in {
            "ROOT": root, "LESSONS": root / "lessons", "WORKSPACES": root / "workspaces",
            "STARTERS": root / "starters", "STATE": root / ".course",
            "PROGRESS_FILE": root / ".course/progress.json",
        }.items():
            stack.enter_context(patch.object(course, name, path))
        stack.enter_context(redirect_stdout(io.StringIO()))
        return stack

    def sync(self, root):
        with self.context(root):
            course.sync_repository()

    def test_unfinished_work_curriculum_and_deletions_sync_both_directions(self):
        (self.a / "exercise.cpp").write_text("// unfinished desktop solution\n")
        (self.a / "new-test.txt").write_text("new behavioral tests")
        self.sync(self.a)
        self.sync(self.b)
        self.assertEqual((self.b / "exercise.cpp").read_text(), "// unfinished desktop solution\n")
        self.assertTrue((self.b / "new-test.txt").exists())
        (self.b / "new-test.txt").unlink()
        (self.b / "laptop.cpp").write_text("// laptop work\n")
        self.sync(self.b)
        self.sync(self.a)
        self.assertFalse((self.a / "new-test.txt").exists())
        self.assertTrue((self.a / "laptop.cpp").exists())
        self.assertEqual(self.git(self.a, "status", "--porcelain"), "")
        self.assertEqual(self.git(self.a, "rev-parse", "HEAD"), self.git(self.b, "rev-parse", "HEAD"))

    def test_divergent_nonconflicting_commits_are_merged_without_losing_either(self):
        (self.a / "desktop.cpp").write_text("desktop")
        (self.b / "laptop.cpp").write_text("laptop")
        self.sync(self.b)
        self.sync(self.a)
        self.sync(self.b)
        for root in (self.a, self.b):
            self.assertEqual((root / "desktop.cpp").read_text(), "desktop")
            self.assertEqual((root / "laptop.cpp").read_text(), "laptop")

    def test_pending_commit_is_pushed_even_when_no_files_are_dirty(self):
        (self.a / "pending.cpp").write_text("saved offline")
        self.git(self.a, "add", "--all")
        self.git(self.a, "commit", "-m", "Pending local work")
        self.sync(self.a)
        self.sync(self.b)
        self.assertEqual((self.b / "pending.cpp").read_text(), "saved offline")

    def test_offline_failure_keeps_local_snapshot_and_retry_pushes_it(self):
        (self.a / "offline.cpp").write_text("do not lose this")
        self.git(self.a, "remote", "set-url", "origin", str(self.base / "missing.git"))
        with self.assertRaises(SystemExit):
            self.sync(self.a)
        self.assertEqual(self.git(self.a, "show", "HEAD:offline.cpp"), "do not lose this")
        self.assertEqual(self.git(self.a, "status", "--porcelain"), "")
        self.git(self.a, "remote", "set-url", "origin", str(self.remote))
        self.sync(self.a)
        self.sync(self.b)
        self.assertTrue((self.b / "offline.cpp").exists())

    def test_progress_conflicts_union_completions_and_keep_highest_hint(self):
        (self.a / ".course/progress.json").write_text(json.dumps({
            "completed": ["08_05"], "hintsViewed": {"08_06": 2}
        }))
        (self.b / ".course/progress.json").write_text(json.dumps({
            "completed": ["08_06"], "hintsViewed": {"08_06": 1, "08_07": 3}
        }))
        self.sync(self.b)
        self.sync(self.a)
        self.sync(self.b)
        for root in (self.a, self.b):
            progress = json.loads((root / ".course/progress.json").read_text())
            self.assertEqual(set(progress["completed"]), {"08_05", "08_06"})
            self.assertEqual(progress["hintsViewed"], {"08_06": 2, "08_07": 3})

    def test_code_conflict_preserves_both_versions_and_stops(self):
        (self.a / "exercise.cpp").write_text("desktop implementation\n")
        (self.b / "exercise.cpp").write_text("laptop implementation\n")
        self.sync(self.b)
        with self.assertRaisesRegex(SystemExit, "manual merge"):
            self.sync(self.a)
        self.assertEqual(self.git(self.a, "show", "HEAD:exercise.cpp"), "desktop implementation")
        self.assertEqual(self.git(self.a, "show", "MERGE_HEAD:exercise.cpp"), "laptop implementation")
        with self.assertRaisesRegex(SystemExit, "existing merge"):
            self.sync(self.a)

    def test_ignored_outputs_are_not_published(self):
        (self.a / ".gitignore").write_text(".env\nbuild/\n")
        (self.a / ".env").write_text("test fixture only")
        (self.a / "build").mkdir()
        (self.a / "build/program").write_text("binary fixture")
        self.sync(self.a)
        tracked = self.git(self.a, "ls-files").splitlines()
        self.assertNotIn(".env", tracked)
        self.assertNotIn("build/program", tracked)

    def test_detached_head_is_refused_before_saving(self):
        self.git(self.a, "switch", "--detach")
        (self.a / "unsaved.cpp").write_text("preserve")
        with self.assertRaisesRegex(SystemExit, "detached HEAD"):
            self.sync(self.a)
        self.assertEqual((self.a / "unsaved.cpp").read_text(), "preserve")
        self.assertIn("?? unsaved.cpp", self.git(self.a, "status", "--porcelain"))

    def test_second_sync_without_changes_does_not_add_commits(self):
        self.sync(self.a)
        before = self.git(self.a, "rev-parse", "HEAD")
        self.sync(self.a)
        self.assertEqual(self.git(self.a, "rev-parse", "HEAD"), before)

    def test_passing_lesson_retries_sync_even_without_new_edits(self):
        lesson = {"id": "8.5", "key": "08_05"}
        with self.context(self.a), patch.dict("os.environ", {}, clear=True), patch.object(course, "sync_repository") as sync:
            self.assertTrue(course.git_sync_lesson(lesson, course.workspace_path(lesson)))
            sync.assert_called_once()

    def test_check_reports_a_sync_failure_instead_of_silent_success(self):
        lesson = {"id": "8.5", "key": "08_05"}
        with self.context(self.a), patch.dict("os.environ", {}, clear=True), patch.object(course, "compile_and_run", return_value=(True, "All behavioral tests passed.")), patch.object(course, "sync_repository", side_effect=SystemExit("Network unavailable")):
            self.assertFalse(course.check_lesson(lesson, course.workspace_path(lesson)))
            progress = json.loads((self.a / ".course/progress.json").read_text())
            self.assertIn("08_05", progress["completed"])
