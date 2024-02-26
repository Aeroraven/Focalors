#include <iostream>
#include <vector>
#include <cstring>
using namespace std;

class Solution {
public:
    int minCost(vector<int>& houses, vector<vector<int>>& cost, int m, int n, int target) {
        int f[2][21][101];

        for (int i = 0; i <= n; i++) {
            for (int j = 0; j <= target; j++) {
                f[0][i][j] = INT_MAX;
            }
        }

        if (houses[0] == 0) {
            for (int j = 1; j <= n; j++) {
                f[0][j][1] = cost[0][j - 1];
                //cout << 0 << "," << j << "," << 1 << "=" << f[0][j][1] << endl;
            }
        }
        else {
            f[0][houses[0]][1] = 0;
        }
       

        for (int i = 1; i < m; i++) {
            for (int j = 1; j <= n; j++) {
                for (int k = 1; k <= target; k++) {
                    f[i%2][j][k] = INT_MAX;
                    int gain = cost[i][j - 1];
                    if (houses[i] != 0) {
                        if (houses[i] == j)gain = 0;
                        else continue;
                    }

                    f[i % 2][j][k] = f[(i+1) % 2][j][k];
                    for (int p = 1; p <= n; p++) {
                        if (k - 1 > 0 && p!=j) {
                            f[i%2][j][k] = std::min(f[i%2][j][k], f[(i+1)%2][p][k - 1]);
                        }
                    }
                    if (f[i%2][j][k] != INT_MAX) {
                        f[i%2][j][k] += gain;
                    }
                }
            }
        }

        int ans = INT_MAX;
        for (int i = 1; i <= n; i++) {
            ans = std::min(ans, f[(m+1)%2][i][target]);
        }
        if (ans == INT_MAX)return -1;
        return ans;
    }
};

int main() {
    Solution s;
    vector<int> house = { 1,1,1,0,2,0,0,2,0,0 };
    vector<vector<int>> cost = { {6,8,5},{4,8,3},{7,1,10},{4,9,8},{4,7,6},{6,5,1},{8,9,4},{7,6,3},{9,5,10},{8,8,4} };
    cout << s.minCost(house, cost, 10,3,10) << endl;
    return 0;
}