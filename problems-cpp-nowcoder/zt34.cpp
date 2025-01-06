#include <iostream>
using namespace std;

using ll = long long;

void lfct(ll xf, ll xv, ll n, ll &mi, ll &by, ll &bx) {
  long double dy = n / (xf - (long double)1.0);
  dy = max(dy, (long double)(0.0));
  ll ds = max(1ll, ll(dy));
  ll ds2 = ds + 1;
  if (ds2 == 2)
    ds2++;
  if (ds == 2)
    ds--;
  ll v1;
  v1 = abs(xf * ds - ds - n);
  ll v2;
  v2 = abs(xf * (ds2) - (ds2)-n);

  if (v2 < mi) {
    mi = v2;
    by = ds2;
    bx = xv;
  }
  if (v1 < mi) {
    mi = v1;
    by = ds;
    bx = xv;
  }
}

int main() {
  ll n;
  ll xf = 2;
  cin >> n;
  ll mi = 1 + n, by = 1, bx = 1;

  for (int i = 3; i <= 13; i++) {
    xf *= i;
    lfct(xf, i, n, mi, by, bx);
  }
  printf("%lld %lld", bx, by);
}
// 120*10-10