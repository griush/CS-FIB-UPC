#include <iostream>
using namespace std;

int main() {
    int n;
    cin >> n;
    
    int h = n / 3600;
    n -= h * 3600;
    int m = n / 60;
    n -= m * 60;
    int s = n;

    cout << h << " " << m << " " << s << endl;
}
