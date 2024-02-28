#include <iostream>
#include <vector>
#include <set>
#include <unordered_map>
#include <algorithm>
using namespace std;

class Solution {
public:
    int maxValue(vector<vector<int>>& events, int k) {
        set<int> vals;
        unordered_map<int,int> rv;
        for (int i = 0; i < events.size(); i++) {
            vals.insert(events[i][0]);
            vals.insert(events[i][1] + 1);
        }
        int ck = 0;
        for (auto s : vals) {
            rv[s] = ck++;
        }
        for (int i = 0; i < events.size(); i++) {
            events[i][0] = rv[events[i][0]];
            events[i][1] = rv[events[i][1] + 1];
        }
        int* f = new int[vals.size() * (k + 1)];
        int* g = new int[k + 1];
#define d(x,y) f[(x)*(k+1)+(y)]
        memset(f, 0, sizeof(int) * vals.size() * (k + 1));
        memset(g, 0, sizeof(int) * (k + 1));
        auto cmp = [](const vector<int>& a, const vector<int>& b) {
            return a[0] < b[0];
        };
        sort(events.begin(), events.end(), cmp);
        int curv = 0;
        int ans = 0;
        for (int i = 0; i < events.size(); i++) {
            while (curv<ck && curv <= events[i][0]) {
                for (int j = 0; j <= k; j++) {
                    g[j] = std::max(g[j], d(curv, j));
                }
                curv++;
            }
            for (int j = 1; j <= k; j++) {
                d(events[i][1], j) = std::max(d(events[i][1], j), g[j - 1] + events[i][2]);
                ans = std::max(d(events[i][1], j), ans);
            }
        }
        return ans;
    }
};


int main() {
    Solution s;
    vector<vector<int>> a = { {1,2,4},{3,4,3},{2,3,1} };
    cout << s.maxValue(a,2) << endl;
    return 0;
}