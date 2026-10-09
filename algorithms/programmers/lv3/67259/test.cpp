// Local test for Programmers 67259 (경주로 건설).
// Expected values are the official examples from the problem page.
// Build from this directory:
//   Windows: g++ -std=c++17 -Wall -Wextra -Wpedantic test.cpp -o test.exe
//   macOS:   clang++ -std=c++17 -Wall -Wextra -Wpedantic test.cpp -o test.out
// Exit code: 0 = all passed, 1 = failed, 2 = solution() not implemented yet.

#include <iostream>
#include <stdexcept>
#include <string>

#include "solution.cpp"

namespace {

using Answer = int;

int failures = 0;

std::string show(const Answer& value) { return std::to_string(value); }

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
        check(1, solution({{0, 0, 0}, {0, 0, 0}, {0, 0, 0}}), 900);
        check(2,
              solution({{0, 0, 0, 0, 0, 0, 0, 1},
                        {0, 0, 0, 0, 0, 0, 0, 0},
                        {0, 0, 0, 0, 0, 1, 0, 0},
                        {0, 0, 0, 0, 1, 0, 0, 0},
                        {0, 0, 0, 1, 0, 0, 0, 1},
                        {0, 0, 1, 0, 0, 0, 1, 0},
                        {0, 1, 0, 0, 0, 1, 0, 0},
                        {1, 0, 0, 0, 0, 0, 0, 0}}),
              3800);
        check(3, solution({{0, 0, 1, 0}, {0, 0, 0, 0}, {0, 1, 0, 1}, {1, 0, 0, 0}}), 2100);
        check(4,
              solution({{0, 0, 0, 0, 0, 0},
                        {0, 1, 1, 1, 1, 0},
                        {0, 0, 1, 0, 0, 0},
                        {1, 0, 0, 1, 0, 1},
                        {0, 1, 0, 0, 0, 1},
                        {0, 0, 0, 0, 0, 0}}),
              3200);
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
