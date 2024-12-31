#include <iostream>
using namespace std;

int main()
{
    int n;
    cin >> n;
    int copy = n;

    int sum = 0;
    while (n != 0)
    {
        int last_digit = n % 10;
        sum += last_digit;
        n /= 100;
    }

    cout << copy << ((sum % 2 == 0) ? " IS COOL" : " IS NOT COOL") << endl;
}
