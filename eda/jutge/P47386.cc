#include <iostream>
#include <map>
#include <set>
#include <string>
using namespace std;

void add_couple(map<string, string>& partner, set<string>& singles, string x,
                string y) {
  if (partner.count(x)) {
    singles.insert(partner[x]);
    partner.erase(partner[x]);
  }
  if (partner.count(y)) {
    singles.insert(partner[y]);
    partner.erase(partner[y]);
  }

  partner[x] = y;
  partner[y] = x;
  singles.erase(x);
  singles.erase(y);
}

void print_couples_and_singles(const map<string, string>& partner,
                               const set<string>& singles) {
  cout << "COUPLES:\n";
  for (const auto& [person, partner_name] : partner) {
    if (person < partner_name) {
      cout << person << " " << partner_name << endl;
    }
  }

  cout << "ALONE:\n";
  for (const auto& single : singles) {
    cout << single << endl;
  }
  cout << "----------" << endl;
}

int main() {
  map<string, string> partner;
  set<string> singles;

  string cmd;
  while (cin >> cmd) {
    if (cmd == "affair") {
      string x, y;
      cin >> x >> y;
      add_couple(partner, singles, x, y);
    } else {
      print_couples_and_singles(partner, singles);
    }
  }
}