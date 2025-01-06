#include <cstdint>
#include <iostream>
using namespace std;

using ll = long long;
ll a[1000001], rsum[1001], csum[1001];
int main() {
  int n, m;
  cin >> n >> m;
#define G(i, j) ((i) * (m) + (j))
  // rows
  ll asum = 0;
  for (int i = 0; i < n; i++) {
    ll sum = 0;
    for (int j = 0; j < m; j++) {
      cin >> a[G(i, j)];
      sum += a[G(i, j)];
    }
    asum += sum;
    rsum[i] = asum;
  }

  // cols
  asum = 0;
  for (int i = 0; i < m; i++) {
    ll sum = 0;
    for (int j = 0; j < n; j++) {
      sum += a[G(j, i)];
    }
    asum += sum;
    csum[i] = asum;
  }

  long long maxv = INT64_MAX;
  for (int i = 0; i < n - 1; i++) {
    long long r = rsum[n - 1] - rsum[i];
    long long l = rsum[i];
    maxv = min(abs(r - l), maxv);
  }
  for (int i = 0; i < m - 1; i++) {
    long long r = csum[m - 1] - csum[i];
    long long l = csum[i];
    maxv = min(abs(r - l), maxv);
  }
  cout << maxv;
}
// 64 位输出请用 printf("%lld")