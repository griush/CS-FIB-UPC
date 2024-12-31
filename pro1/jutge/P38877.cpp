#include <iostream>
using namespace std;

void print_reverse(int& n) {
    string s;
    if (cin >> s) {
        print_reverse(n);
        if (n > 0) cout << s << endl;
        n--;
    }
}

int main() {
    int n;
    cin  >> n;
    print_reverse(n);
}