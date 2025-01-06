#include <iostream>
using namespace std;

using ll = long long;
int main() {
  ll p;
  int t;
  scanf("%d", &t);
  while (t--) {
    scanf("%lld", &p);
    auto s = p >> 1;
    if (p == 2) {
      printf("1 1\n");
    } else if (p & 1) {
      printf("%lld %lld\n", s, s + 1);
    } else {
      if (s & 1) {
        printf("%lld %lld\n", s - 2, s + 2);
      } else {
        printf("%lld %lld\n", s - 1, s + 1);
      }
    }
  }
}
// 64 位输出请用 printf("%lld")

// 6=>24,(15)
// 8=>35
// 10=>46,37