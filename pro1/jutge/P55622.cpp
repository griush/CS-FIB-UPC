#include <iostream>
using namespace std;

int main()
{
    int n;
    cin >> n;
    int copy = n;

    if (n == 0)
    {
        cout << "The number of digits of " << n << " is 1." << endl;
        return 0;
    }

    int count = 0;
    while (n != 0)
    {
        count++;
        n /= 10;
    }

    cout << "The number of digits of " << copy << " is " << count << "." << endl;
}
