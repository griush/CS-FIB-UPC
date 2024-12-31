#include <algorithm>
#include <iostream>
#include <string>
using namespace std;

int main()
{
    int n;
    cin >> n;

    if (n == 0)
    {
        cout << 0 << endl;
        return 0;
    }

    string bin{};
    while (n > 0)
    {
        if (n % 2 == 0)
            bin.insert(bin.begin(), '0');
        else
            bin.insert(bin.begin(), '1');

        n >>= 1;
    }

    reverse(bin.begin(), bin.end());
    cout << bin << endl;
}
