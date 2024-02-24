#include <vector>
#include <iostream>
#include <queue>
using namespace std;


struct Grid {
    int x, y, w;
    bool operator < (const Grid& p) const {
        return w > p.w;
    }
};
class Solution {
public:
    int swimInWater(vector<vector<int>>& grid) {
        int r = grid.size();
        int c = grid[0].size();
        int* f = new int[r * c];
        int target = (r - 1) * c + (c - 1);
        memset(f, 0, sizeof(int) * r * c);

        int ans = 0;
        priority_queue<Grid> q;
        q.push({0,0,grid[0][0]});
        f[0] = 1;
        while (!q.empty()) {
            auto tp = q.top();
            q.pop();
            constexpr static const int dir[4][2] = { {0,1},{1,0},{-1,0},{0,-1} };
            ans = std::max(ans, tp.w);
            for (int i = 0; i < 4; i++) {
                int nx = tp.x + dir[i][0];
                int ny = tp.y + dir[i][1];
                if (nx < 0 || nx >= r)continue;
                if (ny < 0 || ny >= c)continue;
                int ns = nx * c + ny;
                if (!f[ns]) {
                    if (ns == target) {
                        ans = std::max(ans, grid[nx][ny]);
                        return ans;
                    }
                    q.push({ nx,ny,grid[nx][ny] });
                    f[ns] = 1;
                }
            }
        }
        return ans;
    }
};

int main() {
    Solution s;
    vector<vector<int>> a = { {0,1,2,3,4},{24,23,22,21,5},{12,13,14,15,16},{11,17,18,19,20},{10,9,8,7,6} };
    cout << s.swimInWater(a) << endl;
    return 0;
}