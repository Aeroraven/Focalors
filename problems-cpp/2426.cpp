#include <vector>
#include <iostream>
using namespace std;
class Solution {
public:
    long long numberOfPairs(vector<int>& nums1, vector<int>& nums2, int diff) {
        int tr[65537] = {};
        const int maxNd = 65536;
        const int baseAd = 30000;
        auto query = [&](int x)->int {
            int ans = 0;
            while (x) {
                ans += tr[x];
                x -= (x & (-x));
            }
            return ans;
        };
        auto add = [&](int x)->void {
            while (x <= maxNd) {
                tr[x] += 1;
                x += (x & (-x));
            }
        };
        long long ret = 0;
        int n = nums1.size();
        for (int i = 0; i < n; i++) {
            int lp = nums1[i] - nums2[i];
            int qv = lp + diff;
            ret += query(qv + baseAd);
            add(lp + baseAd);
        }
        return ret;
    }
};

int main() {
    Solution s;
    vector<int> a = { 3,-1 };
    vector<int> b = { -2,2 };
    cout << s.numberOfPairs(a, b, -1) << endl;
    return 0;
}