#include <iostream>
#include <set>
using namespace std;

int main() {
  int x, y, n;
  scanf("%d %d %d", &x, &y, &n);
  long long w = x;
  set<int, greater<>> p;
  for (int i = 0; i < n; i++) {
    int v;
    scanf("%d", &v);
    p.insert(v);
  }
  if (w >= y) {
    printf("0");
    return 0;
  }
  int cnt = 0;
  for (auto el : p) {
    cnt++;
    w *= el;
    if (w >= y) {
      printf("%d", cnt);
      return 0;
    }
  }
  printf("-1");
}
// 64 位输出请用 printf("%lld")