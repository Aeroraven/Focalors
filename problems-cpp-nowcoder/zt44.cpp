#include <cstring>
#include <iostream>
#include <queue>
#include <vector>

using namespace std;

using ll = long long;
using ull = unsigned long long;
int n, m, h, md;

struct Edv {
  int v, w, d;
};
struct To {
  int v;
  ull w;
  bool operator<(const To &p) const { return v > p.v; }
};
vector<vector<Edv>> e;
ull dist[100005];
int vis[100005];

bool trav(int carweight) {
  memset(dist, -1, sizeof(dist));
  memset(vis, 0, sizeof(vis));
  dist[0] = 0;
  priority_queue<To> q;
  q.push({0, 0});
  while (!q.empty()) {
    auto ep = q.top();
    q.pop();
    int u = ep.v;
    if (vis[u])
      continue;
    vis[u] = 1;
    for (auto ve : e[u]) {
      if (!vis[ve.v]) {
        auto w = ve.w, d = ve.d, v = ve.v;
        if (w >= carweight && dist[v] > dist[u] + d) {
          dist[v] = dist[u] + d;
          q.push({v, dist[v]});
          if (v == n - 1 && dist[v] <= h) {
            return true;
          }
        }
      }
    }
  }
  return false;
}

int main() {
  scanf("%d %d %d", &n, &m, &h);
  e.resize(n);
  for (int i = 0; i < m; i++) {
    int u, v, w, d;
    scanf("%d %d %d %d", &u, &v, &w, &d);
    u--, v--;
    e[u].push_back({v, w, d});
    e[v].push_back({u, w, d});
    md = max(w, md);
  }

  int l = -1, r = md;
  while (l < r) {
    int mid = (l + r + 1) / 2;
    bool able = trav(mid);
    if (able) {
      l = mid;
    } else {
      r = mid - 1;
    }
  }
  if (l >= 0)
    printf("%d", l);
  else
    printf("-1");

  return 0;
}
