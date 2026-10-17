# C++ Learning Lab

A CLion-first interactive companion to [LearnCpp](https://www.learncpp.com/), currently covering Chapters 2 through 8 and optional Chapter O. The lab links to each original lesson, provides a short original recap, and follows it with a focused coding challenge, progressive hints, automated checks, and a reference solution. Workspace code and course progress are tracked in Git so the same course can be continued across machines.

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

Run `./course sync` before starting work on another machine. It pulls remote changes with rebase and creates any missing lesson workspaces. When `./course check 6.1` passes, the checker commits that lesson's workspace and progress and pushes the current branch automatically. Failed lessons are never committed. Set `COURSE_NO_SYNC=1` for a one-off local check without committing or pushing.

The same commands accept Chapter 3 through Chapter 8 and Chapter O lesson IDs, for example:

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
