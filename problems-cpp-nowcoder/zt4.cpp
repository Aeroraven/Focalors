#include <iostream>
#include <string>
using namespace std;

int main() {
  string w;
  cin >> w;
  auto len = w.length() - 1;
  if (!len) {
    printf("0");
    return 0;
  }
  auto last = (w[len] - '0') & 1;
  auto ans = 0;
  for (unsigned i = 0; i < len; i++) {
    auto p = (w[i] - '0') & 1;
    ans += !(p ^ last);
  }
  printf("%d", ans);
}
