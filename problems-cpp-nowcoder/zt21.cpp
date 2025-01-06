#include <algorithm>
#include <iostream>

using namespace std;

struct El {
  int pos;
  int val;
  const bool operator<(const El &p) const { return pos < p.pos; }
};
int a[200001];
El w[400003];
int main() {
  int n, m;
  cin >> n >> m;
  for (int i = 0; i < n; i++) {
    cin >> a[i];
  }
  for (int i = 0; i < m; i++) {
    int l, r, v;
    cin >> l >> r >> v;
    l--;
    w[i * 2].pos = l;
    w[i * 2].val = v;
    w[i * 2 + 1].pos = r;
    w[i * 2 + 1].val = -v;
  }
  sort(w, w + 2 * m);
  long long acc = 0;
  int p = 0;
  for (int i = 0; i < n; i++) {
    while (p < 2 * m && w[p].pos <= i) {
      acc += w[p].val;
      p++;
    }
    printf("%lld ", a[i] + acc);
  }
}
// 64 位输出请用 printf("%lld")