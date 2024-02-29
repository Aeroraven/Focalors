#include <iostream>
#include <vector>
#include <stack>
#include <algorithm>
using namespace std;

class Solution {
   
public:
    int maxBuilding(int n, vector<vector<int>>& r) {
        using ll = long long;
        int m = r.size();
        sort(r.begin(), r.end(),
            [](const vector<int>& a, const vector<int>& b)->bool {
                return a[0] < b[0];
            });
        stack<int> q;
        for (int i = m - 1; i >= 0; i--) {
            r[i][0]--;
            if (q.empty() || (r[i][0] + r[i][1]) < r[q.top()][0] + r[q.top()][1]) {
                q.push(i);
            }
        }
        int clim = 0;
        ll ans = 0;
        for (int i = 0; i <= m; i++) {
            int cl = (i == 0) ? 0 : r[i - 1][0];
            int cr = (i == m) ? n - 1 : r[i][0] - 1;

            if (i == m) {
                ans = max(static_cast<ll>((cr - cl) + clim), ans);
                break;
            }
            ll qt = r[q.top()][0] + r[q.top()][1];

            //The problem aims to find the maximum of
            // I. y<=(x-cl)+clim => y=x+(clim-cl)
            // II. x+y<=qt => y =-x+qt
            // III. cl<=x<=cr
            // 2x+(clim-cl-qt)=0 => 2x = cl+qt-clim

            ll tx = cl + qt - clim;
            if (tx <= 2 * cl) {
                ans = max(qt - cl, ans);
            }
            else if (tx >= 2 * cr) {
                ans = max(ans, static_cast<ll>(cr + (clim - cl)));
            }
            else {
                if (tx % 2 == 0) {
                    ans = max(ans, tx / 2 + (clim - cl));
                }
                else {
                    if (tx / 2 >= cl) {
                        ans = max(ans, tx / 2 + (clim - cl));
                    }
                    if (tx / 2 + 1 <= cr) {
                        ans = max(ans, -(tx / 2 + 1) + qt);
                    }
                }
            }
            if (r[q.top()][0] == r[i][0])q.pop();
            clim = (r[i][0] - cl) + clim;
            clim = min(r[i][1], clim);
        }
        return static_cast<int>(ans);
    }
};
int main() {
    Solution s;
    vector<vector<int>> w = { };

    cout << s.maxBuilding(6, w) << endl;
    return 0;
}