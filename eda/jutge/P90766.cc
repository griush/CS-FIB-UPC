#include <iostream>
#include <vector>
using namespace std;
using map_t = vector<vector<char>>;
using vertex = pair<int, int>;
map_t map;
int n, m;
vector<vector<bool>> visited;

int bfs(vertex v, vector<vector<bool>>& visited) {
  visited[v.first][v.second] = true;
  if (v.first < 0 or v.first >= n or v.second < 0 or v.second >= m or
      map[v.first][v.second] == 'X') return 0;
  int r = 0;
  if (map[v.first][v.second] == 't') r += 1;
  if (not visited[v.first - 1][v.second])
    r += bfs({v.first - 1, v.second}, visited);
  if (not visited[v.first][v.second + 1])
    r += bfs({v.first, v.second + 1}, visited);
  if (not visited[v.first + 1][v.second])
    r += bfs({v.first + 1, v.second}, visited);
  if (not visited[v.first][v.second - 1])
    r += bfs({v.first, v.second - 1}, visited);
  return r;
}

int main() {
  cin >> n >> m;
  map = map_t(n, vector<char>(m));
  visited = vector<vector<bool>>(n, vector<bool>(m));
  for (int i = 0; i < n; i++) {
    for (int j = 0; j < m; j++) {
      cin >> map[i][j];
    }
  }
  int r, c;
  cin >> r >> c;
  cout << bfs({r - 1, c - 1}, visited) << endl;
}
