#include <iostream>
using namespace std;

int main()
{
    cout.setf(ios::fixed);
    cout.precision(2);

    int n;
    cin >> n;

    double summation = 0;
    double prod_sequence = 0;
    for (int i = 0; i < n; i++)
    {
        double xi;
        cin >> xi;

        summation += xi * xi;
        prod_sequence += xi;
    }

    prod_sequence *= prod_sequence;
    double res = (summation / (n - 1)) - (prod_sequence / (n * (n - 1.0)));
    cout << res << endl;
}
