// Local test for Programmers 42578 (의상).
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
        check(1,
              solution({{"yellow_hat", "headgear"},
                        {"blue_sunglasses", "eyewear"},
                        {"green_turban", "headgear"}}),
              5);
        check(2,
              solution({{"crow_mask", "face"},
                        {"blue_sunglasses", "face"},
                        {"smoky_makeup", "face"}}),
              3);
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
