#include <iostream>
#include <vector>
using namespace std;
using map_t = vector<vector<char>>;
using vertex = pair<int, int>;
map_t map;
int n, m;
vector<vector<bool>> visited;

bool dfs(vertex v, vector<vector<bool>>& visited) {
  visited[v.first][v.second] = true;
  if (map[v.first][v.second] == 't') return true;
  if (map[v.first][v.second] == 'X') return false;
  if (v.first > 0 and not visited[v.first - 1][v.second])
    if (dfs({v.first - 1, v.second}, visited)) return true;
  if (v.second < m - 1 and not visited[v.first][v.second + 1])
    if (dfs({v.first, v.second + 1}, visited)) return true;
  if (v.first < n - 1 and not visited[v.first + 1][v.second])
    if (dfs({v.first + 1, v.second}, visited)) return true;
  if (v.second > 0 and not visited[v.first][v.second - 1])
    if (dfs({v.first, v.second - 1}, visited)) return true;
  return false;
}

int main() {
  cin >> n >> m;
  map = map_t(n, vector<char>(m));
  visited = vector<vector<bool>>(n, vector<bool>(m));
  for (int i = 0; i < n; i++) {
    for (int j = 0; j < m; j++) {
      char c;
      cin >> c;
      map[i][j] = c;
    }
  }
  int r, c;
  cin >> r >> c;
  cout << (dfs({r - 1, c - 1}, visited) ? "yes" : "no") << endl;
}
