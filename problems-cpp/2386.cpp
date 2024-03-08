#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>
#include <cmath>
using namespace std;
using ll = long long;

struct Candidate {
    ll base;
    int index;
    ll idv;
    bool operator < (const Candidate& p) const {
        return base - idv < p.base - p.idv;
    }
};

class Solution {
public:
    ll kSum(vector<int>& nums, int k) {

        int n = nums.size();
        ll maxv = 0;
        vector<int> a(n);
        for (int i = 0; i < n; i++) {
            a[i] = std::abs(nums[i]);
            maxv += std::max(nums[i], 0);
        }
        std::sort(a.begin(), a.end());
        
        ll ans = maxv;
        priority_queue<Candidate> q;

        q.push({ maxv,0,a[0] });
        for (int i = 0; i < k - 1; i++) {
            auto tp = q.top();
            q.pop();
            ans = tp.base - tp.idv;
            if (tp.index != n - 1) {
                q.push({ tp.base,tp.index + 1,a[tp.index + 1] });
                q.push({ tp.base - tp.idv,tp.index + 1,a[tp.index + 1] });
            }
        }
        return ans;
    }
};

int main() {
    vector<int> a = { 1,-2,3,4,-10,12 };
    Solution s;
    cout << s.kSum(a, 1) << endl;

    return 0;
}