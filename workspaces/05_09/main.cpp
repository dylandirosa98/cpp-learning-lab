/*
Lesson 5.9 - std::string_view (part 2)
LearnCpp: https://www.learncpp.com/cpp-tutorial/stdstring_view-part-2/
Practice:
- Keep a view's owner alive and unchanged for as long as the view is used.
- Narrow a view without copying or modifying the underlying string.
Task:
1. Keep the named std::string owner in scope and unchanged while views use it.
2. Notice that source observes owner rather than owning another text buffer.
3. Remove exactly one-character prefix and suffix inside trimBrackets.
4. Return the narrowed parameter view and retain both report lines.
Function responsibility:
- trimBrackets narrows and returns its non-owning parameter view.
- main owns the source characters and uses all views while that owner lives.
Constraints:
- Use remove_prefix(1) and remove_suffix(1); do not allocate a sliced string.
- Never return a view into a local or temporary std::string.
- A literal-backed view is safe because literals have static lifetime; this
  exercise deliberately practices a view into a caller-owned std::string.
Exact expected output:
Source: [stable slice]
Slice: stable slice
Completion checklist:
- A named std::string outlives source and slice.
- Slicing changes only the view boundaries, not the owner.
- No dangling view exists and the C++20 build is warning-free.
Run from project root: ./course check 5.9
*/
#include <iostream>
#include <string>
#include <string_view>

std::string_view trimBrackets(std::string_view text) {
    text.remove_prefix(1);
    text.remove_suffix(1);
    return text;
}

int main() {
    std::string owner{"[stable slice]"};
    std::string_view source{owner};
    std::string_view slice{trimBrackets(source)};

    std::cout << "Source: " << source << '\n';
    std::cout << "Slice: " << slice << '\n';
    return 0;
}
