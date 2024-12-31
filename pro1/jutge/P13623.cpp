#include <iostream>
using namespace std;

int main() {
    int r, c;
    cin >> r >> c;

    int sum = 0;
    for (int i = 0; i < r; i++) {
        for (int j = i; j < c + i; j++) {
            char digit;
            cin >> digit;
            int num = digit - '0';

            if (j % 2 == 0) sum += num;
        }
    }

    cout << sum << endl;
}
