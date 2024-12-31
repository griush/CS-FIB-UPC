#include <iostream>
using namespace std;

int main()
{
    int d, n, t;
    cin >> d >> n >> t;
    int result = 0;
    for (int week = 0; week < t; week++)
    {
        int a;
        cin >> a;
        n += -d + a;

        if (n > 0)
        {
            result++;
        }
    }

    cout << result << endl;        
}
