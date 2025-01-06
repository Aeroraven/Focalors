#include <iostream>
#include <linux/limits.h>
using namespace std;

using ll = long long;
int n, l, r;
ll k[600001], a[600001], b;

inline ll f(int x) {
  long long v = 0;
  for (int i = 0; i < n; i++) {
    v += abs(k[i] * x + a[i]);
  }
  return v;
};
int main() {
  int T;
  scanf("%d", &T);
  while (T--) {
    b = 0;
    scanf("%d %d %d", &n, &l, &r);
    for (int i = 0; i < n; i++) {
      int sb;
      scanf("%lld %lld %d", k + i, a + i, &sb);
      b += sb;
    }
    while (l < r) {
      int mid = l + (r - l) / 3;
      int rmid = r - (r - l) / 3;
      auto midv = f(mid);
      auto rmidv = f(rmid);
      if (midv == rmidv) {
        l = mid + 1;
        r = rmid - 1;
      } else if (midv < rmidv) {
        r = rmid - 1;
      } else {
        l = mid + 1;
      }
    }
    ll ans = f(l) + b;
    printf("%lld\n", ans);
  }
}
// 64 位输出请用 printf("%lld")