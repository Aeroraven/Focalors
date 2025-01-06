#include <iostream>
using namespace std;

int main() {
  unsigned no = 0, ne = 0, n = 0;
  scanf("%u", &n);
  for (unsigned i = 0; i < n; i++) {
    unsigned a;
    scanf("%u", &a);
    auto q = a & 1;
    no += q;
    ne += 1 - q;
    if ((no >= 3) || (no >= 1 && ne >= 2)) {
      printf("YES");
      return 0;
    }
  }
  printf("NO");
  return 0;
}
// 64 位输出请用 printf("%lld")