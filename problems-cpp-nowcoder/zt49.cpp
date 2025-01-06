#include <cstdio>
#include <cstring>

using namespace std;

int f[10000];
char c[4000];
#define MODF 1000000007
int main() {
  // f[i][j] => first i chars, with j unmatched left brackets
  //  for ?: f[i][j]=f[i-1][j+1]+f[i-1][j-1]
  //  for (: f[i][j]=f[i-1][j-1]
#define S(i, j) ((((i) + 2) & 1) * 2048 + (j))
  scanf("%s", c);
  int n = strlen(c);
  if (n & 1) {
    printf("0");
  }
  int mab = n >> 1;
  f[S(1, 0)] = 1;
  for (int i = 0; i < n; i++) {
    auto ch = c[i];
    if (ch == '?') {
      for (int j = 0; j <= mab; j++) {
        f[S(i, j)] = f[S(i - 1, j + 1)];
        if (j - 1 >= 0) {
          f[S(i, j)] += f[S(i - 1, j - 1)];
          f[S(i, j)] %= MODF;
        }
      }
    } else if (ch == '(') {
      for (int j = 0; j <= mab; j++) {
        f[S(i, j)] = f[S(i - 1, j - 1)];
      }
    } else if (ch == ')') {
      for (int j = 0; j <= mab; j++) {
        f[S(i, j)] = f[S(i - 1, j + 1)];
      }
    }
  }
  printf("%d", f[S(n - 1, 0)]);
}
// 2,1 => <<> / <><
// 2,3 => <<<
// 3,2 => <><< / <<<> / <<><
// 3,0 => <><> / <<>>
// 4,1 => <><<> / <<<>> / <<><> / <><>< / <<>><
// 5,0 => <><<>> / <<<>>> /<<><>>/ <><><> / <<>><>
