#include <iostream>
using namespace std;

int c[100001], mav, mc;
int main() {
  int n;
  scanf("%d", &n);
  for (int i = 0; i < n; i++) {
    int a = 0;
    scanf("%d", &a);
    auto q = ++c[a];
    if (q > mc) {
      mc = q;
      mav = a;
    }
  }
  printf("%d", mc + (n != mc));
}