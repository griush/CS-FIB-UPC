#include <iostream>
#include <queue>
#include <vector>
using namespace std;
using V = vector<char>;
using VV = vector<V>;
using P = pair<int, int>;
VV M;
int n, m;
int ini_i, ini_j;
P ddirs[] = {{-1, -1}, {-1, 0}, {-1, 1}, {0, -1},
             {0, 1},   {1, -1}, {1, 0},  {1, 1}};
P dirs[] = {{-1, 0}, {0, -1}, {0, 1}, {1, 0}};

bool search() {
    vector<vector<int>> D = vector<vector<int>>(n, vector<int>(m, -1));
    D[ini_i][ini_j] = 0;
    queue<P> Q;
    Q.push({ini_i, ini_j});
    while (not Q.empty()) {
        int i = Q.front().first;
        int j = Q.front().second;
        Q.pop();
        bool ghost = false;
        for (P dir : ddirs) {
            char c = M[i + dir.first][j + dir.second];
            int d = D[i + dir.first][j + dir.second];
            if (c == 'F') {
                ghost = true;
                break;
            }
        }
        if (ghost) continue;
        for (int q = 0; q < 4; q++) {
            P dir = dirs[q];
            char c = M[i + dir.first][j + dir.second];
            int d = D[i + dir.first][j + dir.second];
            if (d == -1 and c != 'X') {
                D[i + dir.first][j + dir.second] = D[i][j] + 1;
                Q.push({i + dir.first, j + dir.second});
            } else if (M[i][j] == 'B') {
                return true;
            }
        }
    }
    return false;
}

int main() {
    while (cin >> n >> m) {
        M = VV(n, V(m));
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                cin >> M[i][j];
                if (M[i][j] == 'P') {
                    ini_i = i;
                    ini_j = j;
                }
            }
        }

        if (search()) {
            cout << "yes" << endl;
        } else {
            cout << "no" << endl;
        }
    }
}
