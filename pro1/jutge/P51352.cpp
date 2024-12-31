#include <iostream>
using namespace std;

int main()
{
    char a, b;
    cin >> a >> b;

    if (a == b)
    {
        cout << "-" << endl;
    }
    else if (a == 'A' && b == 'V')
    {
        cout << "2" << endl;
    }
    else if (a == 'V' && b == 'A')
    {
        cout << "1" << endl;
    }
    else if (min(a, b) == a)
    {
        cout << "1" << endl;
    }
    else
    {
        cout << "2" << endl;
    }

    return 0;
}
