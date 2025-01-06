#include <array>
#include <climits>
#include <cstdint>
#include <iostream>

using namespace std;

// f[i][s]=max(f[i-len][t])+w[i]
using ll = long long;
int n;
ll vf[200000 * 16];
int a[200000];

std::array<int, 8> lut[4] = {
    {0b0000, 0b0010, 0b0100, 0b0110, 0b1000, 0b1010, 0b1100, 0b1110},
    {0b0000, 0b0001, 0b0100, 0b0101, 0b1000, 0b1001, 0b1100, 0b1101},
    {0b0000, 0b0001, 0b0010, 0b0011, 0b1000, 0b1001, 0b1010, 0b1011},
    {0b0000, 0b0001, 0b0010, 0b0011, 0b0100, 0b0101, 0b0110, 0b0111}};

#define f(i, j) vf[(i)*16 + (j)]
int main() {
  scanf("%d", &n);
  for (int i = 1; i <= n; i++) {
    scanf("%d", a + i);
  }

  for (int i = 0; i < 16; i++) {
    f(0, i) = -INT64_MAX;
  }
  f(0, 0) = 0;

  for (int i = 1; i <= n; i++) {
    // using card k
    for (int j = 0; j < 16; j++) {
      f(i, j) = -INT64_MAX;
    }
    for (int k = 0; k < 4; k++) {
      int prev = i - k - 1;
      if (prev < 0)
        break;
      for (int j = 0; j < 8; j++) {
        int lastStat = lut[k][j];
        int newStat = lastStat | (1 << k);
        f(i, newStat) = max(f(i, newStat), f(prev, lastStat));
      }
    }
    for (int j = 0; j < 16; j++) {
      if (f(i, j) != -INT64_MAX) {
        f(i, j) += a[i];
        if (f(i, j) < 0) {
          f(i, j) = -INT64_MAX;
        }
      }
    }
    f(i, 0) = f(i, 0b1111);
  }
  ll ans = -1;
  for (int i = 0; i < 16; i++) {
    ans = max(ans, f(n, i));
  }
  printf("%lld", ans);
}
// 64 位输出请用 printf("%lld")