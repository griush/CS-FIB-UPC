#include <cmath>
#include <iostream>
using namespace std;

int main()
{
    int b;
    cin >> b;

    int n;
    while (cin >> n)
    {
        int copy = n;
        int sum = 0;
        int it = 0;

        while (n > 0)
        {
            sum += n % b;
            n /= b;
        }
        

        cout << copy << ": " << sum << endl;
    }
}
