#include <iostream>
using namespace std;

int main()
{
    int num_spaces, num_rombes;
    while (cin >> num_spaces >> num_rombes)
    {
        for (int i = 0; i < num_rombes; i++)
        {
            cout << string(num_spaces, ' ');
            cout << "*" << endl;
            int num_spaces_mid = 1;
            for (int s = num_spaces - 1; s >= 0; s--)
            {
                cout << string(s, ' ') << "*";
                cout << string(num_spaces_mid, ' ') << "*";
                endl(cout);
                num_spaces_mid += 2;
            }

            num_spaces_mid -= 2;
            for (int s = 1; s < num_spaces; s++)
            {
                num_spaces_mid -= 2;
                cout << string(s, ' ') << "*";
                cout << string(num_spaces_mid, ' ') << "*";
                endl(cout);
            }
        }

        cout << string(num_spaces, ' ');
        cout << "*" << endl;

        endl(cout);
    }
}
