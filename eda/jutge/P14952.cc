#include <iostream>
#include <queue>
#include <vector>
using namespace std;

using vtx = int;
using graph = vector<vector<vtx>>;

void print_vec(const vector<int>& v) {
  cout << v[0];
  for (size_t i = 1; i < v.size(); ++i) cout << ' ' << v[i];
  cout << endl;
}

vector<vtx> topological_sort(const graph& g, vector<int>& indegree) {
  int n = g.size();
  priority_queue<int, vector<int>, greater<int>> pq;
  for (int u = 0; u < n; ++u) {
    if (indegree[u] == 0) pq.push(u);
  }
  vector<int> ord;
  while (not pq.empty()) {
    int u = pq.top();
    pq.pop();
    ord.push_back(u);
    for (size_t k = 0; k < g[u].size(); ++k) {
      int v = g[u][k];
      --indegree[v];
      if (indegree[v] == 0) pq.push(v);
    }
  }
  return ord;
}

int main() {
  int n, m;
  while (cin >> n >> m) {
    graph g(n);
    vector<int> indegree(n, 0);
    for (int i = 0; i < m; i++) {
      int v1, v2;
      cin >> v1 >> v2;
      g[v1].push_back(v2);
      indegree[v2]++;
    }
    vector<vtx> v = topological_sort(g, indegree);
    print_vec(v);
  }
}