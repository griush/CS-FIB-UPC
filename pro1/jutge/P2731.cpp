#include <iostream>
using namespace std;

int main()
{
    int a, b;
    while (cin >> a >> b)
    {
        int sum = 0;
        for (int i = a; i <= b; i++)
        {
            sum += i * i * i;
        }

        cout << "suma dels cubs entre " << a << " i " << b << ": " << sum << endl;
    }
}
