#include <cstring>
#include <iostream>
#include <queue>

using namespace std;

int n, m;
int w[4000], v[4000], s[5000];
using ll = long long;
ll f[6000];
ll qub[4000], quv[4000];
int qul = 0, qur = -1;

int main() {
  int t;
  scanf("%d", &t);
  while (t--) {
    memset(f, 0, sizeof(f));
    scanf("%d %d", &n, &m);
    for (int i = 0; i < n; i++) {
      scanf("%d %d %d", w + i, v + i, s + i);
    }
    // start!
    for (int i = 0; i < n; i++) {
      if (v[i] == 0)
        continue;
      if (w[i] == 0) {
        for (int j = m; j >= 0; j--) {
          f[j] += s[i] * v[i];
        }
        continue;
      }
      // f[i][j] = max(f[i][j],f[i-1][j-w[i]*k]+v[i]*k)
      for (int j = 0; j < w[i]; j++) {
        qul = 0;
        qur = -1;
        for (int k = 0, kid = 0; k <= m; k += w[i], kid++) {
          int cap = j + k;
          ll raw = f[cap];
          while (qur >= qul && kid - qub[qul] > s[i])
            qul++;

          // quv = f[i-1][?]-id*v
          if (qur >= qul)
            f[cap] = max(f[cap], quv[qul] + (kid)*v[i]);

          auto kel = raw - kid * v[i];
          while (qur >= qul) {
            if (kel >= quv[qur])
              qur--;
            else
              break;
          }
          quv[++qur] = kel;
          qub[qur] = kid;
        }
      }
    }
    ll ans = 0;
    for (int i = 0; i <= m; i++) {
      ans = max(ans, f[i]);
    }
    printf("%lld\n", ans);
  }
}
// 64 位输出请用 printf("%lld")