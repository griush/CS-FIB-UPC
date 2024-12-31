#include <iostream>
#include <queue>
#include <vector>
using namespace std;
using map_t = vector<vector<char>>;
using vertex = pair<int, int>;
map_t map;
int n, m;
vector<vector<bool>> visited;
#define at(v) (v.first * m + v.second)
#define safe(v)                                                              \
  (not((v.first < 0 or v.first >= n) or (v.second < 0 or v.second >= m)) and \
   map[v.first][v.second] != 'X')

int bfs(vertex v) {
  vector<int> d(n * m, -1);
  queue<vertex> q;
  q.push(v);
  d[at(v)] = 0;
  int max = -1;
  while (not q.empty()) {
    vertex c = q.front();
    q.pop();
    {
      vertex top(c.first - 1, c.second);
      if (safe(top) and d[at(top)] == -1) {
        if (map[top.first][top.second] == 't') max = d[at(c)] + 1;
        q.push(top);
        d[at(top)] = d[at(c)] + 1;
      }
    }
    {
      vertex bot(c.first + 1, c.second);
      if (safe(bot) and d[at(bot)] == -1) {
        if (map[bot.first][bot.second] == 't') max = d[at(c)] + 1;
        q.push(bot);
        d[at(bot)] = d[at(c)] + 1;
      }
    }
    {
      vertex left(c.first, c.second - 1);
      if (safe(left) and d[at(left)] == -1) {
        if (map[left.first][left.second] == 't') max = d[at(c)] + 1;
        q.push(left);
        d[at(left)] = d[at(c)] + 1;
      }
    }
    {
      vertex right(c.first, c.second + 1);
      if (safe(right) and d[at(right)] == -1) {
        if (map[right.first][right.second] == 't') max = d[at(c)] + 1;
        q.push(right);
        d[at(right)] = d[at(c)] + 1;
      }
    }
  }

  return max;
}

int main() {
  cin >> n >> m;
  map = map_t(n, vector<char>(m));
  for (int i = 0; i < n; i++) {
    for (int j = 0; j < m; j++) {
      cin >> map[i][j];
    }
  }
  int r, c;
  cin >> r >> c;
  int d = bfs({r - 1, c - 1});
  if (d == -1)
    cout << "no treasure can be reached" << endl;
  else
    cout << "maximum distance: " << d << endl;
}
