#include <iostream>
using namespace std;

long long s[500005];

int main() {
  int n, m, q;
  cin >> n >> m >> q;
  long long ps = 0;
#define GID(x, y) ((x) * (m) + (y))
  for (int i = 0; i < n; i++) {
    ps = 0;
    for (int j = 0; j < m; j++) {
      int a = 0;
      cin >> a;
      ps += a;
      if (i == 0 && j == 0) {
        s[GID(i, j)] = a;
      } else if (i == 0) {
        s[GID(i, j)] = ps;
      } else {
        s[GID(i, j)] = s[GID(i - 1, j)] + ps;
      }
    }
  }

  for (int i = 0; i < q; i++) {
    int lr, lc, rr, rc;
    cin >> lr >> lc >> rr >> rc;
    lr--, lc--, rr--, rc--;

    long long pw1 = 0, pw2 = 0, plt = 0, prt = 0;
    prt = s[GID(rr, rc)];
    if (lr > 0) {
      pw2 = s[GID(lr - 1, rc)];
    }
    if (lc > 0) {
      pw1 = s[GID(rr, lc - 1)];
    }
    if (lr > 0 && lc > 0) {
      plt = s[GID(lr - 1, lc - 1)];
    }
    long long ans = (prt + plt - pw1 - pw2);
    printf("%lld\n", ans);
  }
}
// 64 位输出请用 printf("%lld")