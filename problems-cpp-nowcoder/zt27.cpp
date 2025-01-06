#include <cstdio>
#include <iostream>
#include <unordered_map>

using namespace std;

int main() {
  int n, k;
  using ll = long long;
  unordered_map<long long, int> x;
  x[0] = -1;
  scanf("%d %d", &n, &k);
  int ans = -1;
  ll tsum = 0;
  for (int i = 0; i < n; i++) {
    int a;
    scanf("%d", &a);
    tsum += (a - k);
    ll v = tsum;
    if (x.count(v)) {
      ans = max(ans, i - x[v]);
    } else {
      x[v] = i;
    }
  }
  printf("%d", ans);
  return 0;
}

// A[I]-A[J]=(I-J)*K
// A[I]-IK=A[J]-JK