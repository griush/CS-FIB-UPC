#include <iostream>
using namespace std;

bool is_prime(int n) {
    if (n == 0 || n == 1) return false;
    for (int i = 2; i * i <= n; i++) {
        if (n % i == 0) {
            return false;
        }
    }

    return true;
}
int next_prime(int n) {
    while (true)
    {
        if (is_prime(++n)) return n;
    }
}

int main(int argc, char const *argv[]) {
    int n;
    while (cin >> n) {
        if (!is_prime(n)) break;
        std::cout << next_prime(n) << std::endl;
    }

    int help = 0;
    float number = 4.5 + help;
    return 0;
}
