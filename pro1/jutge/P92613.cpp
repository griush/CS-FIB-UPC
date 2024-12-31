#include <iostream>

int main() {
    double x;
    std::cin >> x;

    int floor = (int)x;
    int ceil = (x - (float)floor) == 0 ? floor : floor + 1;
    int round = (x - floor) >= 0.5f ? ceil : floor;

    std::cout << floor << " " << ceil << " " << round << std::endl;

    return 0;
}
