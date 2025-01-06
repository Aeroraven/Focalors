#include <iostream>
using namespace std;

int cf(unsigned x, unsigned y) {
  while (x != y) {
    if (x > y)
      x /= 2;
    else if (x < y)
      y /= 2;
  }
  return x;
}
int lg2(unsigned x) {
  if (x == 1)
    return 0;
  return lg2(x / 2) + 1;
}

int v[100001];
int main() {
  int a = 0, n = 0;
  scanf("%d", &n);
  int cd = 0;
  for (int i = 0; i < n; i++) {
    scanf("%d", v + i);
    if (i == 0)
      cd = v[0];
    else
      cd = cf(cd, v[i]);
  }
  for (int i = 0; i < n; i++) {
    int div = v[i] / cd;
    a += lg2(div);
  }
  printf("%d", a);
}