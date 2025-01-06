#include <stdio.h>

int main() {
  unsigned n, d = 0;
  scanf("%u", &n);
  while (n) {
    if (n & 1) {
      putchar('a' + d);
    }
    d++;
    n >>= 1;
  }
  return 0;
}
