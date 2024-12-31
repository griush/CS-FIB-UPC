#include <iostream>
using namespace std;
int main() {
    bool aaa = false, aab = false, aba = false, abb = false, baa = false,
         bab = false, bba = false, bbb = false;
    char prev2, prev;
    cin >> prev2 >> prev;
    int index = 2;
    char current;
    while (cin >> current) {
        if (prev2 == 'a' && prev == 'a' && current == 'a') {
            if (aaa) break;
            aaa = true;
        } else if (prev2 == 'a' && prev == 'a' && current == 'b') {
            if (aab) break;
            aab = true;
        } else if (prev2 == 'a' && prev == 'b' && current == 'a') {
            if (aba) break;
            aba = true;
        } else if (prev2 == 'a' && prev == 'b' && current == 'b') {
            if (abb) break;
            abb = true;
        } else if (prev2 == 'b' && prev == 'a' && current == 'a') {
            if (baa) break;
            baa = true;
        } else if (prev2 == 'b' && prev == 'a' && current == 'b') {
            if (bab) break;
            bab = true;
        } else if (prev2 == 'b' && prev == 'b' && current == 'a') {
            if (bba) break;
            bba = true;
        } else if (prev2 == 'b' && prev == 'b' && current == 'b') {
            if (bbb) break;
            bbb = true;
        }
        prev2 = prev;
        prev = current;
        index++;
    }
    cout << prev2 << prev << current << " " << index - 2 << endl;
}
