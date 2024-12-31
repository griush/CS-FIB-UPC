#include <iostream>
using namespace std;

int main() {
    fixed(cout);
    cout.precision(10);

    int n, m;
    while (cin >> n >> m) {
        double sum = 0.0;
        for (int i = m + 1; i <= n; i++) {
            sum += 1.0 / i;
        }
        cout << sum << endl;
    }
}
