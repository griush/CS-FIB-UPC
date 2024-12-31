#include <iostream>
using namespace std;

int power(int base, int exponent)
{
    if (exponent == 0)
        return 1;

    int result = base;
    while (exponent --> 1)
    {
        result *= base;
    }

    return result;
}

int main()
{
    int b, e;
    while (cin >> b >> e)
    {
        cout << power(b, e) << endl;
    }
    return 0;
}
