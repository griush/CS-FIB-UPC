#include <cmath>
#include <iostream>
using namespace std;

int main()
{
    int k;
    cin >> k;

    for (int base = 2; base <= 16; base++)
    {
        int count = 1;
        for (; pow(base, count) <= k; count++) { }
        cout << "Base " << base << ": " << count << " cifras." << endl;
    }
}
