#include <climits>
#include <iostream>
using namespace std;

int ps[800];
long long vf[1024 * 1024];
inline long long sum(int l, int r) { return ps[r] - ((l > 0) ? ps[l - 1] : 0); }

#define f(i, j) vf[(i)*1024 + (j)]
int main() {
  int n, pr = 0;
  scanf("%d", &n);
  for (int i = 0; i < n; i++) {
    int v;
    scanf("%d", &v);
    pr += v;
    ps[i] = pr;
  }
  for (int x = 1; x < n; x++) {
    for (int l = 0; l < n - x; l++) {
      int r = l + x;
      long long sm = sum(l, r);
      f(l, r) = f(l, l) + f(l + 1, r);
      for (int j = l + 1; j < r; j++) {
        f(l, r) = min(f(l, r), f(l, j) + f(j + 1, r));
      }
      f(l, r) += sm;
    }
  }
  printf("%lld\n", f(0, n - 1));
}
// 64 位输出请用 printf("%lld")