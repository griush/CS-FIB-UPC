#include <iostream>
#include <vector>
using namespace std;

int n;
vector<bool> col, d1, d2;

int s(int r) {
  if (r == n)
    return 1;
  else {
    int m = 0;
    for (int j = 0; j < n; ++j) {
      if (not col[j] and not d1[n - 1 + j - r] and not d2[j + r]) {
        col[j] = true;
        d1[n - 1 + j - r] = true;
        d2[j + r] = true;
        m += s(r + 1);
        col[j] = false;
        d1[n - 1 + j - r] = false;
        d2[j + r] = false;
      }
    }
    return m;
  }
}

int main() {
  cin >> n;
  col = vector<bool>(n, false);
  d1 = vector<bool>(2 * n - 1, false);
  d2 = vector<bool>(2 * n - 1, false);
  cout << s(0) << endl;
}