// Local test for Programmers 120802.
// Build from this directory:
//   Windows: g++ -std=c++17 -Wall -Wextra -Wpedantic test.cpp -o test.exe
//   macOS:   clang++ -std=c++17 -Wall -Wextra -Wpedantic test.cpp -o test.out

#include <iostream>

#include "solution.cpp"

namespace {

int failures = 0;

void check(int num1, int num2, int expected) {
    const int actual = solution(num1, num2);
    if (actual != expected) {
        std::cerr << "FAIL: solution(" << num1 << ", " << num2 << ") = " << actual
                  << ", expected " << expected << '\n';
        ++failures;
    }
}

} // namespace

int main() {
    check(10, 20, 30);
    check(-50000, 50000, 0);
    check(-50000, -50000, -100000);
    check(0, 0, 0);

    if (failures != 0) {
        return 1;
    }
    std::cout << "All tests passed.\n";
    return 0;
}
