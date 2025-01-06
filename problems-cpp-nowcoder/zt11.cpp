#include <iostream>
using namespace std;

char v[1025];
int main() {
  int n;
  scanf("%d", &n);
  int b = 1 << n;
  int c = 0, d = 0;
  for (int i = 0; i < b; i++) {
    scanf("%s", v);
    for (int j = 0; j < b; j++) {
      d = (d << 1) + (v[j] == '#');
      c++;
      if (c == 4) {
        printf("%d ", d);
        d = 0;
        c = 0;
      }
    }
  }
}