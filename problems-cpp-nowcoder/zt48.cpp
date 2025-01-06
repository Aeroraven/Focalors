#include <cstring>
#include <iostream>

using namespace std;

char c[200001];
int main() {
  int q;
  cin >> q;
  while (q--) {
    scanf("%s", c);
    int n = strlen(c);
    if (n & 1) {
      printf("Yes\n");
    } else {
      int n1 = 0, n0 = 0;
      for (int i = 0; i < n; i++) {
        n1 += c[i] == '1';
        n0 += c[i] == '0';
      }
      if ((n1 & 1) && (n0 & 1)) {
        printf("No\n");
      } else {
        printf("Yes\n");
      }
    }
  }
}

// 1010 => 1100