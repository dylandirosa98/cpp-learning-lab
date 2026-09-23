/*
Lesson 3.3 - A strategy for debugging
LearnCpp: https://www.learncpp.com/cpp-tutorial/a-strategy-for-debugging/
What is practiced:
- Reproduce a deterministic failure and use midpoint checkpoints to home in on
  the first pipeline stage with correct inputs but an incorrect output.
Explicit expected behavior:
- Raw 18 plus offset 2 normalizes to 20.
- Scaling 20 by factor 3 produces 60; combining 12 produces 72.
- Holding back 7 from 72 leaves available capacity 65.
Debugging procedure:
1. Run the untouched program with its fixed inputs and record all output.
2. Break in main after combineZones() and compare combined with 72.
3. Move earlier if combined is wrong or later if combined is correct.
4. Inspect normalized, then scaled, until the first divergence is bounded.
5. Step into the isolated stage and compare its parameters and return value.
6. Repair only that stage and rerun the complete reproduction.
File and function responsibilities:
- This header publishes the four pipeline operations and no definitions.
- sensor_pipeline.cpp owns all four calculations and performs no output.
- main.cpp supplies fixed inputs, stores stage results, and prints the report.
Constraints:
- Preserve this guarded interface and all four function signatures.
- Do not include an implementation file or hard-code displayed results.
- Use explicit std:: qualification and no using namespace std.
Exact expected output:
Normalized reading: 20
Combined load: 72
Available capacity: 65
Completion checklist:
- The untouched failure was reproduced before any edit.
- Checkpoints narrowed the search instead of relying on domain guesses.
- The isolated stage has correct parameters and corrected behavior.
- The final build is warning-free and exact output is restored.
Run from project root: ./course check 3.3
*/
#ifndef CPP_LEARNING_LAB_SENSOR_PIPELINE_H
#define CPP_LEARNING_LAB_SENSOR_PIPELINE_H

int normalizeReading(int rawReading, int offset);
int scaleReading(int reading, int factor);
int combineZones(int primary, int secondary);
int reserveCapacity(int combined, int holdback);

#endif
