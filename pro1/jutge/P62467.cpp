#include <iostream>
using namespace std;

void print_n_times(char c, int n) {
    for (size_t i = 0; i < n; i++) {
        cout << c;
    }
}

void print_stuff(int n) {
    if (n == 1) {
        cout << '*' << endl;
        return;
    }

    print_stuff(n - 1);

    print_n_times('*', n);
    endl(cout);

    print_stuff(n - 1);
}

int main(int argc, char const *argv[]) {
    int n;
    cin >> n;

    print_stuff(n);

    return 0;
}
