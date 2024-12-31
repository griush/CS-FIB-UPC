#include <iostream>
using namespace std;

int main() {
    bool a = false, b = false, c = false, d = false;

    char current;
    int index = 0;
    while (cin >> current) {
        if (current == 'a') {
            if (a) break;
            a = true;
        } else if (current == 'b') {
            if (b) break;
            b = true;
        } else if (current == 'c') {
            if (c) break;
            c = true;
        } else if (current == 'd') {
            if (d) break;
            d = true;
        }

        index++;
    }

    cout << current << " " << index << endl;
}
