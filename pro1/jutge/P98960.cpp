#include <iostream>

int main() {
    // Defines an offset between upper and lowercase
    constexpr char offset = 'a' - 'A';

    // Get input
    char c;
    std::cin >> c;

    if (c <= 'Z') {  // If true, c must be uppercase, else, lowercase (assuming
                     // c is in alphabet range)
        c += offset;
    } else {
        c -= offset;
    }

    std::cout << c << std::endl;
}
