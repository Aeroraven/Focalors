#include <iostream>
using namespace std;

int main() {
  int n;
  scanf("%d", &n);
  int mal = 0, lsv = 0, cmal = 0;
  scanf("%d", &lsv);
  mal = 1, cmal = 1;
  for (int i = 1; i < n; i++) {
    int p;
    scanf("%d", &p);
    auto diff = p - lsv;
    if (diff <= 1 && diff >= -1) {
      cmal++;
    } else {
      cmal = 1;
    }
    lsv = p;
    mal = max(cmal, mal);
  }
  printf("%d", mal);
}
// 64 位输出请用 printf("%lld")