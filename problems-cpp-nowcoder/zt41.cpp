#include <iostream>
#include <queue>
#include <vector>

using namespace std;

vector<vector<int>> to;
vector<int> vis;

int main() {
  int n, m, s;
  scanf("%d %d %d", &n, &m, &s);
  s--;
  to.resize(n);
  vis.resize(n);
  for (int i = 0; i < m; i++) {
    int u, v;
    scanf("%d %d", &u, &v);
    u--;
    v--;
    to[u].push_back(v);
  }

  vis[s] = 1;
  queue<int> q;
  q.push(s);
  while (!q.empty()) {
    auto u = q.front();
    q.pop();
    for (auto v : to[u]) {
      if (!vis[v]) {
        vis[v] = vis[u] + 1;
        q.push(v);
      }
    }
  }
  for (int i = 0; i < n; i++) {
    printf("%d ", vis[i] - 1);
  }
}
// 64 位输出请用 printf("%lld")