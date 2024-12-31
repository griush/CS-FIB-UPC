#include <iostream>
using namespace std;

void cross(int n, char c) {
    int half = n >> 1;

    for (int i = 0; i < half; i++)
    {
        cout << string(half, ' ') << c << endl;
    }

    cout << string(n, c) << endl;

    for (int i = 0; i < half; i++)
    {
        cout << string(half, ' ') << c << endl;
    }
}

int main() {
    cross(5, 'X');
}
