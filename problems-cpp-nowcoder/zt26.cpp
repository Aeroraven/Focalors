#include <iostream>
#include <unordered_set>
using namespace std;

int main() {
  int n, m;
  scanf("%d %d", &n, &m);
  unordered_set<int> st;
  int trace2 = -1, ts = 0, tt = 0;
  while (m--) {
    ts++;
    int op, v;
    scanf("%d %d", &op, &v);
    if (op == 1) {
      if (v == trace2) {
        printf("%d", ts);
        return 0;
      }
      if (st.count(v) == 0) {
        st.insert(v);
        tt++;
        if (tt == n) {
          printf("%d", ts);
          return 0;
        }
      }
    } else {
      if (st.count(v)) {
        printf("%d", ts);
        return 0;
      }
      if (trace2 != -1 && trace2 != v) {
        printf("%d", ts);
        return 0;
      }
      trace2 = v;
    }
  }
  printf("-1");
}
// 64 位输出请用 printf("%lld")