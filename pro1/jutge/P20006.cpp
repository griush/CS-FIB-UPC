#include <iostream>
using namespace std;

inline bool is_numeric(char c) { return c >= '0' && c <= '9'; }

int evaluate() {
    char current;
    if (cin >> current) {
        if (is_numeric(current)) {
            return (int)(current - '0');
        }

        int left = evaluate();
        int right = evaluate();

        if (current == '*') {
            return left * right;
        } else if (current == '+') {
            return left + right;
        } else if (current == '-') {
            return left - right;
        }
    }

    return -1;  // I think is safe to assume that correct inputs will never end
                // here
}

int main() {
    int out = evaluate();
    cout << out << endl;
}
