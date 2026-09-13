# C++ Learning Lab

A CLion-first interactive companion to [LearnCpp](https://www.learncpp.com/), currently covering Chapters 2 through 6. The lab links to each original lesson, provides a short original recap, and follows it with a focused coding challenge, progressive hints, automated checks, and a reference solution. Completed workspace code and course progress are tracked in Git so the same course can be continued across machines.

LearnCpp owns its lesson text and examples. This project does not mirror them.

## Requirements

- Python 3.10 or newer
- GCC with C++20 support
- CLion is optional but recommended

The command-line checker invokes `g++` directly, so a system CMake installation is not required. CLion can use its bundled CMake.

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
./course setup
```

GitHub authentication is required to push. On a new machine, run `gh auth login` once (or configure an SSH credential) before submitting lessons.

Run `./course sync` before starting work on another machine. It pulls remote changes with rebase and creates any missing lesson workspaces. When `./course check 6.1` passes, the checker commits that lesson's workspace and progress and pushes the current branch automatically. Failed lessons are never committed. Set `COURSE_NO_SYNC=1` for a one-off local check without committing or pushing.

The same commands accept Chapter 3 through Chapter 6 lesson IDs, for example:

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
```

Your editable files live under `workspaces/`. Every C++ starter file begins with comments explaining that file's tasks, function responsibilities, expected output, LearnCpp link, and checker command. The original starters and reference solutions remain separate.

## Learning Loop

1. Run `./course lesson 2.1`.
2. Open the linked LearnCpp lesson and read it in full.
3. Edit the matching folder under `workspaces/` in CLion.
4. Predict the output before running the checker.
5. Run `./course check 2.1`.
6. Use hints only after a real attempt.
7. Explain the key concept aloud before moving on.

The chapter capstone is lesson `2.x`.

Chapter 3 uses CLion's debugger. Keep the CMake profile set to `Debug` so stepping, breakpoints, watches, and call stacks retain useful symbols. Follow each starter's breakpoint and watch instructions before changing its code. Its capstone is lesson `3.x`.

Chapter 4 focuses on fundamental types and conversions. Its `4.x` capstone is a deterministic multi-file calculator and falling-ball lab: preserve calculation/presentation separation, handle invalid calculator paths before arithmetic, and clamp height at ground level.

Chapter 5 focuses on constants and strings. Its lessons distinguish named constants from magic values, use `std::string` when text needs ownership, and use `std::string_view` for inexpensive read-only access without outliving the viewed text. The `5.x` capstone composes owned full names, calculates an age difference, selects the older person through safe views, and exercises a deterministic first-person-wins tie rule across separate logic, report, and coordinator modules.

Chapter 6 focuses on operators and expressions. Its exercises cover precedence and associativity, arithmetic and integer division, remainder and `std::pow`, sequenced increment/decrement side effects, the comma and conditional operators, robust floating-point comparisons, and short-circuit logical policies. The `6.x` capstone calculates a deterministic apple inventory and pluralized restock report while preserving separate inventory, reporting, and coordinator modules.

## Course Verification

```bash
python3 -m unittest discover -s tests
./course verify-solutions
```
