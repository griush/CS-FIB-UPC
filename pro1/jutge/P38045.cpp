#include <cmath>
#include <iostream>
using namespace std;

int main() {
    cout.setf(ios::fixed);
    cout.precision(6);

    int num;
    while (cin >> num) {
        cout << num * num << ' ' << sqrt(num) << endl;
    }
}
