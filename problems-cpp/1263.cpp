#include <vector>
#include <queue>
#include <iostream>
#include <tuple>
using namespace std;

struct Proposal {
    int x, y;
    int cx, cy;
};

class Solution {
public:
    int minPushBox(vector<vector<char>>& grid) {
        int m = grid.size();
        int n = grid[0].size();
        queue<Proposal> q;
        
        int iX, iY;
        int cX, cY;
        int tX, tY;
        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                if (grid[i][j] == 'B') {
                    iX = i;
                    iY = j;
                }
                if (grid[i][j] == 'S') {
                    cX = i;
                    cY = j;
                }
                if (grid[i][j] == 'T') {
                    tX = i;
                    tY = j;
                }
            }
        }
        int* vis = new int[m * n * m * n];
#define f(x,y,cx,cy) vis[((x)+(y)*m)*m*n+((cx)+(cy)*m)]
        memset(vis, -1, sizeof(int) * m * n * m * n);
        f(iX, iY, cX, cY) = 0;
        q.push({ iX,iY,cX,cY });
        
        int dirs[4][2] = { {1,0},{-1,0},{0,1},{0,-1} };
        auto checkValid = [&](int bx, int by, int cx, int cy, int mx, int my) {
            if (bx + mx < 0 || bx + mx >= m)return false;
            if (by + my < 0 || by + my >= n)return false;
            if (bx - mx < 0 || bx - mx >= m)return false;
            if (by - my < 0 || by - my >= n)return false;
            if (grid[bx - mx][by - my] == '#')return false;
            if (grid[bx + mx][by + my] == '#')return false;

            int targetX = bx - mx, targetY = by - my;
            if (targetX == cx && targetY == cy)return true;
            queue<pair<int, int>> qx;
            int* visn = new int[m * n];
            memset(visn, 0, sizeof(int) * m * n);
#define fn(x,y) visn[(x)+(y)*m]
            fn(cx, cy) = 1;
            qx.push({ cx,cy });
            while (!qx.empty()) {
                auto fr = qx.front();
                qx.pop();
                for (int i = 0; i < 4; i++) {
                    int mvx = fr.first + dirs[i][0];
                    int mvy = fr.second + dirs[i][1];
                    if (mvx < 0 || mvx >= m)continue;
                    if (mvy < 0 || mvy >= n)continue;
                    if (grid[mvx][mvy] == '#')continue;
                    if (mvx == bx && mvy == by)continue;
                    if (fn(mvx, mvy))continue;
                    if (mvx == targetX && mvy == targetY)return true;
                    qx.push({ mvx,mvy });
                    fn(mvx, mvy) = 1;
                }
            }
            return false;
        };

        while (!q.empty()) {
            auto fr = q.front();
            q.pop();
            auto dv = f(fr.x, fr.y, fr.cx, fr.cy);
            //cout << fr.x << " " << fr.y << " Val=" << dv << endl;
            for (int i = 0; i < 4; i++) {
                auto cpx = fr.x, cpy = fr.y;
                int nbx = cpx + dirs[i][0], nby = cpy + dirs[i][1];
                if (nbx < 0 || nbx >= m)continue;
                if (nby < 0 || nby >= n)continue;
                auto visst = f(nbx,nby,cpx,cpy);
                if (visst!=-1)continue;
                auto valid = checkValid(cpx, cpy, fr.cx, fr.cy, dirs[i][0], dirs[i][1]);

                //cout << fr.x << " " << fr.y << "->" << fr.x+dirs[i][0]<<" "<<fr.y+dirs[i][1]<<" ="<<valid << endl;
                
                if (valid) {
                    f(nbx, nby, cpx, cpy) = dv + 1;
                    q.push({ nbx,nby,cpx,cpy });
                    if (nbx == tX && nby == tY) {
                        return dv + 1;
                    }
                }
            }
        }
        return -1;
        
    }
};

int main() {
    vector<vector<char>> c = { {'#','#','#','#','#','#'},
             {'#','T','#','#','#','#'},
             {'#','.','.','B','.','#'},
             {'#','#','#','#','.','#'},
             {'#','.','.','.','S','#'},
             {'#','#','#','#','#','#'} };
    Solution s;
    cout << s.minPushBox(c) << endl;

    return 0;
}