#include <iostream>
using namespace std;

int main() {
  int n, r;
  cin >> n >> r;
  int d = (n - r);
  for (int i = 0; i < d; i++) {
    putchar('(');
    putchar(')');
  }
  for (int i = 0; i < r; i++) {
    putchar('(');
  }
  for (int i = 0; i < r; i++) {
    putchar(')');
  }
}
// 64 位输出请用 printf("%lld")