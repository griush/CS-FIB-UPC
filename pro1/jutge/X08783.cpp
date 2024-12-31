#include <iostream>
#include <cmath>
using namespace std;

int main()
{
    int b, n;
    while (cin >> b >> n)
    {
        int digits = 1;
        while (true) 
        {
            if (pow(b, digits) > n) break;
            digits++;
        }

        cout << digits << endl;
    }
}
