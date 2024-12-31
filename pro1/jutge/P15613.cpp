#include <iostream>

int main() {
    int temp;
    std::cin >> temp;

    // First output
    if (temp < 10)
        std::cout << "it's cold" << std::endl;
    else if (temp > 30)
        std::cout << "it's hot" << std::endl;
    else
        std::cout << "it's ok" << std::endl;

    // Second output
    if (temp >= 100)
        std::cout << "water would boil" << std::endl;
    else if (temp <= 0)
        std::cout << "water would freeze" << std::endl;
}
