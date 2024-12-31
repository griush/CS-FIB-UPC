#include <iostream>
using namespace std;

const char values[17] = "0123456789ABCDEF";

void print_as_base(int, int);

int main() {
    int n;
    while (cin >> n) {
        cout << n << " = ";
        print_as_base(2, n);
        cout << ", ";
        print_as_base(8, n);
        cout << ", ";
        print_as_base(16, n);
        endl(cout);
    }
}

void print_as_base(int base, int n) {
    if (n < base) {
        cout << values[n];
        return;
    }

    print_as_base(base, n / base);
    cout << values[n % base];
}
