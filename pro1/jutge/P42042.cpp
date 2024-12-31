#include <iostream>

bool is_vowel(char c) {
    return c == 'a' || c == 'e' || c == 'i' || c == 'o' || c == 'u' ||
           c == 'A' || c == 'E' || c == 'I' || c == 'O' || c == 'U';
}

bool is_uppercase(char c) { return c <= 'Z'; }

int main() {
    using namespace std;

    char c;
    cin >> c;

    if (is_uppercase(c))
        cout << "uppercase" << endl;
    else
        cout << "lowercase" << endl;

    if (is_vowel(c))
        cout << "vowel" << endl;
    else
        cout << "consonant" << endl;
}
