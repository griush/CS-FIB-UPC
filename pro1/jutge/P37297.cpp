#include <iostream>
using namespace std;

int main() {
    int n;
    cin >> n;
    int u = n % 10;
    n /= 10;
    int d = n % 10;
    n /= 10;
    int c = n % 10;

    cout << u + d + c << endl;
}
