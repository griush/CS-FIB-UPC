#include <iostream>
using namespace std;

int main() {
  bool can_c = false;

  int d_batch = 0;
  int cs = 0;
  int ds = 0;
  char c;
  while (cin >> c) {
    if (c == 'c' && can_c)
      cs++;
    else if (c == 'a') {
      can_c = true;
      ds += d_batch;
      d_batch = 0;
    } else if (c == 'b') {
      can_c = false;
      d_batch = 0;
    } else if (c == 'd') {
      d_batch++;
    }
  }

  cout << cs << " " << ds << endl;
}
