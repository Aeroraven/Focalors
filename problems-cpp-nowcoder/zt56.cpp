#include <iostream>
using namespace std;

int w[2000], v[2000], f[2000];
int main() {
  int t;
  scanf("%d", &t);
  while (t--) {
    int n, m;
    scanf("%d %d", &n, &m);
    for (int i = 0; i < n; i++) {
      scanf("%d %d", w + i, v + i);
    }
    for (int i = 0; i <= m; i++) {
      if (i >= w[0]) {
        f[i] = f[i - w[0]] + v[0];
      } else {
        f[i] = 0;
      }
    }
    for (int i = 0; i < n; i++) {
      for (int j = 0; j <= m; j++) {
        if (j >= w[i]) {
          f[j] = max(f[j], f[j - w[i]] + v[i]);
        }
      }
    }
    int ans = 0;
    for (int i = 0; i <= m; i++) {
      ans = max(ans, f[i]);
    }
    printf("%d\n", ans);
  }
  // f[i][j] = max(f[i-1][j],f[i-1][j-k*c[i]]+k*v[i])
}
// 64 位输出请用 printf("%lld")