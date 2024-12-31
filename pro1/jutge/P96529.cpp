#include <iostream>
using namespace std;

bool is_valid(const std::string& s) {
    int paren_count = 0, key_count = 0;

    for (char c : s) {
        if (c == '(') paren_count++;
        else if (c == ')') paren_count--;
        else if (c == '[') key_count++;
        else if (c == ']') key_count--;

        if (paren_count < 0 || key_count < 0) return false;
    }

    return paren_count == 0 && key_count == 0;
}

int main() {
    string input;
    while (cin >> input) {
        cout << (is_valid(input) ? "si" : "no") << endl;
    }
}
