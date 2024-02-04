#include <algorithm>
#include <iostream>

class Solution {
public:
    int numWays(int steps, int arrLen) {
        constexpr static int MOD = 1000000007;

        int n = std::min(arrLen, steps);
        int* vf = new int[2 * n];
        auto f = [&](int i, int j)->int& {
            return vf[(i % 2) * n + j];
        };
        memset(vf, 0, sizeof(int) * 2 * n);
        f(0, 0) = 1;
        for (int i = 1; i <= steps; i++) {
            auto bound = std::min(i, n - 1);
            for (int j = 0; j <= bound; j++) {
                auto& dest = f(i, j);
                dest = f(i - 1, j);
                if (j > 0) {
                    dest += f(i - 1, j - 1);
                    dest = dest % MOD;
                }
                if (j < n-1) {
                    dest += f(i - 1, j + 1);
                    dest = dest % MOD;
                }
                //std::cout << "F(" << i << "," << j << ")=" << f(i, j) << std::endl;
            }
        }
        return f(steps, 0);
    }
};

int main() {
    Solution s;
    auto x = s.numWays(3, 2);
    std::cout << x;
    return 0;
}