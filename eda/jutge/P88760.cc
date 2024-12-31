#include <iostream>
#include <queue>
#include <vector>
using namespace std;

struct vtx {
  double x, y, r;
};

double d;
int n;
vector<vtx> graph;

bool can_jump(vtx a, vtx b) {
  double dx = b.x - a.x;
  double dy = b.y - a.y;
  double ds = dx * dx + dy * dy;
  double rs = a.r + b.r;
  double mj = (d + rs) * (d + rs);
  return ds <= mj;
}

int bfs() {
  vector<bool> visited(n, false);
  vector<int> dis(n, -1);
  queue<int> q;
  q.push(0);
  dis[0] = 0;
  while (not q.empty()) {
    int curr = q.front();
    q.pop();
    for (int i = 0; i < n; i++) {
      if (i == curr) continue;
      if (not visited[i] and can_jump(graph[curr], graph[i])) {
        dis[i] = dis[curr] + 1;
        visited[i] = true;
        q.push(i);
      }
    }
  }

  return dis[n - 1];
}

int main() {
  while (cin >> n >> d) {
    graph = vector<vtx>(n);
    for (int i = 0; i < n; i++) {
      cin >> graph[i].x >> graph[i].y >> graph[i].r;
    }
    int r = bfs();
    if (r == -1)
      cout << "Xof!" << endl;
    else
      cout << r << endl;
  }
}