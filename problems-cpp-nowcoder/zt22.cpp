#include <iostream>
using namespace std;

long long d[100001];
int main() {
  int n;
  cin >> n;
  long long sp = 0;
  for (int i = 0; i < n; i++) {
    long long v;
    cin >> v;
    sp += v;
    d[i] = sp;
  }
  int x, y;
  cin >> x >> y;
  if (y < x) {
    int t = x;
    x = y;
    y = t;
  }
  x--;
  y--;
  if (x == y)
    cout << 0;
  else {
    y--;
    long long lx = (x - 1 == -1) ? 0 : d[x - 1];
    long long a1 = d[y] - lx;
    long long a2 = sp - a1;
    cout << min(a1, a2);
  }
}
// 64 位输出请用 printf("%lld")