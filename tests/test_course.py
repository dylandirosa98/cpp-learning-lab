import sys
import tempfile
import unittest
from pathlib import Path


ROOT = Path(__file__).resolve().parents[1]
sys.path.insert(0, str(ROOT))

from tools.course import SOLUTIONS, STARTERS, load_lessons, normalize_lesson_id, normalized_cpp_code, source_rule_failures, strip_cpp_comments  # noqa: E402


class CourseTest(unittest.TestCase):
    def test_available_chapters_are_complete(self):
        lessons = load_lessons()

        self.assertEqual(
            [lesson["id"] for lesson in lessons],
            [
                "2.1", "2.2", "2.3", "2.4", "2.5", "2.6", "2.7", "2.8", "2.9", "2.10", "2.11", "2.12", "2.13", "2.x",
                "3.1", "3.2", "3.3", "3.4", "3.5", "3.6", "3.7", "3.8", "3.9", "3.10", "3.x",
                "4.1", "4.2", "4.3", "4.4", "4.5", "4.6", "4.7", "4.8", "4.9", "4.10", "4.11", "4.12", "4.x",
                "5.1", "5.2", "5.3", "5.4", "5.5", "5.6", "5.7", "5.8", "5.9", "5.x",
                "6.1", "6.2", "6.3", "6.4", "6.5", "6.6", "6.7", "6.8", "6.x",
            ],
        )

    def test_every_lesson_has_valid_content_and_files(self):
        required_fields = {
            "order",
            "id",
            "title",
            "url",
            "estimatedMinutes",
            "recap",
            "objectives",
            "warnings",
            "challenge",
            "expectedOutput",
            "hints",
            "sources",
            "sourceChecks",
        }

        for lesson in load_lessons():
            with self.subTest(lesson=lesson["id"]):
                self.assertTrue(required_fields.issubset(lesson))
                self.assertTrue(lesson["url"].startswith("https://www.learncpp.com/cpp-tutorial/"))
                self.assertEqual(len(lesson["hints"]), 3)
                self.assertGreaterEqual(len(lesson["recap"]), 2)
                self.assertTrue(lesson["expectedOutput"])

                for directory in (STARTERS / lesson["key"], SOLUTIONS / lesson["key"]):
                    self.assertTrue(directory.is_dir())
                    for source in lesson["sources"]:
                        self.assertTrue((directory / source).is_file(), f"Missing {directory / source}")
                    for rule in lesson["sourceChecks"]:
                        self.assertTrue((directory / rule["file"]).is_file(), f"Missing {directory / rule['file']}")

                self.assertTrue((STARTERS / lesson["key"] / "CMakeLists.txt").is_file())
                self.assertEqual(source_rule_failures(lesson, SOLUTIONS / lesson["key"]), [])

    def test_lesson_id_normalization(self):
        self.assertEqual(normalize_lesson_id("2.1"), "02_01")
        self.assertEqual(normalize_lesson_id("02_13"), "02_13")
        self.assertEqual(normalize_lesson_id("2.x"), "02_x")
        self.assertEqual(normalize_lesson_id("3.x"), "03_x")
        self.assertEqual(normalize_lesson_id("4.1"), "04_01")
        self.assertEqual(normalize_lesson_id("4.x"), "04_x")
        self.assertEqual(normalize_lesson_id("5.1"), "05_01")
        self.assertEqual(normalize_lesson_id("05_09"), "05_09")
        self.assertEqual(normalize_lesson_id("5.x"), "05_x")
        self.assertEqual(normalize_lesson_id("05x"), "05_x")
        self.assertEqual(normalize_lesson_id("6.1"), "06_01")
        self.assertEqual(normalize_lesson_id("06_08"), "06_08")
        self.assertEqual(normalize_lesson_id("6.x"), "06_x")
        self.assertEqual(normalize_lesson_id("06x"), "06_x")

    def test_every_starter_file_has_actionable_instructions(self):
        for source in list(STARTERS.glob("**/*.cpp")) + list(STARTERS.glob("**/*.h")):
            with self.subTest(source=source.relative_to(ROOT)):
                content = source.read_text()
                self.assertTrue(content.startswith("/*"))
                self.assertIn("LearnCpp:", content)
                self.assertIn("expected", content.lower())
                self.assertIn("./course check", content)

    def test_source_checks_ignore_instructional_comments(self):
        lesson = {
            "sourceChecks": [
                {
                    "file": "main.cpp",
                    "contains": ["requiredFunction();"],
                    "notContains": ["forbiddenFunction();"],
                }
            ]
        }
        with tempfile.TemporaryDirectory() as directory:
            source = Path(directory) / "main.cpp"
            source.write_text("/* requiredFunction(); */\n// forbiddenFunction();\nint main() {}\n")

            failures = source_rule_failures(lesson, Path(directory))

        self.assertEqual(failures, ["main.cpp must contain: requiredFunction();"])

    def test_source_checks_ignore_brace_spacing(self):
        lesson = {
            "sourceChecks": [
                {
                    "file": "main.cpp",
                    "contains": ["const int cartonsPerShelf{ 6 };"],
                    "notContains": [],
                }
            ]
        }
        with tempfile.TemporaryDirectory() as directory:
            source = Path(directory) / "main.cpp"
            source.write_text("const int cartonsPerShelf{6};\n")

            failures = source_rule_failures(lesson, Path(directory))

        self.assertEqual(failures, [])

    def test_comment_stripping_preserves_code(self):
        source = '/* instructions */\n// TODO: write output\nstd::cout << "ready\\n";\n'

        self.assertEqual(strip_cpp_comments(source).strip(), 'std::cout << "ready\\n";')
        self.assertEqual(normalized_cpp_code(source), 'std::cout << "ready\\n";')


if __name__ == "__main__":
    unittest.main()
