#include <iostream>
using namespace std;

int main()
{
    int r, c;
    cin >> r >> c;

    int total_coins = 0;
    char digit;
    while (cin >> digit)
    {
        int val = digit - '0';
        total_coins += val;
    }

    cout << total_coins << endl;
}
