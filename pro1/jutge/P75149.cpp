#include <iostream>
using namespace std;

int main()
{
    char in;
    bool has_a = false;
    while ((cin >> in) && in != '.')
    {
        if (in == 'a') {
            has_a = true;
            break;
        }
    }

    cout << (has_a ? "yes" : "no") << endl;
}
