#include <iostream>
#include <vector>

using namespace std;

// Pre: c1,c2,c3 are pairwise different characters.
// Post: returns the number of triples (i1,i2,i3) such that 0<=i1<i2<i3<s.size()
// and
//       s[i1]=c1, s[i2]=c2, s[i3]=c3.
int numberSubsequences(const string &s, char c1, char c2, char c3) {
    int count_c1 = 0, count_c2 = 0;
    int result = 0;

    for (char ch : s) {
        if (ch == c1) {
            count_c1++;
        } else if (ch == c2) {
            count_c2 += count_c1; // Count subsequences with c1 before c2
        } else if (ch == c3) {
            result += count_c2; // Count subsequences with c1 and c2 before c3
        }
    }

    return result;
}

// Pre:
// Post: returns the number of triples (i1,i2,i3) such that 0<=i1<i2<i3<s.size()
// and
//       either s[i1]=':', s[i2]='-', s[i3]=')' or s[i1]='(', s[i2]='-',
//       s[i3]=':'.
int numberHappySubsequences(const string &s) {
    return numberSubsequences(s, ':', '-', ')') +
           numberSubsequences(s, '(', '-', ':');
}

// Pre:
// Post: returns the number of triples (i1,i2,i3) such that 0<=i1<i2<i3<s.size()
// and
//       either s[i1]=':', s[i2]='-', s[i3]='(' or s[i1]=')', s[i2]='-',
//       s[i3]=':'.
int numberSadSubsequences(const string &s) {
    return numberSubsequences(s, ':', '-', '(') +
           numberSubsequences(s, ')', '-', ':');
}

int main() {
    string in;
    while (cin >> in) {
        cout << numberHappySubsequences(in) << ' ' << numberSadSubsequences(in)
             << endl;
    }
}
