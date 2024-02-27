#include <iostream>
#include <cstring>
using namespace std;

class Solution {
public:
    int rearrangeSticks(int n, int k) {
        constexpr static const int MOD = 1000000007;
        // Let f[i,j] denote the answer "Arrange i sticks, where j sticks are visible from the left"
        // Then F[i,j]=C[i-1,0]A[0]F[i-1,j-1]+C[i-1,1]A[1]F[i-2,j-1]+...+C[i-1,i-1]A[i-1]F[0,j-1]
        // => F[i,j] = A[i-1,0]F[i-1,j-1]+A[i-1,1]F[i-1,1]+...+A[i-1,i-2]F[1,j-1]
        // => F[i,j] = F[i-1,j-1] + (i-1){A[i-2,0]F[i-2,1]+...+A[i-2,i-3]F[1,j-1]}
        // => F[i,j] = F[i-1,j-1] + (i-1)F[i-1,j]

        int f[2][1000];
        memset(f, 0, sizeof(f));
        f[1][1] = 1;
        for (int i = 2; i <= n; i++) {
            for (int j = 1; j <= min(i, k); j++) {
                f[i % 2][j] = f[(i + 1) % 2][j - 1];
                f[i % 2][j] = (f[i % 2][j] + ((long long)(i - 1) * f[(i + 1) % 2][j])) % MOD;
            }
        }
        return f[n % 2][k];
    }
};

int main() {
    Solution s;
    while (true) {
        int n, k;
        cin >> n >> k;
        cout << s.rearrangeSticks(n, k) << endl;
    }
    return 0;
}