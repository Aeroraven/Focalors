#include <vector>
#include <queue>
#include <iostream>
#include <algorithm>
using namespace std;

struct Point {
    int u;
    long long weight;
    bool operator < (const Point& p) const {
        return weight > p.weight;
    }
};
class Solution {
public:
    int countPaths(int n, vector<vector<int>>& roads) {
        using ll = long long;
        const int MOD = 1000000007;

        //Edge List
        vector<vector<pair<int, ll>>> e(n);
        vector<ll> f(n), vis(n),dist(n);
        int m = roads.size();
        for (int i = 0; i < m; i++) {
            e[roads[i][0]].push_back({ roads[i][1],roads[i][2] });
            e[roads[i][1]].push_back({ roads[i][0],roads[i][2] });
        }

        for (int i = 0; i < n; i++) {
            dist[i] = INT_MAX * 400ll;
        }
        // Shortest Path
        priority_queue<Point> p;
        p.push({ n - 1,0 });
        dist[n - 1] = 0;
        while (!p.empty()) {
            
            auto tp = p.top();
            p.pop();

            if (vis[tp.u] == 2)continue;
            vis[tp.u] = 2;
            for (int i = 0; i < e[tp.u].size(); i++) {
                int to = e[tp.u][i].first;
                ll w = e[tp.u][i].second;
                if (vis[to] == 2)continue;
                if (dist[tp.u] + w < dist[to]) {
                    dist[to] = dist[tp.u] + w;
                    p.push({ to,dist[to] });
                }
            }
        }

        vector < pair<int, ll >> a;
        for (int i = 0; i < n; i++) {
            a.push_back({ i,dist[i] });
        }
        sort(a.begin(), a.end(), [](const pair<int, ll>& x, const pair<int, ll>& y) {
            return x.second > y.second;
        });
        f[0] = 1;
        for (int i = 0; i < n; i++) {
            int u = a[i].first;
            ll d = a[i].second;
            vis[u] = 3;
            for (int j = 0; j < e[u].size(); j++) {
                int to = e[u][j].first;
                ll w = e[u][j].second;
                if (vis[to] != 3) continue;
                if (dist[u] + w == dist[to]) {
                    f[u] += f[to];
                    f[u] %= MOD;
                }
            }
        }
        return f[n - 1];
    }
};

int main() {
    Solution s;
    vector<vector<int>> x = { {0,6,7},{0,1,2},{1,2,3},{1,3,3},{6,3,3},{3,5,1},{6,5,1},{2,5,1},{0,4,5},{4,6,2} };
    cout << s.countPaths(7, x) << endl;
    return 0;
}