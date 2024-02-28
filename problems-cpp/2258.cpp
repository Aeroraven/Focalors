#include <vector>
#include <queue>
#include <cstring>
#include <iostream>
using namespace std;


class Solution {
public:
    int maximumMinutes(vector<vector<int>>& grid) {
        int r = grid.size();
        int c = grid[0].size();
        constexpr static const int dirs[][2] = { {0,1},{1,0},{-1,0},{0,-1} };
        int* delay = new int[r * c];
        int* vis = new int[r * c];
        memset(delay, 0x7f, sizeof(int) * r * c);
        memset(vis, -1, sizeof(int) * r * c);

#define p(x,y) ((x)*c+(y))
#define valid(x,y) ((x)>=0&&(x)<r&&(y)>=0&&(y)<c)
        queue<int> q;
        for (int i = 0; i < r; i++) {
            for (int j = 0; j < c; j++) {
                if (grid[i][j] == 1) {
                    q.push(p(i, j));
                    delay[p(i, j)] = 0;
                }
            }
        }

        while (!q.empty()) {
            int fx = q.front();
            q.pop();
            int cx = fx / c, cy = fx % c;
            for (int i = 0; i < 4; i++) {
                int nx = cx + dirs[i][0];
                int ny = cy + dirs[i][1];
                if (valid(nx, ny) && delay[p(nx, ny)] == 0x7f7f7f7f && grid[nx][ny]!=2) {
                    delay[p(nx, ny)] = delay[fx] + 1;
                    q.push(p(nx,ny));
                }
            }
        }


        auto bfs = [&](int retain)->bool {
            int validFlag = true;
            queue<int> hq;
            memset(vis, -1, sizeof(int)*r*c);
            if (delay[0] - retain <= 0) {
                return false;
            }
            vis[0] = 0;
            hq.push(0);
            while (!hq.empty()) {
                int fx = hq.front();
                hq.pop();
                int cx = fx / c, cy = fx % c;
                for (int i = 0; i < 4; i++) {
                    int nx = cx + dirs[i][0];
                    int ny = cy + dirs[i][1];
                    if (valid(nx, ny)  && grid[nx][ny] != 2 && vis[p(nx,ny)]==-1) {
                        int remainingTime = delay[p(nx, ny)] - (vis[fx] + 1 + retain);
                        if (nx == r - 1 && ny == c - 1 && remainingTime >= 0) {
                            return true;
                        }
                        else if(remainingTime>0) {
                            vis[p(nx, ny)] = vis[fx] + 1;
                            hq.push(p(nx, ny));
                        }
                    }
                }
            }
            return false;
        };

        int l = -1, ri = 1000000000;
        while (l < ri) {
            int mid = (l + ri + 1) / 2;
            bool able = bfs(mid);
            //cout <<l<<","<<ri<<":"<< mid << "->" << able << endl;
            if (able) {
                l = mid;
            }
            else {
                ri = mid - 1;
            }
        }

        return ri;
    }
};

int main() {
    Solution s;
    vector<vector<int>> p = {
        {0,2,0,0,0,0,0,0},
        {0,2,0,2,2,2,2,2},
        {0,2,0,0,0,0,0,0},
        {0,2,2,2,2,2,2,0},
        {0,0,0,0,0,0,0,0}
    };
    cout << s.maximumMinutes(p) << endl;
    return 0;

}