#include <iostream>
using namespace std;

int ans1, n;
int fm = 1;
int a[200000], b[200000];
#define MODF 1000000007
void mergeSort(int l, int r) {
  if (l == r)
    return;
  int mid = (l + r) / 2;
  mergeSort(l, mid);
  mergeSort(mid + 1, r);

  int cl = l, cr = mid + 1, cp = 0;
  while (cl <= mid && cr <= r) {
    if (a[cl] <= a[cr]) {
      b[cp++] = a[cl++];
    } else {
      ans1 += (mid - cl + 1);
      ans1 %= MODF;
      b[cp++] = a[cr++];
    }
  }
  while (cl <= mid)
    b[cp++] = a[cl++];
  while (cr <= r)
    b[cp++] = a[cr++];
  for (int i = 0; i < cp; i++) {
    a[l + i] = b[i];
  }
}

int main() {
  scanf("%d", &n);
  for (int i = 0; i < n; i++) {
    scanf("%d", a + i);
    if (i >= 2) {
      fm *= 2;
      fm %= (MODF);
    }
  }
  mergeSort(0, n - 1);
  long long ans = ans1;
  ans *= fm;
  int fq = ans % MODF;
  printf("%d", fq);
}
// 64 位输出请用 printf("%lld")