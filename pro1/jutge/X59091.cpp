#include <iostream>
using namespace std;

int main() {
    int n, m;
    bool first = true;
    while (cin >> n >> m) {
        char next = '9';

        if (!first) endl(cout);
        first = false;

        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                cout << next;
                next--;

                if (next < '0') next = '9';
            }

            endl(cout);
        }
    }
}
