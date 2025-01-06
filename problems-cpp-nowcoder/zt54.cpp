#include <iostream>
using namespace std;

int a[200006];
int main() {
  int n;
  scanf("%d", &n);
  for (int i = 0; i < n; i++) {
    scanf("%d", a + i);
  }

  int minChance = 0x7fffffff;
  // case1. killing consecutive
  for (int i = 1; i < n - 1; i++) {
    int sec = a[i + 1];
    int fir = a[i];
    int c1 = (sec + 1) / 2;
    fir = max(0, fir - c1);
    int c2 = (fir + 1) / 2;
    minChance = min(minChance, c1 + c2);
  }
  // case1b. killing 1 & 2
  if (true) {
    int sec = a[1];
    int fir = a[0];
    int c1 = (sec + 1) / 2;
    fir = max(fir - c1, 0);
    minChance = min(minChance, c1 + fir);
  }
  // case2. killing 1 & ?
  for (int i = 2; i < n; i++) {
    int sec = a[i];
    int fir = a[0];
    int c1 = (sec + 1) / 2;
    minChance = min(minChance, c1 + fir);
  }

  // case3. killing a & b, non consecutive, a!=1
  if (n > 2) {
    for (int i = 0; i < n; i++) {
      a[i] = (a[i] + 1) >> 1;
    }
    int mpos = 1, mpos2 = 0;
    for (int i = 2; i < n; i++) {
      if (a[i] < a[mpos]) {
        mpos = i;
      }
    }
    for (int i = 1; i < n; i++) {
      if ((mpos2 == 0 || a[i] < a[mpos2]) && i != mpos) {
        mpos2 = i;
      }
    }
    minChance = min(minChance, a[mpos] + a[mpos2]);
  }

  printf("%d", minChance);
}
// 64 位输出请用 printf("%lld")