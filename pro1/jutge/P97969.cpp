#include <iostream>
using namespace std;

int main()
{
    char in;
    int as = 0;
    while (in != '.')
    {
        cin >> in;
        if (in == 'a') as++;
    }

    cout << as << endl;
}
