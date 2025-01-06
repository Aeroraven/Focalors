#include <stdio.h>

int main() {
  unsigned q;
  scanf("%u", &q);
  while (q--) {
    unsigned m, x;
    scanf("%u %u", &m, &x);
    x--;
    printf("%u\n", x % m + 1);
  }
}
// 64 位输出请用 printf("%lld")