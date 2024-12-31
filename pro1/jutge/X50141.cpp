#include <iostream>
using namespace std;

int fatten(int x) {
    if (x < 10) return x;

    int prev = fatten(x / 10);

    int last_digit = x % 10;
    int prev_to_last = (prev % 10);
    if (last_digit < prev_to_last) last_digit = prev_to_last;
    
    return (prev * 10) + last_digit;
}

int main(int argc, char const *argv[]) {
    int n;
    while (cin >> n) {
        cout << fatten(n) << endl;
    }
    return 0;
}
