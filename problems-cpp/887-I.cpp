#include <iostream>

// This file is here for problem 887 induction

class Solution {
public:
    int superEggDrop(int k, int n) {
        int f[50][100];
        for (int i = 0; i <= n; i++) {
            f[1][i] = i;
        }
        for (int i = 2; i <= k; i++) {
            f[i][0] = 0;
            for (int j = 1; j <= n; j++) {
                f[i][j] = 100000;
                for (int s = 1; s <= j; s++) {
                    f[i][j] = std::min(f[i][j], std::max(f[i - 1][j - s] , f[i][s - 1]) + 1);
                    //std::cout << "S[" << i-1 << "," << j-s << "]=" << f[i - 1][j - s] << std::endl;
                }
                if(f[i][j]!=f[i][j-1])
                std::cout << "F[" << i << "," << j << "]=" << f[i][j] << std::endl;
            }
        }
        return 0;
    }
};

int main() {
    Solution s;
    s.superEggDrop(4, 100);
    return 0;
}