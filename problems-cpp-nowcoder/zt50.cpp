#include <climits>
#include <cmath>
#include <cstring>
#include <iostream>
#include <vector>

using namespace std;

int n;
int w[100005];
int vf[200005];
int vis[100005];
vector<vector<int>> e;

#define f(i, j) vf[(j)*100001 + (i)]

inline bool issq(int x, int y) {
  long long v = 1ll * x * y;
  long long sqv = sqrt(v);
  if (sqv * sqv == v)
    return true;
  return false;
}

void dfs(int u) {
  f(u, 0) = 0;
  f(u, 1) = -INT_MAX;

  for (auto v : e[u]) {
    if (vis[v] == -1) {
      vis[v] = u;
      dfs(v);
      f(u, 0) += max(f(v, 0), f(v, 1));
    }
  }
  for (auto v : e[u]) {
    if (vis[v] == u) {
      if (issq(w[u], w[v])) {
        f(u, 1) = max(f(u, 1), f(u, 0) - max(f(v, 0), f(v, 1)) + f(v, 0) + 2);
      }
    }
  }
}

int main() {
  scanf("%d", &n);
  for (int i = 0; i < n; i++) {
    scanf("%d", w + i);
  }
  e.resize(n);
  memset(vis, -1, sizeof(vis));
  for (int i = 0; i < n - 1; i++) {
    int u, v;
    scanf("%d %d", &u, &v);
    u--;
    v--;
    e[v].push_back(u);
    e[u].push_back(v);
  }
  vis[0] = n;
  dfs(0);
  printf("%d", max(f(0, 0), f(0, 1)));
  return 0;
}