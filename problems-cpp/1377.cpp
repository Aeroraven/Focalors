#include <iostream>
#include <vector>
#include <functional>
using namespace std;

class Solution {
public:
    double frogPosition(int n, vector<vector<int>>& edges, int t, int target) {
        n++;
        int* depth = new int[n];
        long long* nchild = new long long[n];
        int* vis = new int[n];
        vector<vector<int>> v(n);
        memset(vis, 0, sizeof(int) * n);
        for (const auto& e : edges) {
            v[e[0]].push_back(e[1]);
            v[e[1]].push_back(e[0]);
        }

        function<void(int,int)> dfs = [&](int u, int d)->void {
            int vc = 0;
            depth[u] = d;
            for (auto& to : v[u]) {
                if (vis[to] == 1)continue;
                vis[to] = 1;
                vc++;
                dfs(to, d + 1);
            }
            nchild[u] = vc;

        };
        vis[1] = 1;
        dfs(1, 0);
        bool dvx = ( nchild[target] == 0);

        function<void(int, long long)> dfs2 = [&](int u, long long cum)->void {
            if (nchild[u] == 0) nchild[u] = cum;
            else nchild[u] *= cum;

            for (auto& to : v[u]) {
                if (vis[to] == 2)continue;
                vis[to] = 2;
                dfs2(to, nchild[u]);
            }
        };
        vis[1] = 2;
        dfs2(1, 1);
        if (depth[target] == t || (depth[target] <= t && dvx)) {
            return 1.0 / nchild[target];
        }
        return 0.0;
    }
};

int main() {
    Solution s;
    vector<vector<int>> x = { {2,1},{3,2},{4,2},{5,2},{6,5},{7,1},{8,3},{9,3},{10,1} };
    cout << s.frogPosition(10, x, 3, 4) << endl;
    return 0;
}