#include <iostream>
using namespace std;

int main() {
  int a, b, c;
  cin >> a >> b >> c;

  bool found = false;
  if ((a + b) / 2.0 == c)
    found = true;
  else if ((a + c) / 2.0 == b)
    found = true;
  else if ((c + b) / 2.0 == a)
    found = true;

  cout << (found ? "YES" : "NO") << endl;
}
