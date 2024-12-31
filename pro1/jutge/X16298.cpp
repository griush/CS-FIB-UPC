#include <iostream>
using namespace std;

// Pre: s is formed with three different characters c1,c2,c3, and is of the form c1...c1c2...c2c3...c3.
// Post: n1, n2, n3 are the number of occurrences of c1, c2, c3 in s, respectively.
void numberOccurrences(const string& s, int& n1, int& n2, int& n3) {
    char first_char = s[0];
    char second_char = 0;
    n1 = 0;
    n2 = 0;
    n3 = 0;
    for (size_t i = 0; i < s.length(); i++) {
        if (s[i] == first_char) {
            n1++;
        }
        else if (n2 == 0) {

        }
    }
}

int main() {
    
}

