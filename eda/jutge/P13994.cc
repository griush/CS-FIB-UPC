#include <limits.h>

#include <algorithm>
#include <iostream>
#include <queue>
#include <vector>

using namespace std;

using vertex = int;
using graph = vector<vector<pair<vertex, int>>>;  // for the adjacency list of a
                                                  // weighted directed graph
using P = pair<int, vertex>;                      // distance, vertex

vector<vertex> dijkstra(const graph& g, vertex s) {
  int n = g.size();
  vector<int> D(n, INT_MAX);      // for all the distances from s
  vector<bool> marked(n, false);  // for the visited vertices
  vector<vertex> p(n, -1);

  D[s] = 0;

  priority_queue<P, vector<P>, greater<P>> pq;
  pq.push({D[s], s});

  while (not pq.empty()) {
    vertex u = pq.top().second;
    pq.pop();
    if (not marked[u]) {
      marked[u] = true;
      for (auto i : g[u]) {
        vertex neigh = i.first;
        int w = i.second;
        if (D[neigh] > D[u] + w) {
          D[neigh] = D[u] + w;
          p[neigh] = u;
          pq.push({D[neigh], neigh});
        }
      }
    }
  }

  return p;
}

int main() {
  int n, m;
  while (cin >> n >> m) {
    graph g(n);
    for (int k = 0; k < m; ++k) {
      int u, v, c;
      cin >> u >> v >> c;
      g[u].push_back({v, c});
    }
    vertex x, y;
    cin >> x >> y;
    if (x == y) {
      cout << x << endl;
      continue;
    }
    vector<vertex> p = dijkstra(g, x);
    if (p[y] == -1)
      cout << "no path from " << x << " to " << y << endl;
    else {
      vector<vertex> path;
      for (vertex u = y; u != -1; u = p[u]) {
        path.push_back(u);
      }
      reverse(path.begin(), path.end());
      cout << path[0];
      for (size_t i = 1; i < path.size(); i++) {
        cout << ' ' << path[i];
      }
      cout << endl;
    }
  }
}