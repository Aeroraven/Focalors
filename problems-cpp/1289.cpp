#include <iostream>
#include <vector>

class Solution {
public:
    int minFallingPathSum(std::vector<std::vector<int>>& grid) {
        int n = grid.size();
        int* vf = new int[2 * n];
        int fmin = 0, smin = 0;
        //Init
        for (int i = 0; i < n; i++) {
            vf[i] = grid[0][i];
            if (vf[i] < vf[fmin])fmin = i;
        }
        if (fmin == 0)smin = 1;
        for (int i = 0; i < n; i++) {
            if (i != fmin && vf[i] < vf[smin])smin = i;
        }

        //Trans
        for (int i = 1; i < n; i++) {
            int bp = (i % 2) * n;
            int lp = ((i + 1) % 2) * n;
            for (int j = 0; j < n; j++) {
                if (j == fmin) {
                    vf[bp + j] = vf[lp + smin] + grid[i][j];
                }
                else {
                    vf[bp + j] = vf[lp + fmin] + grid[i][j];
                }
                //std::cout << "f[" << i << "," << j << "]=" << vf[bp + j] << std::endl;
            }
            fmin = 0; smin = 0;
            for (int j = 0; j < n; j++) {
                if (vf[bp + j] < vf[bp + fmin])fmin = j;
            }
            if (fmin == 0)smin = 1;
            for (int j = 0; j < n; j++) {
                if (j != fmin && vf[bp + j] < vf[bp + smin])smin = j;
            }
        }

        //Ans=0;
        int ans = 100000000, rs = ((n - 1) % 2) * n;
        for (int i = 0; i < n; i++) {
            ans = std::min(ans, vf[rs + i]);
        }
        return ans;
    }
};

int main() {
    Solution s;
    std::vector<std::vector<int>> a = { {1,2,3},{4,5,6},{7,8,9} };
    std::cout << s.minFallingPathSum(a) << std::endl;
    return 0;
}