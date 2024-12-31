#include <iostream>
using namespace std;

int main() {
    int n;
    while (cin >> n) {
        cout << "divisors of " << n << ':';
        int sqrt = 1;  // Not really the sqrt
                       // just the last that run the loop before
                       // It is the closest int - 1 to the sqrt
        for (int i = 1; i * i < n; i++) {
            if (n % i == 0) {
                cout << " " << i;
            }

            sqrt = i + 1;
        }

        // Check if the sqrt is also a divisor
        // Example: With 100, 10 gets printed two times
        if ((sqrt) * (sqrt) == n) {
            cout << " " << sqrt;
        }

        for (int i = sqrt - 1; i > 0; i--) {
            if (n % i == 0) {
                cout << " " << n / i;
            }
        }

        endl(cout);
    }
}
