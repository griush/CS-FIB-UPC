#include <iostream>
using namespace std;

int main() {
  int n, m, side;
  while (cin >> n >> m >> side) {
    for (int k = 0; k < n; k++) {
      cout << string((side + 1) * m + 1, '#') << endl;
      for (int i = 0; i < side; i++) {
        for (int j = 0; j < m; j++) {
          cout << '#' << string(side, ' ');
        }

        cout << '#' << endl;
      }
    }

    cout << string((side + 1) * m + 1, '#') << endl << endl;
  }
}
