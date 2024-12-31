#include <iostream>
#include <string>
using namespace std;

int max(int a, int b) { return a > b ? a : b; }
int min(int a, int b) { return a < b ? a : b; }

int main() {
    int a1, b1, a2, b2;
    cin >> a1 >> b1 >> a2 >> b2;

    // Case 2: [an, bn] == [am, bm]
    if (a1 == a2 && b1 == b2) {
        cout << "="
             << " , "
             << "[" << a1 << "," << b1 << "]" << endl;
        return 0;
    }
    if (a1 >= a2 && b1 <= b2) {
        cout << "1"
             << " , "
             << "[" << a1 << "," << b1 << "]" << endl;
    } else if (a2 >= a1 && b2 <= b1) {
        cout << "2"
             << " , "
             << "[" << a2 << "," << b2 << "]" << endl;
    } else {
        int bmax = max(b1, b2);
        int bmin = min(b1, b2);
        int amax = max(a1, a2);
        int amin = max(a1, a2);

        if (amax <= bmin)
            cout << "? , "
                 << "[" << amax << "," << bmin << "]" << endl;
        else
            cout << "?"
                 << " , "
                 << "[]" << endl;
    }
    return 0;
}
