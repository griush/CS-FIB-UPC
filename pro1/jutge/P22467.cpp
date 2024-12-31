#include <iostream>
using namespace std;

int digit_sum(int n) { return (n < 10) ? n : n % 10 + digit_sum(n / 10); }

bool is_prime(int n) {
    if (n == 0 || n == 1) return false;
    for (int i = 2; i * i <= n; i++) {
        if (n % i == 0) {
            return false;
        }
    }

    return true;
}

bool is_perfect_prime(int n) {
	if (n < 10 && is_prime(n)) return true;
    return is_prime(n) && is_perfect_prime(digit_sum(n));
}

int main() {
    cout << is_perfect_prime(977) << endl;
    cout << is_perfect_prime(978) << endl;
    cout << is_perfect_prime(0) << endl;
    cout << is_perfect_prime(11) << endl;
    cout << is_perfect_prime(587899597) << endl;
}
