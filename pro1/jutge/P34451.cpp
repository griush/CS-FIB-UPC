#include <iostream>
using namespace std;

int main()
{
    int n;
    cin >> n;

    int count = 0;
    int x;
    while (cin >> x)
    {
        if (x % n == 0)
            count++;
    }
    cout << count << endl;
}
