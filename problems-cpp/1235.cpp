#include <iostream>
#include <vector>
#include <set>
#include <unordered_map>
#include <algorithm>
#include <tuple>
using namespace std;



class Solution {
public:
    int jobScheduling(vector<int>& startTime, vector<int>& endTime, vector<int>& profit) {
        int n = startTime.size(), ck = 0;
        int* f = new int[2*n+2];
        memset(f, 0, sizeof(int)*(2*n+2));
        set<int> st;
        unordered_map<int, int> mp;
        vector<tuple<int, int,int>> work(n);
        for (int i = 0; i < n; i++) {
            st.insert(startTime[i]);
            st.insert(endTime[i]);
        }
        for (auto& x : st) mp[x] = ck++;
        for (int i = 0; i < n; i++) {
            get<0>(work[i]) = mp[startTime[i]];
            get<1>(work[i]) = mp[endTime[i]];
            get<2>(work[i]) = profit[i];
        }
        sort(work.begin(), work.end(), [](const tuple<int, int, int>& a, const tuple<int, int, int>& b) {
            return get<0>(a) < get<0>(b);
        });
        int curv = 0;
        int curMax = 0;
        int ans = 0;
        for (int i = 0; i < n; i++) {
            while (curv < ck && curv <= get<0>(work[i])) {
                curMax = std::max(f[curv++], curMax);
            }
            f[get<1>(work[i])] = std::max(f[get<1>(work[i])], curMax + get<2>(work[i]));
            ans = max(ans, f[get<1>(work[i])]);
        }
        return ans;
    }
};
int main() {
    Solution s;
    vector<int> a = { 1,1,1 };
    vector<int> b = { 2,3,4 };
    vector<int> p = { 5,6,4 };
    cout << s.jobScheduling(a, b, p) << endl;
    return 0;
}