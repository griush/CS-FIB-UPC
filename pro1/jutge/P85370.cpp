#include <iostream>
using namespace std;

int main()
{
    cout.setf(ios::fixed);
    cout.precision(4);

    double c, i;
    int t;
    string type;
    cin >> c >> i >> t >> type;

    if (type == "simple")
    {
        double rate = (i / 100) * c;
        for (int y = 1; y <= t; y++)
        {
            c += rate;
        }
    }
    else if (type == "compound")
    {
        for (int y = 1; y <= t; y++)
        {
            c += (i / 100) * c;
        }
    }

    cout << c << endl;
}
