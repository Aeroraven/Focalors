#include <iostream>
#include <algorithm>
#include <vector>

class Solution {
public:
    int maxSatisfaction(std::vector<int>& satisfaction) {
        // f[i][j] = max like-time value that can be obtained by cooking j out of first i dishes
        // satisfaction values are in ascending order
        // f[i][j] = max(f[i-1][j],f[i-1][j-1]*satisfaction[i]*j)

        std::sort(satisfaction.begin(), satisfaction.end());
        int n = satisfaction.size();
        int* f = new int[2 * (n + 1)];
        int ans = 0;
        for (int i = 1; i < 2 * n + 2; i++) {
            f[i] = -2147483648;
        }
        f[n+1] = 0;
        for (int i = 0; i < n; i++) {
            f[(i % 2) * (n + 1) + 0] = 0;
            for (int j = 1; j <= i + 1; j++) {
                f[(i % 2) * (n + 1) + j] = std::max(f[((i + 1) % 2) * (n + 1) + j], f[((i + 1) % 2) * (n + 1) + j - 1] + satisfaction[i] * j);
                ans = std::max(f[(i % 2) * (n + 1) + j], ans);
            }
        }
        return ans;
    }
};

int main() {
    Solution s;
    std::vector<int> p = { 4,3,2 };
    std::cout << s.maxSatisfaction(p);
    return 0;
}