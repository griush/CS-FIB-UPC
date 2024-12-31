#include <iostream>
#include <vector>
using namespace std;

int occurences_row(const vector<int>& row, int target) {
    int result = 0;
    for (int i = 0; i < row.size(); i++) {
        if (row[i] == target) result++;
    }

    return result;
}

int occurences_column(const vector<vector<int>>& mat, int row, int target) {
    int result = 0;
    for (int i = 0; i < mat.size(); i++) {
        if (mat[i][row] == target) result++;
    }

    return result;
}

int main() {
    int n, m;
    while (cin >> n >> m) {
        vector<vector<int>> u(n, vector<int>(m));
        // Input
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                char x;
                cin >> x;
                u[i][j] = (int)(x - '0');
            }
        }

        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                int d = u[i][j];
                cout << (occurences_row(u[i], d) + occurences_column(u, j, d)) %
                            10;
            }
            cout << endl;
        }

        cout << endl;
    }
}
