#include <cstring>
#include <iostream>

using namespace std;

char x[2001];
int n;
int main() {
  int t;
  scanf("%d\n", &t);
  for (int i = 0; i < t; i++) {
    scanf("%s", x);
    n = strlen(x);
    int sum = 0;
    for (int i = 0; i < n; i++) {
      auto s = x[i] - '0';
      sum += s;
    }
    int dpos = -1;
    if (sum % 3 == 0) {
      dpos = -2;
    } else {
      for (int i = n - 1; i >= 0; i--) {
        if ((sum - (x[i] - '0')) % 3 == 0) {
          dpos = i;
          break;
        }
      }
    }

    if (dpos == -1) {
      printf("0\n");
    } else {
      bool ilz = (dpos == 0);
      int lzs = 0, rms = (dpos != -2);
      for (int i = (dpos == 0); i < n; i++) {
        if (x[i] == '0' && ilz)
          lzs++;
        else {
          if (x[i] == '3' || x[i] == '6' || x[i] == '9') {
            rms++;
            ilz = false;
          } else if (x[i] == '0') {
            rms++;
          }
        }
      }
      int maxd = min(n - 1, n - lzs - (dpos != -2));
      rms = min(rms, maxd);
      printf("%d\n", rms);
    }
  }
}