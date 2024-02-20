#include <iostream>
#include <vector>
#include <cstring>
using namespace std;

class Solution {
public:
    int dieSimulator(int n, vector<int>& rollMax) {
        int f[2][6][16];
        int g[2][6];
        int total[2];
        memset(f, 0, sizeof(f));
        memset(g, 0, sizeof(g));
        memset(total, 0, sizeof(total));
        constexpr static int modf = 1000000000 + 7;
        //Initialize
        for (int i = 0; i <= 5; i++) {
            f[1][i][1] = 1;
            g[1][i] = 1;
            total[1] += 1;
        }
        //Rep
        for (int i = 2; i <= n; i++) {
            total[i % 2] = 0;
            for (int j = 0; j <= 5; j++) {
                g[i % 2][j] = 0;
                f[i % 2][j][1] = total[(i - 1) % 2] - g[(i - 1) % 2][j];
                if (f[i % 2][j][1] < 0) {
                    f[i % 2][j][1] += modf;
                   
                }
                f[i % 2][j][1] %= modf;

                total[i % 2] += f[i % 2][j][1];
                total[i % 2] %= modf;
                g[i % 2][j] += f[i % 2][j][1];
                g[i % 2][j] %= modf;
                for (int k = 2; k <= rollMax[j]; k++) {
                    f[i % 2][j][k] = f[(i - 1) % 2][j][k - 1];
                    total[i % 2] += f[i % 2][j][k];
                    g[i % 2][j] += f[i % 2][j][k];
                    total[i % 2] %= modf;
                    g[i % 2][j] %= modf;
                }
            }
        }
        return total[n % 2];
    }
};

int main() {
    Solution s;
    vector<int> v = { 1,1,1,2,2,3 };
    cout << s.dieSimulator(3, v);
    return 0;
}