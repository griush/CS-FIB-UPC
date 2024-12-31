#include <cmath>
#include <iostream>
using namespace std;

#define DEG_TO_RAD(x) x * (M_PI / 180.0)

int main() {
    cout.setf(ios::fixed);
    cout.precision(6);

    double num;
    while (cin >> num) {
        cout << sin(DEG_TO_RAD(num)) << ' ' << cos(DEG_TO_RAD(num)) << endl;
    }
}
