#include <iostream>
#include <vector>
using namespace std;
int n, m;
vector<int> forb;

bool is_valid(int num) {
    for (int f : forb) {
        if (num % f == 0) return false;
    }
    return true;
}

void bt(int i, int num) {
    if (i == n) {
        cout << num << endl;
        return;
    }
    for (int j = 0; j < 10; j++) {
        // cout << "currently " << num << " trying at " << i << " number " << j << endl;
        if (is_valid(num * 10 + j)) {
            bt(i + 1, num * 10 + j);
        }
    }
}

int main() {
    while (cin >> n >> m) {
        forb = vector<int>(m);
        for (int i = 0; i < m; i++) {
            cin >> forb[i];
        }
        bt(0, 0);
        cout << "----------" << endl;
    }
}
