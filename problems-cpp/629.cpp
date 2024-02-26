#include <iostream>
#include <cstring>
using namespace std;

class Solution {
public:
    int kInversePairs(int n, int k) {
        int f[2][1001];
        int g[2][1001];
        const int modf = 1000000007;
        memset(f, 0, sizeof(f));
        memset(g, 0, sizeof(g));
        f[1][0] = 1;
        for (int j = 0; j <= k; j++) {
            g[1][j] = 1;
        }
        for (int i = 2; i <= n; i++) {
            for (int j = 0; j <= k; j++) {
                f[i % 2][j] = 0;
                int prec = std::max(-1, j - i);
                f[i % 2][j] = g[(i + 1) % 2][j];
                if (prec > -1) {
                    f[i % 2][j] -= g[(i + 1) % 2][prec];
                    f[i % 2][j] += modf;
                    f[i % 2][j] %= modf;
                }

                if (j == 0) {
                    g[i % 2][j] = f[i % 2][j];
                }
                else {
                    g[i % 2][j] = g[i % 2][j - 1] + f[i % 2][j];
                    g[i % 2][j] %= modf;
                }
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
        cout << s.kInversePairs(n, k) << endl;
    }
    return 0;
}