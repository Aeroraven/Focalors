#include <iostream>
using namespace std;

using ll = long long;

ll fpow(ll a, ll b, ll p) {
  ll r = 1, q = a;
  while (b) {
    if (b & 1) {
      r *= q;
      r %= p;
    }
    q *= q;
    q %= p;
    b >>= 1;
  }
  return r % p;
}

int main() {
  int t;
  cin >> t;
  for (int i = 0; i < t; i++) {
    ll a, b, p;
    cin >> a >> b >> p;
    cout << fpow(a, b, p) << endl;
  }
}
// 64 位输出请用 printf("%lld")