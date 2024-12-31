#include <iostream>
using namespace std;

int main() {
    int n;

    while (cin >> n) {
        int numx = n;
        for (int i = n - 1; i > 0; i--) {
            cout << string(i, ' ') << string(numx, 'X') << endl;
            numx += 2;
        }

        for (int i = 0; i < n; i++)
        {
            cout << string(numx, 'X') << endl;
        }
        
        numx -= 2;
        for (int i = 1; i < n; i++) {
            cout << string(i, ' ') << string(numx, 'X') << endl;
            numx -= 2;
        }

        endl(cout);
    }
}
