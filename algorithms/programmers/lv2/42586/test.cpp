// Local test for Programmers 42586 (기능개발).
// Expected values are the official examples from the problem page.
// Build from this directory:
//   Windows: g++ -std=c++17 -Wall -Wextra -Wpedantic test.cpp -o test.exe
//   macOS:   clang++ -std=c++17 -Wall -Wextra -Wpedantic test.cpp -o test.out
// Exit code: 0 = all passed, 1 = failed, 2 = solution() not implemented yet.

#include <iostream>
#include <stdexcept>
#include <string>
#include <vector>

#include "solution.cpp"

namespace {

using Answer = std::vector<int>;

int failures = 0;

std::string show(const Answer& value) {
    std::string text = "[";
    for (std::size_t i = 0; i < value.size(); ++i) {
        if (i != 0) {
            text += ", ";
        }
        text += std::to_string(value[i]);
    }
    return text + "]";
}

void check(int example, const Answer& actual, const Answer& expected) {
    if (actual != expected) {
        std::cerr << "FAIL: example " << example << ": got " << show(actual) << ", expected "
                  << show(expected) << '\n';
        ++failures;
    }
}

} // namespace

int main() {
    try {
        check(1, solution({93, 30, 55}, {1, 30, 5}), {2, 1});
        check(2, solution({95, 90, 99, 99, 80, 99}, {1, 1, 1, 1, 1, 1}), {1, 3, 2});
    } catch (const std::logic_error& error) {
        if (std::string(error.what()) == "Not implemented") {
            std::cout << "NOT IMPLEMENTED: write solution() in solution.cpp\n";
            return 2;
        }
        std::cerr << "FAIL: exception: " << error.what() << '\n';
        return 1;
    } catch (const std::exception& error) {
        std::cerr << "FAIL: exception: " << error.what() << '\n';
        return 1;
    }

    if (failures != 0) {
        return 1;
    }
    std::cout << "All tests passed.\n";
    return 0;
}
