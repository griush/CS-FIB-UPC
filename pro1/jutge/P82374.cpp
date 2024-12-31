#include <iostream>
using namespace std;

int main() {
    int x, a, b, c, d;
    cin >> x >> a >> b >> c >> d;

    bool result = (x >= a && x <= b) || (x >= c && x <= d);
    cout << (result ? "yes" : "no") << endl;
}
