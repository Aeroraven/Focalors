#include <iostream>
using namespace std;

bool isg(unsigned x) {
  int a = x % 10;
  x /= 10;
  int b = x % 10;
  x /= 10;
  int c = x % 10;
  x /= 10;
  int d = x % 10;
  x /= 10;
  int e = x % 10;
  x /= 10;
  if (a == b || a == c || a == d || a == e || b == c || b == d || b == e ||
      c == d || c == e || d == e)
    return false;
  return true;
}

int main() {
  int n;
  scanf("%d", &n);
  int cw = 0;
  for (int i = 98765; i >= 999; i--) {
    if (isg(i))
      cw++;
    if (cw == n) {
      if (i < 10000) {
        putchar('0');
      }
      printf("%d", i);
      return 0;
    }
  }
}