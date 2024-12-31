#include <iostream>
using namespace std;

int main()
{
    int a, b, c;
    string op, cmp;

    // NUM1 OPERATOR NUM2 COMPARATOR NUM3
    while (cin >> a >> op >> b >> cmp >> c)
    {
        int op_res = 0;
        if (op == "+")
            op_res = a + b;
        else if (op == "-")
            op_res = a - b;
        else if (op == "*")
            op_res = a * b;

        bool cmp_res = false;
        if (cmp == "<")
            cmp_res = op_res < c;
        else if (cmp == ">")
            cmp_res = op_res > c;
        else if (cmp == "<=")
            cmp_res = op_res <= c;
        else if (cmp == ">=")
            cmp_res = op_res >= c;
        else if (cmp == "==")
            cmp_res = op_res == c;
        else if (cmp == "!=")
            cmp_res = op_res != c;

        cout << (cmp_res ? "true" : "false") << endl;
    }
}
