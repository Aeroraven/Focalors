#include <iostream>
using namespace std;

int main() {
  int t;
  scanf("%d", &t);
  while (t--) {
    unsigned n, l, r;
    unsigned long long mai = 0, mad = 0, mii = 0, mid = 0;
    scanf("%u %u %u", &n, &l, &r);
    while (n--) {
      unsigned v;
      scanf("%d", &v);
      if (v >= r) {
        mid += (v - r); //[3,5] 6 => 5
        mad += (v - l); //[3,5] 6 => 5 4 3
      } else if (v <= l) {
        mii += (l - v);
        mai += (r - v);
      } else {
        mai += (r - v);
        mad += (v - l);
      }
    }
    if (mid > mai || mii > mad)
      printf("-1\n");
    else
      printf("%lld\n", max(mid, mii));
  }
}
// 64 位输出请用 printf("%lld")