# C++ Learning Lab

A file-based interactive companion to [LearnCpp](https://www.learncpp.com/), covering Chapters 2 through 13 and optional Chapter O. Use Neovim or CLion. The lab links to each original lesson, provides original explanations, and follows them with focused coding challenges, progressive hints, automated checks, and reference solutions. Workspace code and course progress are tracked in Git so the same course can be continued across machines.

LearnCpp owns its lesson text and examples. This project does not mirror them.

## Requirements

- Python 3.10 or newer
- GCC with C++20 support
- CLion is optional but recommended

The command-line checker invokes `g++` directly, so a system CMake installation is not required. CLion can use its bundled CMake.

On NixOS, enter the included development shell instead of installing the tools globally:

```bash
nix develop
```

This provides Python, GCC, CMake, Git, and GitHub CLI for the current terminal.

## Start

```bash
./course setup
./course refresh-instructions
./course
```

Open the project in CLion with:

```bash
./course open
```

Useful commands:

```bash
./course list
./course lesson 2.1
./course read 2.1
./course check 2.1
./course hint 2.1
./course solution 2.1
./course next
./course progress
./course reset 2.1
./course verify-solutions
./course sync
```

## Work Across Machines

Clone the repository rather than downloading a ZIP. Cloning configures the GitHub remote that automatic syncing needs:

```bash
git clone https://github.com/dylandirosa98/cpp-learning-lab.git
cd cpp-learning-lab
nix develop # NixOS only
./course setup
```

GitHub authentication is required to push. On a new machine, run `gh auth login` once (or configure an SSH credential) before submitting lessons.

Run **`./course sync` before and after working on either machine**. It saves all
non-ignored course files in a local commit (including unfinished exercises, lesson
definitions, tests, and scratch code), fetches and merges the matching branch from
GitHub, prepares missing workspaces, and pushes. It retries pending pushes even
when there are no new edits. Ignored build outputs, editor settings, and credentials
stay local. Keep secrets outside the repository; `.gitignore` is a convenience,
not a secret scanner. Save editor buffers before syncing.

Passing `./course check 6.1` also runs this full synchronization automatically.
Failed lessons are not marked complete, but their work can still be backed up with
`./course sync`. Set `COURSE_NO_SYNC=1` for a local check without commits or network
operations. Explicit `./course sync` always syncs, regardless of that variable.

Both machines should use the same branch (`main` by default). Offline sync keeps
your local snapshot and reports the network failure; rerun it when connected.
Completion records are combined automatically. Conflicting edits to the same code
are **never overwritten automatically**: resolve the listed conflicts, `git add`
the resolved files, `git commit`, then rerun `./course sync`. A check with a sync
failure exits unsuccessfully while explaining that the lesson itself passed.

For an existing laptop clone using the older checker, first run `git pull --ff-only`
once to get this update, then use `./course sync`. If that initial pull reports
local edits or diverged history, preserve those changes and resolve them rather
than resetting or force-pushing. Run `nix develop` first on NixOS, or install the
requirements listed above. No machine-specific absolute paths are required.

The same commands accept Chapter 3 through Chapter 13 and Chapter O lesson IDs, for example:

```bash
./course check 3.1
./course hint 3.6
./course reset 3.x
./course lesson 4.1
./course check 4.x
./course lesson 5.1
./course check 5.x
./course lesson 6.1
./course check 6.7
./course reset 6.x
./course lesson 7.1
./course check 7.14
./course reset 7.x
./course lesson 8.1
./course check 8.15
./course reset 8.x
./course lesson O.1
./course check O.3
./course reset O.4
```

Your editable files are grouped by chapter under `workspaces/`, such as `workspaces/06/06_07` and `workspaces/O/o_01`. Every C++ starter file begins with comments explaining that file's tasks, function responsibilities, expected output, LearnCpp link, and checker command. The original starters and reference solutions remain separate.

## Learning Loop

### Chapter 9 browser experience

From the repository root:

```bash
./course web
```

Open **http://127.0.0.1:8765** in your browser. Only Chapter 9 appears in this
experimental split-pane UI. The live LearnCpp page stays on the left; focused
activities appear on the right. Nothing from the live page is mirrored in the repo.

The chapter has **29 curated steps**, not a fixed quiz/challenge pair per page:
short explanations, code predictions, knowledge checks, choose-a-repair debugging
drills, and the existing coding assignments. For example, 9.5 has seven steps:
extraction → failed-stream prediction → recovery → repair drill → EOF → final-token
prediction → combined reader challenge. Shorter 9.4 has three steps. Each step
states one learning objective, and explanation steps do not force a quiz.

Repair drills update only their displayed example, not your C++ files. Practice
answers stay in browser memory; they do not record lesson completion. Existing
quiz/challenge links and all seven main.cpp assignments remain accessible.

Use the browser editor with **Vim keybindings** for file challenges, or keep
editing the same files externally. **Alt+R** (in Normal or Insert mode) and the
**Run** button save the current buffer before testing. **:w** and **Save** also
write it to disk. This is not Neovim and does not load your plugins or configuration.
Unsaved drafts survive step navigation in the current page; refreshing or closing
the page warns before discarding them. If the file changes externally, saving
refuses to overwrite it: copy your draft before reloading and reconciling changes.
**Submit from the terminal as usual** with
`./course check 9.1`. Browser tests never mark lessons complete, commit, or push.
The progress bar reflects submitted topics only, not individual practice steps.
Chapter 9's browser presentation and normal file workflow share the same lessons
and progress, rather than creating duplicate exercises. Chapters 10–13 are unchanged.

The browser editor uses locally bundled, MIT-licensed CodeMirror with its Vim
keymap; no npm installation, CDN, Neovim, or Python msgpack is needed. The server binds only to
127.0.0.1; it is a personal development tool, not a hosted service or sandbox for
untrusted C++ code. Keep the terminal running; **Ctrl+C** stops it. If the port is
busy, use `./course web --port 8766`. Use the exact URL printed in the terminal.

The design draws on Boot.dev's public roadmap, CLI workflow, and Prepcards
review interaction, without copying their course UI or assets.
See [design references](tools/web/SOURCES.md).

### File-based challenges: Chapters 9–13

There are 61 new lessons, including chapter capstones and 13.y. Each has a
`lesson.md`, optional `hints.md`, and a `main.cpp` containing the challenge API
and **visible executable tests**. Implement the TODOs, not printed answers.
Chapter 9 is the guided course-format experiment: original explanations, worked
examples, prediction tasks, missions, and reflection questions, all in files.
No browser editor or external course subscription is needed.

```bash
nvim workspaces/09/09_01/lesson.md workspaces/09/09_01/main.cpp
```

With `main.cpp` open, your configured **Alt+R** CMake shortcut builds and runs
the visible tests. It reports the first failure or `All ... tests passed`.
This does **not** submit or change progress. Each lesson has its own C++20 CMake
target, including the multi-file 11.10 challenge. For terminal-only use:

```bash
cmake -S workspaces/09/09_01 -B .course/build/visible-09_01
cmake --build .course/build/visible-09_01
./.course/build/visible-09_01/lesson_09_01
./course check 9.1
```

The last command is the normal submission: independent tests run, and only a
pass records completion and syncs. Editing visible tests cannot change the
checker's copy. Some type/API challenges initially fail compilation until you
add the required declaration; that is intentional. Assertion subprocess tests
in 9.6 require Linux or macOS. The CMake targets keep assertions enabled.
Existing completed work and progress are unchanged.

Chapter indexes: [9](workspaces/09/README.md), [10](workspaces/10/README.md),
[11](workspaces/11/README.md), [12](workspaces/12/README.md), [13](workspaces/13/README.md).

The material is original personal-study content, not a copy of Boot.dev or
LearnCpp. Chapters 10–13 follow the Chapter 8 function-challenge model with
behavioral checks, not required source tokens or arbitrary output formatting.
Lesson 13.5 tests stream formatting because stream operators are its actual API.

1. Run `./course lesson 2.1`.
2. Open the linked LearnCpp lesson and read it in full.
3. Edit the matching chapter and lesson folder under `workspaces/` in CLion.
4. Predict the output before running the checker.
5. Run `./course check 2.1`.
6. Use hints only after a real attempt.
7. Explain the key concept aloud before moving on.

The chapter capstone is lesson `2.x`.

Chapter 3 uses CLion's debugger. Keep the CMake profile set to `Debug` so stepping, breakpoints, watches, and call stacks retain useful symbols. Follow each starter's breakpoint and watch instructions before changing its code. Its capstone is lesson `3.x`.

Chapter 4 focuses on fundamental types and conversions. Its `4.x` capstone is a deterministic multi-file calculator and falling-ball lab: preserve calculation/presentation separation, handle invalid calculator paths before arithmetic, and clamp height at ground level.

Chapter 5 focuses on constants and strings. Its lessons distinguish named constants from magic values, use `std::string` when text needs ownership, and use `std::string_view` for inexpensive read-only access without outliving the viewed text. The `5.x` capstone composes owned full names, calculates an age difference, selects the older person through safe views, and exercises a deterministic first-person-wins tie rule across separate logic, report, and coordinator modules.

Chapter 6 focuses on operators and expressions. Its exercises cover precedence and associativity, arithmetic and integer division, remainder and `std::pow`, sequenced increment/decrement side effects, the comma and conditional operators, robust floating-point comparisons, and short-circuit logical policies. The `6.x` capstone calculates a deterministic apple inventory and pluralized restock report while preserving separate inventory, reporting, and coordinator modules.

Chapter 7 focuses on scope, duration, and linkage. Its exercises cover blocks, namespaces, local and global variables, shadowing, internal and external linkage, inline variables, shared constants, static locals, using declarations, and unnamed and inline namespaces. The `7.x` capstone builds a deterministic multi-file field survey while keeping configuration, survey logic, reporting, and coordination separate.

Chapter 8 focuses on control flow. Its exercises cover if statements and blocks, common if statement problems, constexpr if statements, switch statements with fallthrough and scoping, goto statements, while, do while, and for loops, break and continue, early exits with halts, and reproducible pseudo-random draws through fixed-seed engines, distributions, and a shared Random header. The revised `8.x` capstone combines these ideas in a launch-readiness scanning function.

### Chapter 8 function challenges (8.5–8.x)

These lessons provide function signatures and plain-English contracts, not prewritten
branches or loops. Write the implementation yourself. The comments include concrete
input/result examples and edge-case rules; `main` is only a supplied demo. There are
no required console labels or exact source-token checks. Practice the construct named
in the lesson, but any implementation that passes the behavioral tests is accepted.

`./course check 8.5` compiles a trusted test driver from `tests/lesson_cases/` against
your workspace code and calls your function with multiple inputs. Tests live outside
the editable workspace and failures report the expected and actual result. Compiler
warnings are shown but do not reject these function challenges. Earlier completed
lessons retain their original checker behavior.

| Lesson | Your task |
| --- | --- |
| 8.5 | Map status codes to messages with a switch |
| 8.6 | Calculate cumulative rank bonuses using switch fallthrough |
| 8.7 | Simulate retries with a backward goto |
| 8.8 | Sum an inclusive range with a while loop |
| 8.9 | Count decimal digits, including zero, with a do while loop |
| 8.10 | Count multiples in a range with a for loop |
| 8.11 | Skip checkpoints and stop before a sentinel |
| 8.12 | Terminate a child process with the correct exit code |
| 8.13 | Reproduce an indexed raw seeded engine draw |
| 8.14 | Sum seeded four-sided die rolls |
| 8.15 | Share and reset one random sequence across translation units |
| 8.x | Scan launch statuses, skip ignored codes, stop on scrub, and return tallies/verdict |

The revised `8.x` capstone uses one function and a supplied result struct rather than
requiring presentation modules. Lessons 8.1–8.4 and their completed work are unchanged.

Optional Chapter O focuses on bit manipulation. Its four exercises use `std::bitset`, apply all six bitwise operators, manage named flags with masks, and convert decimal integers to binary without relying on bitwise operators or `std::bitset`.

## Course Verification

```bash
python3 -m unittest discover -s tests
./course verify-solutions
```
