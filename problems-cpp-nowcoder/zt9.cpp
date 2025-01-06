#include <cstring>
#include <iostream>

using namespace std;

char s[2][1000001];
int len[2] = {0, 0};
int main() {
  int n, q;
  scanf("%d %d", &n, &q);
  scanf("%s", s[0]);
  len[0] = strlen(s[0]);
  for (int i = 0; i < q; i++) {
    int l, r;
    int o = 1 - (i & 1), c = i & 1;
    scanf("%d %d", &l, &r);
    l--, r--;
    len[o] = len[c] + (r - l + 1);
    int p = 0;
    for (int j = 0; j < l; j++) {
      s[o][p++] = s[c][j];
    }
    for (int j = l; j <= r; j++) {
      s[o][p++] = s[c][j];
      s[o][p++] = s[c][j];
    }
    for (int j = r + 1; j < len[c]; j++) {
      s[o][p++] = s[c][j];
    }
  }
  int x = q & 1;
  s[x][len[x]] = '\0';
  printf("%s", s[x]);
}
