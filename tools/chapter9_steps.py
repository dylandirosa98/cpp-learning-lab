"""Original, bite-sized study steps for Chapter 9."""

# prompt, options, correct index, explanation
QUIZZES = {
    '9.1': [
        ('What does successful compilation establish?', ['The program meets every requirement.', 'The program is well formed, not necessarily correct.', 'Every branch has been tested.', 'All edge cases are handled.'], 1, 'The compiler checks language syntax and type rules. Behavioral requirements need tests and reasoning.'),
        ('Which pair best exposes the leap-year century exception?', ['2023 and 2024', '1900 and 2000', '2024 and 2028', '1 and 4'], 1, '1900 is not a leap year, but 2000 is. Both are centuries, so this pair tests the 400-year exception.'),
    ],
    '9.2': [
        ('Every branch ran in a passing test suite. What can you conclude?', ['No boundary mistakes remain.', 'Every possible input has been checked.', 'Each branch outcome was exercised, but bugs may remain.', 'Statement coverage is still incomplete.'], 2, 'Coverage measures execution paths, not whether the thresholds and results are correct.'),
        ('A fee changes after weight 5. Which inputs target that boundary?', ['1, 10, 100', '4, 5, 6', '5, 15, 25', '0, 50, 100'], 1, 'Values just below, at, and above a threshold catch off-by-one comparisons.'),
    ],
    '9.3': [
        ('What value does double average{5 / 2}; initialize?', ['2.0', '2.5', '2.25', 'It does not compile.'], 0, 'Both operands are int. Integer division happens before conversion to double.'),
        ('Which input is valid for the averageScore contract?', ['total=0, count=3', 'total=3, count=0', 'total=-1, count=3', 'total=5, count=-2'], 0, 'A zero total is valid; a nonpositive count or negative total is not.'),
    ],
    '9.4': [
        ('When must a zero divisor be rejected?', ['After computing the remainder.', 'Before evaluating the remainder operation.', 'Only when the numerator is also zero.', 'Inside the caller after % runs.'], 1, 'Remainder by zero is undefined behavior. Validate before performing the operation.'),
        ('When is -1 an unambiguous error result?', ['Whenever the return type is int.', 'When no successful result can be -1.', 'When the caller prints an error.', 'Whenever divisor is positive.'], 1, 'A sentinel must not collide with any valid value in the successful result domain.'),
    ],
    '9.5': [
        ('Extraction failed on a bad text line, without EOF. How should the reader recover?', ['Retry the same extraction immediately.', 'ignore(), then clear().', 'clear(), then ignore the rest of the line.', 'Return 0 immediately.'], 2, 'Clear the failure state first so discarding the bad line can work.'),
        ('The final input is a valid integer with no newline. What should happen?', ['Accept it if extraction succeeded.', 'Always reject it because eofbit may be set.', 'Retry forever.', 'Clear the value to 0.'], 0, 'Successful extraction can reach EOF. Handle success before treating EOF as an unsuccessful read.'),
    ],
    '9.6': [
        ('Which check is evaluated during compilation?', ['assert(runtimeValue > 0)', 'static_assert(2 + 2 == 4)', 'An if statement inside main', 'std::abort()'], 1, 'static_assert requires a constant expression and is checked at compile time.'),
        ('Why is assert(++count > 0) a poor place for a necessary increment?', ['An assertion always evaluates twice.', 'Assertions may be removed when NDEBUG is defined.', 'An assertion cannot contain an integer expression.', 'It causes a syntax error in C++20.'], 1, 'Required work must remain active when assertions are disabled in release builds.'),
    ],
    '9.x': [
        ('Where should invalid-text recovery belong in the order workflow?', ['The price calculation.', 'The input reader.', 'Every caller must implement its own loop.', 'Inside main() only.'], 1, 'Input mechanics are separate from pricing rules, making both parts easier to test.'),
        ('Input is product 2, quantity 0, then quantity 3. What should the workflow do?', ['Reread the product after 0.', 'Accept quantity 0.', 'Keep product 2, retry quantity, then return 24.', 'Return -1 immediately.'], 2, 'The product remains valid while quantity is retried. Product 2 costs 8; three units cost 24.'),
    ],
}


def question(prompt, options, answer, explanation):
    return dict(question=prompt, options=options, answer=answer, explanation=explanation)


def existing_question(lesson_id, index):
    return question(*QUIZZES[lesson_id][index])


def step(suffix, kind, title, objective, explanation, **extra):
    return dict(suffix=suffix, kind=kind, title=title, objective=objective,
                explanation=explanation, **extra)


# Deliberately authored per topic, not a template that adds the same activities
# to every LearnCpp page. Small choice-based repair drills do not edit files.
TOPICS = {
    '9.1': [
        step('idea', 'read', 'Compilation is not correctness',
             'Distinguish a well-formed program from a program that meets its requirements.',
             'Compilation is one check, not a correctness certificate. A test arranges an input, calls the behavior, and compares the result with an expectation chosen from the requirement.\n\nStart with one ordinary case, then ask what different category could break the rule. Read the live lesson on the left for the broader discussion.'),
        step('quiz', 'quiz', 'What did the compiler prove?',
             'Identify what a successful build does and does not establish.',
             'Choose the statement that separates language validity from behavioral correctness.',
             questions=[existing_question('9.1', 0)]),
        step('centuries', 'predict', 'Predict the century cases',
             'Choose inputs that distinguish two plausible implementations.',
             'The rule is: a positive year is a leap year if divisible by 400, or divisible by 4 but not by 100. Predict the results before implementing it.',
             code='// Candidate implementation: what category does it miss?\nbool isLeapYear(int year) { return year > 0 && year % 4 == 0; }',
             questions=[existing_question('9.1', 1)]),
        step('code', 'code', 'Implement and test the calendar rule',
             'Turn the leap-year requirement into general behavior.',
             'Now use the existing main.cpp challenge. Predict its tests first, implement the function, and add a case of your own. Do not replace the visible test suite with output text.'),
    ],
    '9.2': [
        step('coverage', 'read', 'Two different coverage questions',
             'Distinguish statement coverage from branch coverage.',
             'Statement coverage asks whether each statement ran. Branch coverage asks whether each decision outcome ran. Neither proves a formula or threshold is right.\n\nFor shipping, list invalid, light, medium, and heavy weights. Then cross those categories with ordinary and express delivery.'),
        step('quiz', 'quiz', 'Coverage is evidence, not proof',
             'Recognize what branch coverage leaves uncertain.',
             'Imagine every branch was visited but a price bracket still uses the wrong endpoint.',
             questions=[existing_question('9.2', 0)]),
        step('boundary', 'predict', 'Probe both sides of the boundary',
             'Select boundary-focused tests rather than only typical values.',
             'The first price bracket includes weight 5; the next begins at 6. Which small group would expose an accidental < instead of <=?',
             questions=[existing_question('9.2', 1)]),
        step('code', 'code', 'Make shipping boundaries executable',
             'Implement brackets and their express combinations.',
             'Use the existing shippingFee challenge to check the category map against real code. Invalid orders must stay invalid when express is true.'),
    ],
    '9.3': [
        step('semantic', 'read', 'Valid code, wrong meaning',
             'Recognize a semantic error that survives compilation.',
             'A wrong Boolean condition, an off-by-one bound, and integer division can all be legal C++. Trace a small failing example through both the values and their types.\n\nChange one suspected cause at a time and rerun earlier tests after a repair.'),
        step('division', 'predict', 'Evaluate before converting',
             'Predict the result of integer division assigned to double.',
             'The destination type does not reach backward and change the operands of /. Work out the division first.',
             code='double average{5 / 2};', questions=[existing_question('9.3', 0)]),
        step('repair', 'debug', 'Repair the conversion point',
             'Move conversion before the operation that loses information.',
             'This snippet compiles but returns 2.0 for total=5, count=2. The inputs here are valid, with count > 0. Choose a replacement for the return expression; the repaired snippet will appear below.',
             code='double average(int total, int count) {\n    return static_cast<double>(total / count); // BUG\n}',
             repairTemplate='double average(int total, int count) {\n    return REPLACEMENT;\n}',
             questions=[question('Which expression repairs the fractional average?',
                                 ['static_cast<double>(total / count)', 'static_cast<double>(total) / count', 'total / count + 0.0'], 1,
                                 'Converting total before division makes the division floating-point. Converting or adding 0.0 afterward is too late: 5 / 2 has already become 2.')]),
        step('code', 'code', 'Add domain guards to the average',
             'Combine the repaired calculation with invalid-input handling.',
             'The full averageScore challenge also rejects negative totals and nonpositive counts. Keep total=0 valid. Test those guards as well as the fractional result.'),
    ],
    '9.4': [
        step('policy', 'read', 'Detect, report, recover',
             'Choose an error-reporting policy without performing an invalid operation.',
             'Detection, reporting, and recovery are different responsibilities. A calculation can return failure without printing a message or exiting the program.\n\nA sentinel is useful only if it cannot also be a successful result. For nonnegative remainders, -1 is unambiguous. Validate the divisor before evaluating %.'),
        step('quiz', 'quiz', 'Choose a safe error contract',
             'Check validation order and sentinel meaning together.',
             'These two decisions form one API contract: avoid the dangerous operation, then return a distinguishable failure result.',
             questions=[existing_question('9.4', 0), existing_question('9.4', 1)]),
        step('code', 'code', 'Guard the remainder operation',
             'Apply the error contract to the existing safeRemainder function.',
             'Keep this implementation small. A divisor check after % is too late, and a valid zero remainder must not be mistaken for an error.'),
    ],
    '9.5': [
        step('extraction', 'read', 'Successful extraction first',
             'Use the extraction result instead of guessing whether a value was read.',
             'Formatted extraction parses a value and reports success through the stream. On success, validate the value against your domain. On failure, do not use the failed result.\n\nThis course accepts a leading integer and discards the rest of its line. Thus 3 extra is intentionally accepted as 3; it is not a strict whole-line parser.',
             code='int value{};\nif (std::cin >> value) {\n    // Validate the successfully extracted integer.\n}'),
        step('failure', 'predict', 'Predict a poisoned stream',
             'Explain why retrying the same failed extraction cannot recover.',
             'Assume input starts with hello followed by a newline and then 8. The first int extraction fails, and failbit remains set.',
             code='int value{};\nstd::cin >> value; // encounters hello\nstd::cin >> value; // no recovery yet',
             questions=[question('What does the second extraction do?',
                                 ['It skips hello and reads 8.', 'It remains unsuccessful while failure state is set.', 'It automatically clears the stream.'], 1,
                                 'The stream remains failed. Retrying does not clear its state or remove the bad token.')]),
        step('recover', 'read', 'Clear state, then discard the line',
             'Separate state recovery from consuming bad input.',
             'clear() resets the failure state; it does not remove the invalid characters. ignore(max, newline) discards the rest of the attempted line.\n\nFor recoverable bad text, use both operations in that order. Otherwise the next attempt can encounter the same bad input again. EOF is different and needs its own stopping rule.'),
        step('repair', 'debug', 'Repair the recovery order',
             'Fix a reader that tries to discard input while still failed.',
             'Assume extraction failed because of text, not EOF. Choose a replacement for the two recovery statements. This repair drill is separate from the final main.cpp assignment.',
             code="// BUG: stream is still failed here\nstd::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\\n');\nstd::cin.clear();",
             repairTemplate='// After a non-EOF extraction failure:\nREPLACEMENT',
             questions=[question('Which replacement prepares the next line for extraction?',
                                 ["std::cin.clear();\nstd::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\\n');", 'std::cin.clear();', "std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\\n');"], 0,
                                 'Clear failure before ignoring characters. clear() alone leaves the bad token; ignore() alone does not recover a failed stream.')]),
        step('eof', 'read', 'EOF is a stopping condition',
             'Distinguish input exhaustion from a retryable bad line.',
             'Clearing EOF and retrying forever cannot create more input. If extraction fails and input is exhausted, stop with the documented sentinel.\n\nBut a final valid token may be extracted successfully without a newline. Check extraction success first; eofbit by itself is not a reason to throw away that valid result.'),
        step('final-token', 'predict', 'A valid token without a newline',
             'Decide whether the final successfully parsed quantity is usable.',
             'The entire input is 20, with no trailing newline. Predict what the bounded reader should return.',
             questions=[existing_question('9.5', 1)]),
        step('code', 'code', 'Build the resilient quantity reader',
             'Combine extraction, line policy, range validation, recovery, and EOF.',
             'Now implement readQuantity in the existing main.cpp. Its visible tests supply in-memory input automatically, so running it should not wait for keyboard input. Include recovery from integer overflow and acceptance of the final valid token.'),
    ],
    '9.6': [
        step('invariants', 'read', 'Assertions check programmer assumptions',
             'Distinguish an internal invariant from invalid external input.',
             'Use ordinary validation and recovery for expected bad user input. assert documents a condition that should already hold in an internal call and aborts when it fails in an assertion-enabled build.\n\nstatic_assert instead checks a constant expression during compilation. Neither tool replaces deciding who owns error recovery.'),
        step('quiz', 'quiz', 'Which check runs at compile time?',
             'Identify a compile-time assertion.',
             'Think about whether the condition is known during compilation or only when the executable runs.',
             questions=[existing_question('9.6', 0)]),
        step('release', 'predict', 'Predict a build with NDEBUG',
             'Spot required work that disappears with a disabled assertion.',
             'Assume NDEBUG is defined before including <cassert>. Trace count without treating assert as an always-on statement.',
             code='#define NDEBUG\n#include <cassert>\nint count{0};\nassert(++count > 0);',
             questions=[question('What is count after the assertion statement?', ['0', '1', 'The process must abort.'], 0,
                                 'With assertions disabled, the condition is not evaluated. The increment disappears, so count stays zero.')]),
        step('code', 'code', 'Express and check the percent invariant',
             'Use a constexpr predicate with runtime and compile-time assertions.',
             'The existing challenge checks valid inputs normally and isolates intentional assertion aborts in child processes. Keep assertions enabled when running it. Do not turn an internal assertion into a sentinel return.'),
    ],
    '9.x': [
        step('design', 'read', 'Compose three small responsibilities',
             'Separate input recovery, pricing, and workflow coordination.',
             'The order reader accepts bounded integers, the pricing function applies product rules, and the coordinator connects the two.\n\nIf the interface changes from terminal input to a form, pricing should not change. If prices change, stream recovery should not change. Test the units and the full sequence.'),
        step('quiz', 'predict', 'Trace an order through a retry',
             'Preserve a valid product while retrying only an invalid quantity.',
             'Product 2 costs 8. Follow the input sequence and decide which value needs rereading.',
             questions=[existing_question('9.x', 1)]),
        step('code', 'code', 'Capstone: a resilient order workflow',
             'Integrate the chapter skills without mixing their responsibilities.',
             'Implement the existing readBounded, orderTotal, and placeOrder contracts. Run the tests for EOF at each stage as well as invalid-first attempts. A test pass is a rehearsal; use the normal course check command to submit.'),
    ],
}


def steps_for(lessons):
    result = []
    for lesson in lessons:
        for activity in TOPICS.get(lesson['id'], []):
            activity = dict(activity)
            suffix = activity.pop('suffix')
            result.append({**activity, 'id': f"{lesson['id']}-{suffix}",
                           'lessonId': lesson['id'],
                           'shortTitle': f"{lesson['id']} {activity['title']}"})
    return result
