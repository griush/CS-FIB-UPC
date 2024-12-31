#include <iostream>
using namespace std;

void do_thing(int n)
{
    if (n < 0) return;
    cout << n;
    
    for (int i = 0; i < n; i++) {
        do_thing(n - 1);
        cout << n;
    }
}

int main()
{
    int x;
    while (cin >> x) {
        do_thing(x);
        endl(cout);
    }
}
