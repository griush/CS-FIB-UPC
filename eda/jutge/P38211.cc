#include <iostream>
#include <vector>
using namespace std;

int n;
vector<int> c;
vector<bool> col, d1, d2;

void print() {
  for (int i = 0; i < n; i++) {
    for (int j = 0; j < n; j++) {
      cout << (j == c[i] ? "Q" : ".");
    }
    cout << endl;
  }
}

bool s(int r) {
  if (r == n) {
    print();
    return true;
  } else {
    int m = 0;
    for (int j = 0; j < n; ++j) {
      if (not col[j] and not d1[n - 1 + j - r] and not d2[j + r]) {
        col[j] = true;
        d1[n - 1 + j - r] = true;
        d2[j + r] = true;
        c[r] = j;
        if (s(r + 1)) return true;
        col[j] = false;
        d1[n - 1 + j - r] = false;
        d2[j + r] = false;
      }
    }
    return false;
  }
}

int main() {
  cin >> n;
  c = vector<int>(n);
  col = vector<bool>(n, false);
  d1 = vector<bool>(2 * n - 1, false);
  d2 = vector<bool>(2 * n - 1, false);
  if (not s(0)) cout << "NO SOLUTION" << endl; 
}