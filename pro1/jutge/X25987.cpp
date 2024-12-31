#include <iostream>
using namespace std;

int main() {
  int n;
  while (cin >> n) {
    int r = n % 10;
    n /= 10;
    int m = n % 10;
    n /= 10;

    int count = 0;

    int l = 0;
    while (n != 0) {
      l = n % 10;
      if (m > r && m > l) count++;

      r = m;
      m = l;
      n /= 10;
    }

    cout << count << endl;
  }
}
