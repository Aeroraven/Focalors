#include <vector>
#include <set>
#include <cstring>
#include <unordered_map>
#include <iostream>
using namespace std;

using ll = long long;

class SegmentTree {
public:
    ll* a;
    SegmentTree(int s) {
        a = new ll[s * 4];
        memset(a, 0, sizeof(ll) * s * 4);
    }
    ll query(int l, int r, int ql, int qr, int idx) {
        if (l >= ql && r <= qr) {
            return a[idx];
        }
        else if (ql > r || qr < l)  return -1;
        int mid = (l + r) >> 1;
        auto lp = query(l, mid, ql, qr, idx * 2);
        auto rp = query(mid + 1, r, ql, qr, idx * 2 + 1);
        return max(lp, rp);
    }
    void modify(int l, int r, int p, int idx, ll val) {
        if (p == l && p == r) {
            a[idx] = max(a[idx], val);
            return;
        }
        else if (l > p || r < p)return;
        int mid = (l + r) >> 1;
        modify(l, mid, p, idx * 2, val);
        modify(mid + 1, r, p, idx * 2 + 1, val);
        a[idx] = max(a[idx * 2], a[idx * 2 + 1]);
    }
};
class Solution {
public:


    long long maxBalancedSubsequenceSum(vector<int>& nums) {
        set<int> st;
        int ck = 0;
        unordered_map<int, int> mp;

        for (int i = 0; i < nums.size(); i++) {
            st.insert(nums[i] - i);

        }
        for (auto& x : st) {
            mp[x] = ck++;

        }
        SegmentTree tree = SegmentTree(ck + 15);
        ll ans = LLONG_MIN;
        for (int i = 0; i < nums.size(); i++) {
            int curv = nums[i];
            int curi = nums[i] - i;
            int disi = mp[curi];

            ll last = tree.query(0, ck - 1, 0, disi, 1);
            ll opt = last + curv;
            tree.modify(0, ck - 1, disi, 1, opt);
            ans = std::max(opt, ans);
        }
        return ans;
    }
};

int main() {
    Solution s;
    vector<int> a = { -2};
    cout << s.maxBalancedSubsequenceSum(a) << endl;
    return 0;
}