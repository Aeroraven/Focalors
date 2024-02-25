#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    int cherryPickup(vector<vector<int>>& grid) {
        constexpr static const int last[9][2] = {
            {-1,-1},{-1,0},{-1,1},
            {0,-1},{0,0},{0,1},
            {1,-1},{1,0},{1,1}
        };
        int r = grid.size();
        int c = grid[0].size();
        int* vf = new int[r * c * c];

#define f(x,yw,y2) (vf[(x)*c*c+(yw)*c+(y2)])
        for (int i = 0; i < c; i++) {
            for (int j = 0; j < c; j++) {
                f(0, i, j) = INT_MIN / 2;
            }
        }
        f(0, 0, c - 1) = grid[0][0] + grid[0][c - 1];

        int ans = 0;
        for (int k = 1; k < r; k++) {
            for (int i = 0; i < c; i++) {
                for (int j = 0; j < c; j++) {
                    int maxv = INT_MIN;
                    int gain = grid[k][i];
                    if (i != j)gain += grid[k][j];
                    for (int t = 0; t < 9; t++) {
                        int s1 = i + last[t][0];
                        int s2 = j + last[t][1];
                        if (s1 < 0 || s1 >= c || s2 < 0 || s2 >= c)continue;
                        maxv = std::max(f(k - 1, s1, s2), maxv);
                    }
                    f(k, i, j) = maxv + gain;
                    ans = std::max(ans, f(k, i, j));
                }
            }
        }
        return ans;
    }
};

int main() {
    Solution s;
    vector<vector<int>> p = { {1,0,0,0,0,0,1},{2,0,0,0,0,3,0},{2,0,9,0,0,0,0},{0,3,0,5,4,0,0},{1,0,2,3,0,0,6} };
    cout << s.cherryPickup(p) << endl;
    return 0;
}