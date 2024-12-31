#include <iostream>
#include <vector>
using namespace std;
using graph = vector<vector<int>>;
using vertex = int;

bool cyclic(const graph& g, vertex v, vector<bool>& visited,
            vector<int>& father) {
  if (visited[v]) return true;
  visited[v] = true;
  for (int u : g[v]) {
    if (father[v] != u) {
      father[u] = v;
      if (cyclic(g, u, visited, father)) return true;
    }
  }
  return false;
}

int count_trees(const graph& g) {
  int n = g.size();
  int res = 0;
  vector<bool> vis(n, false);
  vector<int> f(n, -1);
  for (int v = 0; v < n; ++v) {
    if (not vis[v]) {
      if (cyclic(g, v, vis, f))
        return -1;
      else
        ++res;
    }
  }
  return res;
}

int main() {
  int n, m;
  while (cin >> n >> m) {
    graph g(n);
    for (; m > 0; m--) {
      int i, v;
      cin >> i >> v;
      g[i].push_back(v);
      g[v].push_back(i);
    }
    int n_trees = count_trees(g);
    if (n_trees == -1)
      cout << "no" << endl;
    else
      cout << n_trees << endl;
  }
}
