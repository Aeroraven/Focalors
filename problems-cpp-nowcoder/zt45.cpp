#include <cstring>
#include <iostream>
#include <queue>
#include <vector>

using namespace std;

int n, m, q;
using ull = unsigned long long;

struct Ed {
  int v, w;
};
struct To {
  int v;
  ull w;
  bool operator<(const To &p) const { return w > p.w; }
};

vector<vector<Ed>> e;
ull dist[200004];
int vis[200005];

int main() {
  scanf("%d %d %d", &n, &m, &q);
  e.resize(n);
  memset(vis, 0, sizeof(vis));
  memset(dist, -1, sizeof(dist));
  for (int i = 0; i < m; i++) {
    int u, v, w;
    scanf("%d %d %d", &u, &v, &w);
    u--, v--;
    e[u].push_back({v, w});
    e[v].push_back({u, w});
  }

  dist[0] = 0;
  priority_queue<To> h;
  h.push({0, 0});
  while (!h.empty()) {
    auto ed = h.top();
    h.pop();
    auto u = ed.v;
    if (vis[u])
      continue;
    vis[u] = 1;
    for (auto ex : e[u]) {
      auto v = ex.v;
      auto w = ex.w;
      if (vis[ex.v])
        continue;
      if (dist[v] > dist[u] + w) {
        dist[v] = dist[u] + w;
        h.push({v, dist[v]});
      }
    }
  }

  ull ans = 0;
  for (int i = 0; i < q; i++) {
    int ps;
    scanf("%d", &ps);
    ans += dist[ps - 1];
  }
  printf("%lld", ans * 2ull);
}
// 64 位输出请用 printf("%lld")