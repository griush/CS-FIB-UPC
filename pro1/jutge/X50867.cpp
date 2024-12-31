// Pre: n >= 1
// Post: Returns 1-2+3-4+...+(-1)^(n+1)*n
int simpleAlternatedSum(int n) {
    if (n == 1) return 1;
    return (n & 0x1) ? (-n + simpleAlternatedSum(n - 1)) : (n + simpleAlternatedSum(n - 1));
}

#include <iostream>
using namespace std;

int main() {
    cout << simpleAlternatedSum(1) << endl;
    cout << simpleAlternatedSum(5) << endl;
    cout << simpleAlternatedSum(10) << endl;
    cout << simpleAlternatedSum(533) << endl;
}
