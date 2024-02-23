#include <iostream>
#include <vector>
#include <queue>
using namespace std;
#define sta(a,b,c,d,e,f) ((a)+(b)*6+(c)*36+(d)*216+(e)*1296+(f)*7776)

class Solution {
public:
    int slidingPuzzle(vector<vector<int>>& board) {
        int vis[46657];
        constexpr static const int target = sta(1, 2, 3, 4, 5, 0);
        constexpr static const int base[] = { 1,6,36,216,1296,7776 };
        constexpr static const int dirs[6][3] = { {1,3,-1},{0,2,4},{1,5,-1},{0,4,-1},{3,5,1},{4,2,-1} };
        int beginSta = sta(board[0][0], board[0][1], board[0][2], board[1][0], board[1][1], board[1][2]);
        if (beginSta == target)return 0;
        memset(vis, 0, sizeof(vis));
        queue<int> q;
        q.push(beginSta);
        vis[beginSta] = 0;
        while (!q.empty()) {
            int v = q.front();
            int vx = v;
            q.pop();
            int block[6];
            int zeroPos;
            for (int i = 5; i >= 0; i--) {
                block[i] = vx / base[i];
                vx %= base[i];
                if (block[i] == 0)zeroPos = i;
            }
            for (int i = 0; i < 3; i++) {
                if (dirs[zeroPos][i] == -1)break;
                swap(block[zeroPos], block[dirs[zeroPos][i]]);
                int newState = sta(block[0], block[1], block[2], block[3], block[4], block[5]);
                if (!vis[newState]) {
                    vis[newState] = vis[v] + 1;
                    if (newState == target)return vis[v] + 1;
                    q.push(newState);
                }
                swap(block[zeroPos], block[dirs[zeroPos][i]]);
            }
        }
        return -1;
    }
};

int main() {
    Solution s;
    vector<vector<int>> a = { {1,2,3},{4,0,5} };
    cout << s.slidingPuzzle(a) << endl;
    return 0;
}