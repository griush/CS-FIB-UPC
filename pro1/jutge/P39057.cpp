#include <cmath>
#include <iostream>
#include <iomanip>
using namespace std;

int main()
{
    int cases;
    cin >> cases;

    for (int i = 0; i < cases; i++)
    {
        string type;
        cin >> type;

        if (type == "rectangle")
        {
            double w, h;
            cin >> w >> h;
            cout << fixed << setprecision(6) << w * h << endl;
        }
        else // safe to asume that the other case is circle
             // due to problem constraints
        {
            double r;
            cin >> r;
            cout << fixed << setprecision(6) << M_PI * r * r << endl;
        }
    }
    
}
