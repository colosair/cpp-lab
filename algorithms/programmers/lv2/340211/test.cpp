// Local test for Programmers 340211 ([PCCP 기출문제] 3번 / 충돌위험 찾기).
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
        check(1, solution({{3, 2}, {6, 4}, {4, 7}, {1, 4}}, {{4, 2}, {1, 3}, {2, 4}}), 1);
        check(2, solution({{3, 2}, {6, 4}, {4, 7}, {1, 4}}, {{4, 2}, {1, 3}, {4, 2}, {4, 3}}), 9);
        check(3,
              solution({{2, 2}, {2, 3}, {2, 7}, {6, 6}, {5, 2}},
                       {{2, 3, 4, 5}, {1, 3, 4, 5}}),
              0);
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
