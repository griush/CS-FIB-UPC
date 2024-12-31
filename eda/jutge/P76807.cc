#include <iostream>
#include <vector>

using namespace std;
using v = vector<int>;
using vv = vector<v>;
using vvv = vector<vv>;

vv sudoku(9, vector<int>(9));
vv rows, cols;
vvv boxs;

void print() {
  for (int i = 0; i < 9; i++) {
    for (int j = 0; j < 9; j++) {
      cout << (j ? " " : "") << sudoku[i][j];
    }
    cout << endl;
  }
}

bool solve(int i, int j) {
  if (i == 9) {
    print();
    return true;
  }

  if (j == 9) return solve(i + 1, 0);

  if (sudoku[i][j] != 0) return solve(i, j + 1);

  for (int d = 1; d <= 9; d++) {
    if (not rows[i][d] and not cols[j][d] and not boxs[i / 3][j / 3][d]) {
      rows[i][d] = cols[j][d] = boxs[i / 3][j / 3][d] = true;
      sudoku[i][j] = d;
      if (solve(i, j + 1)) return true;
      sudoku[i][j] = 0;
      rows[i][d] = cols[j][d] = boxs[i / 3][j / 3][d] = false;
    }
  }

  return false;
}

int main() {
  int n;
  cin >> n;
  cout << n << endl;
  while (n--) {
    cout << endl;
    rows = cols = vv(9, v(10, false));
    boxs = vvv(3, vv(3, v(10, false)));
    for (int i = 0; i < 9; ++i)
      for (int j = 0; j < 9; ++j) {
        char c;
        cin >> c;
        if (c == '.')
          sudoku[i][j] = 0;
        else {
          int d = c - '0';
          sudoku[i][j] = d;
          rows[i][d] = cols[j][d] = boxs[i / 3][j / 3][d] = true;
        }
      }

    solve(0, 0);
  }
}