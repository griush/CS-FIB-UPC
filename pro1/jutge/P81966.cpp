#include <iostream>
#include <vector>
using namespace std;

int position(double x, const vector<double>& v, int left, int right) {
    if (left > right) return -1;
    int mid = left + (right - left) / 2;
    if (x == v[mid]) return mid;
    if (x < v[mid]) return position(x, v, left, mid - 1);
    else return position(x, v, mid + 1, right);
}

int main() {
    int n;
    while (cin >> n) {
        vector<double> V(n);
        for (int i = 0; i < n; ++i) cin >> V[i];
        int t;
        cin >> t;
        while (t--) {
            double x;
            int left, right;
            cin >> x >> left >> right;
            cout << position(x, V, left, right) << endl;
        }
    }
    return 0;
}
