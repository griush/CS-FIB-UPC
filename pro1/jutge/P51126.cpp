#include <iostream>
using namespace std;

int max(int a, int b) { return a > b ? a : b; }
int min(int a, int b) { return a < b ? a : b; }

int main() {
    int a1, b1, a2, b2;
    cin >> a1 >> b1 >> a2 >> b2;

    // Case 2: [an, bn] == [am, bm]
    if (a1 == a2 && b1 == b2) {
        cout << "[" << a1 << "," << b1 << "]" << endl;
        return 0;
    }

    // Case 4: intervals outside of eachother
    else if (b1 < a2 || b2 < a1) {
        cout << "[]" << endl;
        return 0;
    }

    // Case 1: [an, bn] in [am, bm]
    // Case 3: interval is an, bm
    int bmax = max(b1, b2);
    int bmin = min(b1, b2);
    int amax = max(a1, a2);
    int amin = max(a1, a2);

    cout << "[" << amax << "," << bmin << "]" << endl;
    return 0;
}
