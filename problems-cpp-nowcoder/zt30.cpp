#include <math.h>
#include <stdio.h>
int main() {
  int v0, x, y;
  scanf("%d %d %d", &v0, &x, &y);
  double l = 0, r = 1e10;
  double f = sqrt(1.0 * y * x);
  double t1 = fmax((f - v0) / x, 0.0);
  double ans = t1 + (y / (v0 + t1 * x));
  printf("%.10lf", ans);
}