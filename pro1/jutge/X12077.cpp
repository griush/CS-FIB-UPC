#include <iostream>
#include <vector>

using namespace std;

int countHappySubsequences(vector<vector<char>>& matrix) {
    int n = matrix.size();
    int m = matrix[0].size();

    vector<vector<int>> dp_colon(n, vector<int>(m, 0));
    vector<vector<int>> dp_dash(n, vector<int>(m, 0));
    vector<vector<int>> dp_paren(n, vector<int>(m, 0));

    vector<vector<int>> prefix_colon(n+1, vector<int>(m+1, 0));
    vector<vector<int>> prefix_dash(n+1, vector<int>(m+1, 0));

    for (int y = 1; y <= n; y++) {
        for (int x = 1; x <= m; x++) {
            prefix_colon[y][x] = prefix_colon[y-1][x] + prefix_colon[y][x-1] - prefix_colon[y-1][x-1];
            prefix_dash[y][x] = prefix_dash[y-1][x] + prefix_dash[y][x-1] - prefix_dash[y-1][x-1];

            if (matrix[y-1][x-1] == ':') {
                dp_colon[y-1][x-1] = 1;
                prefix_colon[y][x]++;
            } else if (matrix[y-1][x-1] == '-') {
                dp_dash[y-1][x-1] = prefix_colon[y-1][x-1];
                prefix_dash[y][x] += dp_dash[y-1][x-1];
            } else if (matrix[y-1][x-1] == ')') {
                dp_paren[y-1][x-1] = prefix_dash[y-1][x-1];
            }
        }
    }

    int count = 0;
    for (int y = 0; y < n; y++) {
        for (int x = 0; x < m; x++) {
            count += dp_paren[y][x];
        }
    }

    return count;
}

int main() {
    int n, m;

    while (cin >> n >> m) {
        vector<vector<char>> matrix(n, vector<char>(m));

        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                cin >> matrix[i][j];
            }
        }

        int result = countHappySubsequences(matrix);
        cout << result << endl;
    }

    return 0;
}
