#include <cstring>
#include <iostream>
#include <queue>
#include <vector>

using namespace std;

unsigned n, m, s;
struct Ed {
  unsigned v;
  unsigned long long w;
  bool operator<(const Ed &p) const { return w > p.w; }
};
vector<vector<Ed>> e;
unsigned long long dist[600000];
int vis[600000];

long long bitcast(unsigned long long p) { return *(long long *)(&p); }

int main() {
  scanf("%u %u %u", &n, &m, &s);
  s--;
  e.resize(n);
  for (int i = 0; i < m; i++) {
    unsigned u, v, w;
    scanf("%u %u %u", &u, &v, &w);
    u--;
    v--;
    e[u].push_back({v, w});
  }
  memset(dist, -1, sizeof(dist));

  dist[s] = 0;
  priority_queue<Ed> q;
  q.push({s, 0});
  while (!q.empty()) {
    auto ed = q.top();
    q.pop();
    int u = ed.v;
    if (vis[u])
      continue;
    vis[u] = 1;
    for (auto v : e[u]) {
      if (!vis[v.v]) {
        if (dist[v.v] > dist[u] + v.w) {
          dist[v.v] = dist[u] + v.w;
          q.push({v.v, dist[v.v]});
        }
      }
    }
  }
  for (int i = 0; i < n; i++) {
    printf("%lld ", bitcast(dist[i]));
  }
}
// 64 位输出请用 printf("%lld")