#include <iostream>
using namespace std;

int main() {
  unsigned t = 0;
  scanf("%d", &t);
  while (t--) {
    int a, b;
    scanf("%d %d", &a, &b);
    if (a == b) {
      if (a == 0)
        printf("1 1\n");
      else
        printf("-1 -1\n");
    } else {
      if (a > b) {
        printf("%d %d\n", a, a + b + (b ? 0 : a));
      } else {
        printf("%d %d\n", a + b + (a ? 0 : b), b);
      }
    }
  }
}
// 64 位输出请用 printf("%lld")