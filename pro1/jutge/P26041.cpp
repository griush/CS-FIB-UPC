#include <iostream>
using namespace std;

void print_reverse() {
    string str;
    if (cin >> str) {
        print_reverse();
        cout << str << endl;
    }
}

int main() {
    print_reverse();
}
