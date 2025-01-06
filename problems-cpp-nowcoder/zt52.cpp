#include <cstring>
#include <iostream>

using namespace std;

int cnt[26];
char p[200001];
int main() {
  scanf("%s", p);
  int n = strlen(p);
  int ans = 1;
  // 2^(cnt[k]-1)
  for (int i = 0; i < n; i++) {
    cnt[p[i] - 'a']++;
    if (cnt[p[i] - 'a'] >= 2) {
      ans *= 2;
      ans %= (1000000007);
    }
  }
  ans = (ans - 1 + 1000000007) % 1000000007;
  printf("%d", ans);
}
// 64 位输出请用 printf("%lld")