#include <iostream>
using namespace std;

int main() {
    int a1, b1, a2, b2;
    cin >> a1 >> b1 >> a2 >> b2;

    // Case 2: [an, bn] == [am, bm]
    if (a1 == a2 && b1 == b2) {
        cout << "=" << endl;
        return 0;
    }

    if (a1 >= a2 && b1 <= b2) {
        cout << "1" << endl;
    } else if (a2 >= a1 && b2 <= b1) {
        cout << "2" << endl;
    } else
        cout << "?" << endl;

    return 0;
}
