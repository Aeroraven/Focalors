#include <cstdio>

inline void write(unsigned x) {
  if (x > 9)
    write(x / 10);
  putchar((x % 10) + '0');
}

int main() {
  unsigned n;
  scanf("%u", &n);
  if (n < 3) {
    printf("-1\n");
  } else [[likely]] {
    unsigned r = n & 1;
    unsigned f = n + r - 1;
    write(f--);
    for (unsigned i = f; i; i--) {
      putchar(' ');
      write(i);
    }
    if (!r) {
      putchar(' ');
      write(n);
    }
    putchar('\n');
  }
  return 0;
}