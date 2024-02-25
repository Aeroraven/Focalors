#include <iostream>
#include <vector>
#include <queue>
using namespace std;

class Solution {
public:
    int minimumMoves(vector<vector<int>>& grid) {
        int n = grid.size();
        int* visit = new int[n * n * 2];
        memset(visit, 0, sizeof(int) * n * n * 2);

#define vis(c,r,d) (visit[(c)*n*2+(r)*2+(d)])
#define sta(c,r,d) ((c)*n*2+(r)*2+(d))
#define valid(c,r) (((c)>=0&&(c)<n&&(r)>=0&&(r)<n) && (grid[(r)][(c)]==0))
        int target = sta(n - 2, n - 1, 0);

        vis(0, 0, 0) = 0;
        queue<int> q;
        q.push(sta(0, 0, 0));
        while (!q.empty()) {
            int tp = q.front(); q.pop();
            int dir = tp % 2;
            int curc = tp / n / 2;
            int curr = (tp / 2) % n;
            int x = visit[tp];
            
            if (dir == 0) { //Horizontal
                if (valid(curc + 2, curr)) { //Right
                    if (!vis(curc + 1, curr,0)) {
                        vis(curc + 1, curr, 0) = x + 1;
                        int nsta = sta(curc + 1, curr, 0);
                        q.push(nsta);
                        if (nsta == target)return x + 1;
                    }
                }
                if (valid(curc, curr + 1) && valid(curc + 1, curr + 1)) { //Down & Rotate
                    if (!vis(curc, curr + 1, 0)) {
                        vis(curc, curr + 1, 0) = x + 1;
                        int nsta = sta(curc, curr + 1, 0);
                        q.push(nsta);
                        if (nsta == target)return x + 1;
                    }
                    if (!vis(curc, curr, 1)) {
                        vis(curc, curr, 1) = x + 1;
                        int nsta = sta(curc, curr, 1);
                        q.push(nsta);
                    }
                }
            }
            else {
                if (valid(curc, curr + 2)) { //Down
                    if (!vis(curc, curr + 1, 1)) {
                        vis(curc, curr + 1, 1) = x + 1;
                        int nsta = sta(curc, curr + 1, 1);
                        q.push(nsta);
                    }
                }
                if (valid(curc + 1, curr) && valid(curc + 1, curr + 1)) { //Right & Rotate
                    if (!vis(curc + 1, curr, 1)) {
                        vis(curc + 1, curr, 1) = x + 1;
                        int nsta = sta(curc + 1, curr, 1);
                        q.push(nsta);
                    }
                    if (!vis(curc, curr, 0)) {
                        vis(curc, curr, 0) = x + 1;
                        int nsta = sta(curc, curr, 0);
                        q.push(nsta);
                        if (nsta == target)return x + 1;
                    }
                }
            }
        }
        return -1;
    }
};

int main() {
    Solution s;
    vector<vector<int>> p = { {0,0,0,0,0,1},
               {1,1,0,0,1,0},
               {0,0,0,0,1,1},
               {0,0,1,0,1,0},
               {0,1,1,0,0,0},
               {0,1,1,0,0,0} };
    cout << s.minimumMoves(p) << endl;
    return 0;
}