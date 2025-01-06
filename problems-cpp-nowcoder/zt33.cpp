#include <algorithm>
#include <cmath>
#include <iomanip>
#include <iostream>

using namespace std;

struct Point {
  long long dist;
  long long v;
  bool operator<(const Point &p) const { return dist < p.dist; }
};
Point pt[100002];
int main() {
  int n;
  long long x;
  cin >> n >> x;
  for (int i = 0; i < n; i++) {
    long long a, b, v;
    cin >> a >> b >> pt[i].v;
    pt[i].dist = (a * a + b * b);
  }
  sort(pt, pt + n);
  long long ds = 0;
  for (int i = 0; i < n; i++) {
    ds += pt[i].v;
    if (ds >= x) {
      cout << setprecision(10) << sqrt(pt[i].dist);
      return 0;
    }
  }
  cout << -1;
}
// 64 位输出请用 printf("%lld")