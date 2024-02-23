#include <iostream>
#include <vector>
#include <string>
#include <queue>
using namespace std;

class Solution {
public:
    int shortestPathAllKeys(vector<string>& grid) {
#define vis(x,y,state) (visit[((x)*c+(y))*(tm)+(state)])
#define vis2(state) (visit[state])
#define sta(x,y,state) (((x)*c+(y))*(tm)+(state))
        int r = grid.size();
        int c = grid[0].size();
        int sx = -1, sy = -1;
        int m = 0;
        int ansKey, tm;
        for (int i = 0; i < r; i++) {
            for (int j = 0; j < c; j++) {
                if (grid[i][j] >= 'a' && grid[i][j] <= 'f') {
                    m = std::max(m, grid[i][j] - 'a' + 1);
                }
                else if (grid[i][j] == '@') {
                    sx = i; sy = j;
                }
            }
        }
        
        if (sx == -1) return -1;
        tm = (1 << m);
        ansKey = ((1 << m) - 1);
        int* visit = new int[r * c * (1 << m)];
        memset(visit, -1, r * c * (1 << m) * sizeof(int));
        
        vis(sx, sy, 0) = 0;
        queue<int> q;
        q.push(sta(sx, sy, 0));
        while (!q.empty()) {
            int x = q.front();
            q.pop();
            int state = x & ((1 << m) - 1);
            int pos = x >> m;
            int posr = pos / c;
            int posc = pos % c;

            constexpr static const int dir[4][2] = { {1,0},{0,1},{0,-1},{-1,0} };
            for (int i = 0; i < 4; i++) {
                int nr = posr + dir[i][0];
                int nc = posc + dir[i][1];
                if (nr >= 0 && nr < r && nc >= 0 && nc < c) {
                    
                    // If Key
                    if (grid[nr][nc] >= 'a' && grid[nr][nc] <= 'f') {
                        int nkey = 0;
                        nkey = (1 << (grid[nr][nc] - 'a'));
                        int newState = sta(nr, nc, state | nkey);
                        if ((state | nkey) == ansKey) {
                            return vis2(x) + 1;
                        }
                        if (vis2(newState) != -1)continue;
                        vis2(newState) = vis2(x) + 1;
                        q.push(newState);
                    }
                    // If Lock
                    else if (grid[nr][nc] >= 'A' && grid[nr][nc] <= 'F') {
                        int nkey = 0;
                        nkey = (1 << (grid[nr][nc] - 'A'));
                        if ((state & nkey) == 0)continue;
                        int newState = sta(nr, nc, state);
                        if (vis2(newState) != -1)continue;
                        vis2(newState) = vis2(x) + 1;
                        q.push(newState);
                    }
                    // If Room
                    else if (grid[nr][nc] == '.' || grid[nr][nc] == '@') {
                        int newState = sta(nr, nc, state);
                        if (vis2(newState) != -1)continue;
                        vis2(newState) = vis2(x) + 1;
                        q.push(newState);
                    }
                }
            }
        }
        return -1;
    }
};

int main() {
    Solution s;
    vector<string> a = { "@...a",".###A","b.BCc" };
    cout << s.shortestPathAllKeys(a) << endl;
    return 0;
}