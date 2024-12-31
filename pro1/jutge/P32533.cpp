#include <iostream>
using namespace std;

int main()
{
    int n;
    cin >> n;

    for (int i = n - 1; i >= 0; i--)
    {
        cout << string(i, '+');
        cout << "/" << string(n - (i + 1), '*') << endl;
    }
}
