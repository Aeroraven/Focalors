#include <cmath>
#include <iostream>

using namespace std;

int solve(int x) {
  int ub = sqrt(x) + 2;
  int lf = 2;
  int nufs = 0, nws = 1, nws2 = 0;
  while (x > 1) {
    int nf = 0;
    while (!(x % lf)) {
      nf++;
      x /= lf;
    }
    lf++;
    if (nf != 0)
      nufs++;
    nws *= (1 + nf);
    nws2 = 2 * nf;
    if (lf >= ub)
      break;
  }
  if (x > 1) {
    nws *= 2;
    nws2 = 2;
    nufs++;
  }
  if (nufs == 1) {
    return nws2;
  }
  return nws;
}

int main() {
  int t;
  scanf("%d", &t);
  while (t--) {
    int v;
    scanf("%d", &v);
    printf("%d\n", solve(v));
  }
}

// 36: 1 2(2) 3(2) 4(3) 6(4) 9(3) 12(6) 18(6) 36 [9]
// 12: 1 2(2) 3(2) 4(3) 6(4) 12 [6]
// 18: 1 2(2) 3(2) 6(3) 9(3) 18 [6]

// 64: 1 2(2) 4(3) 8(4) 16 32 64 [7]
// 8: 1 2 4 8
// 16: 1 2 4 8 16 [5]
// 32: 1 2 4 8 16 32 [6]

// 36 = 2x2x3x3 => (1+2)x(1+2)=9
// 32 = 2x2x2x2x2 => (1+5)=6 | 2x5=10