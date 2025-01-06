#include <algorithm>
#include <cstdio>
#include <iostream>

using namespace std;

using ll = long long;
int n;
ll k;
struct Fr {
  int a, b;
  bool operator<(const Fr &p) const { return a < p.a; }
};
Fr x[200001];

inline bool bin(ll mx, int th) {
  int l = 0, r = -1;
  ll fun = 0;
  while (r < n) {
    r++;
    while (x[r].a - x[l].a > th) {
      fun -= x[l].b;
      l++;
    }
    fun += x[r].b;
    if (fun >= mx) {
      return true;
    }
  }
  return false;
}

int main() {
  scanf("%d %lld", &n, &k);
  ll tot = 0;
  for (int i = 0; i < n; i++) {
    scanf("%d", &x[i].a);
  }
  for (int i = 0; i < n; i++) {
    scanf("%d", &x[i].b);
    tot += x[i].b;
  }
  if (tot < k) {
    printf("-1");
    return 0;
  }
  sort(x, x + n);
  int l = 0, r = x[n - 1].a - x[0].a;
  while (l < r) {
    int mid = (l + r) / 2;
    bool bv = bin(k, mid);
    if (bv) {
      r = mid;
    } else {
      l = mid + 1;
    }
  }
  printf("%d", l);
}
// 64 位输出请用 printf("%lld")