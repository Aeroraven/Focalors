#include <cstdint>
#include <cstring>
#include <iostream>
#include <queue>
#include <vector>

using namespace std;

int n, m, vis[500005];
int dist[500005];
struct Ed {
  int v, w, id;
  bool operator<(const Ed &p) const { return w > p.w; }
};
vector<vector<Ed>> e;
vector<int> te;

int main() {
  scanf("%d %d", &n, &m);
  e.resize(n);
  for (int i = 0; i < m; i++) {
    int u, v, w;
    scanf("%d %d %d", &u, &v, &w);
    u--;
    v--;
    e[u].push_back({v, w, i + 1});
    e[v].push_back({u, w, i + 1});
  }
  for (int i = 0; i < n; i++) {
    dist[i] = 0x7fffffff;
  }

  priority_queue<Ed> q;
  long long cost = 0;
  q.push({0, 0, 0});
  while (!q.empty()) {
    auto t = q.top();
    q.pop();
    int u = t.v;
    if (vis[u])
      continue;
    vis[u] = 1;
    if (t.id != 0) {
      te.push_back(t.id);
    }
    cost += t.w;
    for (auto v : e[u]) {
      if (!vis[v.v]) {
        if (v.w < dist[v.v]) {
          dist[v.v] = v.w;
          q.push(v);
        }
      }
    }
  }
  printf("%lld\n", cost);
  for (auto tv : te) {
    printf("%d ", tv);
  }
}
// 64 位输出请用 printf("%lld")