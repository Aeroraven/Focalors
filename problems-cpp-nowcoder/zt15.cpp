#include <iostream>
using namespace std;

int a[201];
int main() {
  int n, q;
  cin >> n >> q;
  for (int i = 0; i < n; i++) {
    scanf("%d", &a[i]);
  }
  for (int i = 0; i < q; i++) {
    int o, l, r;
    cin >> o >> l >> r;
    if (o == 1) {
      a[l - 1] = r;
    } else {
      int t = 0;
      for (int j = 0; j < l; j++) {
        t += (a[j] == r);
      }
      printf("%d\n", t);
    }
  }
}
// 64 位输出请用 printf("%lld")