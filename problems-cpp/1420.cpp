#include <iostream>
#include <cstring>
using namespace std;
class Solution {
public:
    int f[2][51][101];
    int g[2][51][101];

    int numOfArrays(int n, int m, int k) {
        // F(i,j,k) denotes number of combinations that place first i numbers
        // with j chances used , with the numebr k as the current largest number

        const int modf = 1000000007;
        memset(f, 0, sizeof(f));
        memset(g, 0, sizeof(g));

        for (int i = 1; i <= m; i++) {
            f[0][1][i] = 1;
            g[0][1][i] = g[0][1][i - 1] + 1;
        }
        for (int i = 1; i < n; i++) {
            for (int j = 1; j <= k; j++) {
                g[i % 2][j][0] = 0;
                for (int s = 1; s <= m; s++) {
                    f[i % 2][j][s] = (((long long)f[(i + 1) % 2][j][s]) * s) % modf;
                    f[i % 2][j][s] += g[(i + 1)%2][j - 1][s - 1];
                    f[i % 2][j][s] %= modf;
                    g[i % 2][j][s] = g[i%2][j][s - 1] + f[i%2][j][s];
                    g[i % 2][j][s] %= modf;
                    //cout << "F[" << i << "," << j << "," << s << "]=" << f[i % 2][j][s] << endl;
                }
            }
        }
        int ans = 0;
        for (int i = 1; i <= m; i++) {
            ans += f[(n+1)%2][k][i];
            ans %= modf;
        }
        return ans;
    }
};
int main() {
    Solution s;
    while (true) {
        int n, m, k;
        cin >> n >> m >> k;
        cout << s.numOfArrays(n, m, k) << endl;
    }
    return 0;
}