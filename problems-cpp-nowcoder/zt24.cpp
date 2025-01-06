#include <iostream>
using namespace std;

using ll = long long;
ll v[100001];
int main() {
  int n, m;
  cin >> n >> m;
  for (int i = 0; i < n; i++) {
    ll k, c;
    cin >> k >> c;
    ll pc = (c + k - 1) / k;
    for (int j = 0; j < k - 1; j++) {
      int a = 0;
      cin >> a;
      a--;
      v[a] += pc;
    }
  }
  for (int i = 0; i < m; i++) {
    cout << v[i] << " ";
  }
}
// 64 位输出请用 printf("%lld")