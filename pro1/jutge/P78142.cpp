#include <iostream>
#include <iomanip>
using namespace std;

int main()
{
    double sum = 0;
    int count = 0;
    double num;
    while (cin >> num)
    {
        sum += num;
        count++;
    }

    cout << fixed << setprecision(2) << sum / (double)count << endl;
}
