#include <stdio.h>
#include <string.h>

char w[200001], b[200001];
inline void process(char *w) {
  unsigned l = 0, r = 0, len = 0;
  char s = w[l], v = s, e = w[0];
  while (s) {
    while (s == v) {
      v = w[++r];
      if (!v) {
        if (!l) {
          printf("-1");
          return;
        }
        len = r;
        r = 0;
        v = e;
      }
    }
    unsigned ma = (r > len) ? r : len;
    while (l < ma)
      b[l++] = v;
    s = w[l];
  }
  b[len] = '\0';
  printf("%s", b);
}
int main() {
  scanf("%s", w);
  process(w);
  return 0;
}