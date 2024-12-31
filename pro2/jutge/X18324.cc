#include <iostream>
#include <stack>
using namespace std;

int solution(string in) {
    int result = 0;

    stack<char> s;
    for (size_t i = 0; i < in.length(); i++) {
        char c = in[i];
        if (c == '(' || c == '[')
            s.push(c);
        else if (c == ')') {
            if (s.size() == 0 || s.top() == '[')
                break;
            else
                s.pop();
        } else if (c == ']') {
            if (s.size() == 0 || s.top() == '(')
                break;
            else
                s.pop();
        }

        if (s.size() == 0) result = (int)i + 1;
    }

    return result;
}

int main() {
    string in;

    while (cin >> in) {
        cout << solution(in) << endl;
    }
}
