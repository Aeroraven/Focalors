#include <iostream>
using namespace std;

char a[100001];
int b[100001], c[100001];
int uq, sm, n;
int main() {
  cin >> n;
  scanf("%s", a);
  for (int i = 0; i < n; i++) {
    if (a[i] == '0')
      b[i] = i;
    else {
      c[uq++] = i;
    }
  }
  if (uq <= 1) {
    b[c[0]] = c[0];
  } else {
    for (int i = 0; i < uq; i++) {
      b[c[i]] = c[(i + 1) % uq];
    }
  }
  for (int i = 0; i < n; i++) {
    printf("%d ", b[i] + 1);
  }
}
// 64 位输出请用 printf("%lld")