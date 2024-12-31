#include <iostream>
using namespace std;

int main()
{
    int a, b;
    cin >> a >> b;
    int temp = a;
    a = min(a, b);    // a is smaller
    b = max(temp, b); // b is greater

    for (int i = b; i >= a; i--)
    {
        cout << i << endl;
    }

    return 0;
}
