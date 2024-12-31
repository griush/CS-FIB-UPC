#include <iostream>
#include <cmath>
#include <iomanip>
using namespace std;

int main()
{
    int k;
    cin >> k;

    int len = 0;
    int copy = k;
    while (copy != 0)
    {
        len++;
        copy /= 10;
    }
    
    int result = 0;
    int it = len;
    while (k != 0)
    {
        result += (k % 10) * pow(10, --it);
        k /= 10;
    }
    

    cout << setw(len) << setfill('0') << result << endl;
}
