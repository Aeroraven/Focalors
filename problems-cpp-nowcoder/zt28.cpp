#include <iostream>
using namespace std;

int a[200000];
int lbound1(int l, int r, int x) {
  int xr = r;
  while (l < r) {
    int mid = (l + r) / 2;
    if (a[mid] >= x) {
      r = mid;
    } else {
      l = mid + 1;
    }
  }
  if (l > xr || a[l] < x)
    return -1;
  return a[l];
}
int ubound1(int l, int r, int x) {
  int xr = r;
  while (l < r) {
    int mid = (l + r) / 2;
    if (a[mid] > x) {
      r = mid;
    } else {
      l = mid + 1;
    }
  }
  if (l > xr || a[l] <= x)
    return -1;
  return a[l];
}
int lbound2(int l, int r, int x) {
  int xl = l;
  while (l < r) {
    int mid = (l + r + 1) / 2;
    if (a[mid] < x) {
      l = mid;
    } else {
      r = mid - 1;
    }
  }
  if (r < xl || a[r] >= x)
    return -1;
  return a[l];
}
int ubound2(int l, int r, int x) {
  int xl = l;
  while (l < r) {
    int mid = (l + r + 1) / 2;
    if (a[mid] <= x) {
      l = mid;
    } else {
      r = mid - 1;
    }
  }
  if (r < xl || a[r] > x)
    return -1;
  return a[r];
}

int main() {
  int n, q;
  scanf("%d %d", &n, &q);
  for (int i = 0; i < n; i++) {
    scanf("%d", a + i);
  }
  while (q--) {
    int op, l, r, x;
    scanf("%d %d %d %d", &op, &l, &r, &x);
    r--;
    if (op == 1) {
      printf("%d\n", lbound1(l, r, x));
    } else if (op == 2) {
      printf("%d\n", ubound1(l, r, x));
    } else if (op == 3) {
      printf("%d\n", lbound2(l, r, x));
    } else if (op == 4) {
      printf("%d\n", ubound2(l, r, x));
    }
  }
}
// 64 位输出请用 printf("%lld")