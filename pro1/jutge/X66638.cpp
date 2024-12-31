#include <iostream>
#include <cmath>
using namespace std;

int main()
{
    int x;
    while (cin >> x)
    {
        int even = 0, odd = 0, even_iter = 0, odd_iter = 0;
        while (x != 0)
        {
            int last_digit = x % 10;
            if (last_digit == 0)
            {
                x /= 10;
                continue;
            }

            if (last_digit % 2 == 0)
            {
                even += last_digit * pow(10, even_iter);
                even_iter++;
            }
            else
            {
                odd += last_digit * pow(10, odd_iter);
                odd_iter++;
            }

            x /= 10;
        }

        int temp = even, count = 0;
        while (temp != 0)
        {
            count++;
            temp /= 10;
        }

        int y = odd * pow(10, count) + even;
        int z = 2 * y;

        cout << y << " " << z << endl;
    }
}
