#include <iostream>
#include <vector>
#include <queue>
using namespace std;

#define visit(x,y) (vis[(x)*(cols)+(y)])
struct Grid {
    int r, c, h;
    bool operator < (const Grid& p) const {
        return h > p.h;
    }
};
class Solution {
public:
    int trapRainWater(vector<vector<int>>& heightMap) {
        int curLevel = 0;
        priority_queue<Grid> q;
        int rows = heightMap.size(), cols = heightMap[0].size();
        int* vis = new int[rows * cols];
        memset(vis,0, sizeof(int) * (rows * cols));

        for (int i = 1; i < rows - 1; i++) {
            q.push({ i,0,heightMap[i][0] });
            q.push({ i,cols - 1,heightMap[i][cols - 1] });
            visit(i, 0) = 1;
            visit(i, cols - 1) = 1;
        }
        for (int i = 0; i < cols; i++) {
            q.push({ 0, i, heightMap[0][i] });
            q.push({ rows - 1, i, heightMap[rows - 1][i] });
            visit(0, i) = 1;
            visit(rows - 1, i) = 1;
        }

        int ans = 0;
        while (!q.empty()) {
            auto c = q.top();
            q.pop();
            
            curLevel = std::max(curLevel, c.h);
            ans += curLevel - c.h;

            if (c.r - 1 >= 0 && !visit(c.r-1,c.c)) {
                q.push({ c.r - 1,c.c,heightMap[c.r - 1][c.c] });
                visit(c.r - 1, c.c) = 1;
            }
            if (c.r + 1 <= rows - 1 && !visit(c.r + 1, c.c)) {
                q.push({ c.r + 1,c.c,heightMap[c.r + 1][c.c] });
                visit(c.r + 1, c.c) = 1;
            }
            if (c.c - 1 >= 0 && !visit(c.r, c.c - 1)) {
                q.push({ c.r,c.c - 1,heightMap[c.r][c.c - 1] });
                visit(c.r, c.c - 1) = 1;
            }
            if (c.c + 1 <= cols - 1 && !visit(c.r, c.c + 1)) {
                q.push({ c.r,c.c + 1,heightMap[c.r][c.c + 1] });
                visit(c.r, c.c + 1) = 1;
            }
        }
        return ans;
    }
};

int main() {
    Solution s;
    vector<vector<int>> x = { {1, 4, 3, 1, 3, 2},{3, 2, 1, 3, 2, 4},{2, 3, 3, 2, 3, 1}};
    cout << s.trapRainWater(x) << endl;
    return 0;
}