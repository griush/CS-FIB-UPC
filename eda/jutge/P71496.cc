#include <functional>
#include <iostream>
#include <queue>
#include <vector>
using namespace std;
using P = pair<int, int>;

int main() {
    int n, m;
    while (cin >> n >> m) {
        vector<vector<P>> G(n);
        int tot = 0;
        for (int i = 0; i < m; i++) {
            int x, y, c;
            cin >> x >> y >> c;
            G[x].push_back({c, y});
            G[y].push_back({c, x});
            tot += c;
        }
        vector<bool> visited(n, false);
        visited[0] = true;
        priority_queue<P, vector<P>, greater<P>> pq;
        for (P p : G[0]) pq.push(p);
        int sz = 1;
        int sum = 0;
        while (sz < n) {
            int c = pq.top().first;
            int x = pq.top().second;
            pq.pop();
            if (not visited[x]) {
                visited[x] = true;
                for (P p : G[x]) pq.push(p);
                sum += c;
                ++sz;
            }
        }
        cout << tot - sum << endl;
    }
}
