#include <algorithm>
#include <iostream>
#include <string>
using namespace std;

int main()
{
    int n;
    cin >> n;

    char hex_values[16] = {
        '0', '1', '2', '3', '4', '5', '6', '7', '8', '9', 'A', 'B', 'C', 'D', 'E', 'F',
    };

    if (n == 0)
    {
        cout << 0 << endl;
        return 0;
    }

    string hex{};
    while (n > 0)
    {
        hex.insert(hex.begin(), hex_values[n % 16]);
        n /= 16;
    }

    reverse(hex.begin(), hex.end());
    cout << hex << endl;
}
