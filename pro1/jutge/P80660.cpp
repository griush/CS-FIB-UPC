#include <iostream>
using namespace std;

int main() {
    int n;
    while (cin >> n) {
        int steps = 0;
        while (n != 1) {
            steps++;

            if (n % 2 == 0) {
                n /= 2;
                continue;
            }

            n *= 3;
            n++;
        }

        cout << steps << endl;
    }
}
