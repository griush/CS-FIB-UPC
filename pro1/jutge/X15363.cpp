#include <iostream>
using namespace std;

/*
 *    @brief: No one knows what this does.
 *    MAGIC!
 */
void magic_function(int, int);

int main() {
    int n;
    while (cin >> n) {
        magic_function(n, n - 1);
        endl(cout);
    }
}

void magic_function(int n, int max_spaces) {
    if (n == 1) {
        cout << string(max_spaces, ' ') << '*' << endl;
        return;
    }

    magic_function(n - 1, max_spaces);

    // draw original n here
    int max_width = n * 2 - 1;
    int curr_spaces = max_spaces - 1;
    for (int i = 3; i <= max_width; i += 2) {
        cout << string(curr_spaces, ' ') << string(i, '*') << endl;
        curr_spaces--;
    }

    curr_spaces += 2;
    for (int i = max_width - 2; i >= 3; i -= 2) {
        cout << string(curr_spaces, ' ') << string(i, '*') << endl;
        curr_spaces++;
    }

    magic_function(n - 1, max_spaces);
}
