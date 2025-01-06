#include <cmath>
#include <iostream>

using namespace std;

inline bool test(int x) {
  int ub = sqrt(x) + 2;
  int nps = 0, lb = 2;
  while (x > 1) {
    while (!(x % lb)) {
      x /= lb;
      nps++;
    }
    lb++;
    if (lb >= ub)
      break;
  }
  if (x > 1)
    nps++;
  return nps & 1;
}
int main() {
  int t;
  scanf("%d", &t);
  while (t--) {
    int x;
    scanf("%d", &x);
    if (test(x)) {
      printf("kou\n");
    } else {
      printf("yukari\n");
    }
  }
}
// 30 = 2x3x5