#include <iostream>
using namespace std;

struct SegTree {
  long long a[100005 * 4];
  void build(long long *src, int l, int r, int id) {
    if (l == r) {
      a[id] = src[l];
      return;
    }
    int mid = (l + r) >> 1;
    build(src, l, mid, id * 2);
    build(src, mid + 1, r, id * 2 + 1);
    a[id] = a[id * 2] + a[id * 2 + 1];
  }
  void modify(int dest, long long val, int l, int r, int id) {
    if (l == r && l == dest) {
      a[id] = val;
      return;
    }
    if (dest >= l && dest <= r) {
      int mid = (l + r) >> 1;
      modify(dest, val, l, mid, id * 2);
      modify(dest, val, mid + 1, r, id * 2 + 1);
      a[id] = a[id * 2] + a[id * 2 + 1];
    }
  }
  long long query(int dL, int dR, int l, int r, int id) {
    if (l >= dL && r <= dR) {
      return a[id];
    }
    if (l > dR || r < dL) {
      return 0;
    }
    int mid = (l + r) >> 1;
    long long vl = query(dL, dR, l, mid, id * 2);
    long long vr = query(dL, dR, mid + 1, r, id * 2 + 1);
    return vl + vr;
  }
};

long long a[100001];
int main() {
  int n, q;
  cin >> n >> q;
  SegTree st;
  for (int i = 0; i < n; i++) {
    cin >> a[i];
  }
  st.build(a, 0, n - 1, 1);
  for (int i = 0; i < q; i++) {
    int o, l, r;
    cin >> o >> l >> r;
    if (o == 1) {
      l--;
      long long sx = a[l];
      sx += r;
      a[l] += r;
      st.modify(l, sx, 0, n - 1, 1);
    } else {
      l--, r--;
      long long res = st.query(l, r, 0, n - 1, 1);
      printf("%lld\n", res);
    }
  }
}
// 64 位输出请用 printf("%lld")