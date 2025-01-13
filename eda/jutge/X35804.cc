#include <iostream>
#include <map>
using namespace std;

struct Info {
    string code;
    int price;
};

int main() {
    map<int, Info> M;
    char c;
    while (cin >> c) {
        if (c == 'n') {
            cout << "num: " << M.size() << endl;
        } else if (c == 'u') {
            string code;
            int length, price;
            cin >> code >> length >> price;
            M[length] = Info{.code = code, .price = price};
        } else if (c == 'q') {
            int length;
            cin >> length;
            if (M.find(length) != M.end()) {
                cout << M.at(length).price << endl;
            } else {
                cout << "-1" << endl;
            }
        } else if (c == 'p') {
            cout << string(10, '-') << endl;
            for (const auto& c : M) {
                cout << c.second.code << " " << c.first << " " << c.second.price
                     << endl;
            }
            cout << string(10, '*') << endl;
        } else {  // c == ’s’
            if (M.size() < 2) {
                std::cout << "no\n";
            } else {
                auto it = M.begin();
                ++it;
                cout << it->second.code << ' ' << it->first << ' ' << it->second.price << endl;
            }
        }
    }
}
