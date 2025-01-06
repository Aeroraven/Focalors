#include <iostream>
using namespace std;

long long a[1000001], s;
int main() {
  int n, q;
  cin >> n >> q;
  for (int i = 0; i < n; i++) {
    int b;
    scanf("%d", &b);
    s += b;
    a[i] = s;
  }
  for (int i = 0; i < q; i++) {
    int l, r;
    scanf("%d %d", &l, &r);
    l--, r--;
    long long w = (l == 0) ? 0 : a[l - 1];
    printf("%lld\n", a[r] - w);
  }
}
// 64 位输出请用 printf("%lld")