#include <iostream>
#include <vector>
#include <functional>
using namespace std;

class Solution {
public:
    int minimumIncompatibility(vector<int>& a, int k) {
        if (a.size() == k) {
            int s1 = 0;
            for (int i = 0; i < a.size(); i++) {
                s1 += a[i];
            }
            return s1;
        }
        vector<vector<int>> p(17);
        vector<pair<int, int>> s;
        unordered_map <int, int> ban;
        int n = a.size();
        int f[2][65536];
        memset(f, 0x7f, sizeof(f));
        for (int i = 0; i < n; i++) {
            ban[a[i]] = (ban[a[i]] | (1 << i));
        }
        function<void(int, int, int, int, int,int)> dfs = [&](int x, int ct, int sta, int ma, int mi,int allw)->void {
            if (x == n) {
                p[ct].push_back(sta);
                if (ct == n/k && allw) {
                    s.push_back({ sta,ma - mi });
                    //s[sta] = ma - mi;
                }
                return;
            }
            dfs(x + 1, ct, sta, ma, mi,allw);
            int banv = ban[a[x]] & (~(1 << x));
            if (!(banv & sta)) {
                ma = std::max(ma, a[x]);
                mi = std::min(mi, a[x]);
                dfs(x + 1, ct + 1, sta | (1 << x), ma, mi,allw);
            }
            else {
                dfs(x + 1, ct + 1, sta | (1 << x), ma, mi, 0);
            }
        };
        dfs(0, 0, 0, INT_MIN, INT_MAX,1);
        f[0][0] = 0;
        for (int i = 0; i < k; i++) {
            memset(f[(i + 1) % 2], 0x7f, sizeof(f[(i + 1) % 2]));
            for (auto q : p[i*n/k]) {
                for (auto v : s) {
                    if ((q & v.first) == 0) {
                        f[(i + 1) % 2][q | v.first] = std::min(f[i % 2][q] + v.second, f[(i + 1) % 2][q | v.first]);
                    }
                }
            }
        }
        int ans = f[k%2][(1 << n) - 1];
        if (ans == 0x7f7f7f7f)ans = -1;
        return ans;
    }
};

int main() {
    Solution s;
    vector<int> a = { 1,2,3,4,5,6,7,8,9,10,11,12,13,14,15,16 };
    cout << s.minimumIncompatibility(a, 8) << endl;
    return 0;
}