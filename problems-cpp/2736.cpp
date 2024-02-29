#include <vector>
#include <iostream>
#include <set>
#include <unordered_map>
#include <cstring>
#include <algorithm>
using namespace std;


class SegmentTree {
public:
    int* x;
    SegmentTree(int s) {
        x = new int[s * 4];
        memset(x, -1, sizeof(int) * s * 4);
    }
    void modify(int l, int r, int p, int val, int id) {
        if (p == l && l == r) {
            x[id] = max(x[id], val);
            return;
        }
        else if (l > p || r < p)return;
        int mid = (l + r) >> 1;
        modify(l, mid, p, val, id << 1);
        modify(mid + 1, r, p, val, (id << 1) + 1);
        x[id] = max(x[id << 1], x[(id << 1) + 1]);
    }
    int query(int l, int r, int ql, int qr, int id) {
        if (l >= ql && r <= qr) return x[id];
        else if (l > qr || r < ql)return -1;
        int mid = (l + r) >> 1;
        return max(query(l, mid, ql, qr, id << 1), query(mid + 1, r, ql, qr, (id << 1) + 1));
    }
};
class Solution {
public:
    vector<int> maximumSumQueries(vector<int>& nums1, vector<int>& nums2, vector<vector<int>>& queries) {
        set<int> st;
        unordered_map<int, int> mp;
        vector<pair<int, int>> p;
        int n = nums1.size(), m = queries.size(), ck = 0;
        vector<int> ret(m);
        for (int i = 0; i <m; i++)queries[i].push_back(i);
        sort(queries.begin(), queries.end(), [](const vector<int>& a, const vector<int>& b)->bool {
            return a[0] > b[0];
            });
        for (int i = 0; i < n; i++) {
            p.push_back({ nums1[i],nums2[i] });
            st.insert(nums2[i]);
        }
        for (auto& x : st)mp[x] = ck++;
        sort(p.begin(), p.end(), [](const pair<int, int>& a, const pair<int, int>& b)->bool {
            return a.first > b.first;
            });
        SegmentTree tree(ck);
        int ncur = 0;
        for (int i = 0; i < m; i++) {
            while (ncur < n && p[ncur].first >= queries[i][0]) {
                int lwId = mp[p[ncur].second];
                tree.modify(0, ck - 1, lwId, p[ncur].first + p[ncur].second, 1);
                ncur++;
            }
            auto lx = st.lower_bound(queries[i][1]);
            if (lx == st.end()) {
                ret[queries[i][2]] = -1;
                continue;
            }
            int qId = mp[*lx];
            int cAns = tree.query(0, ck - 1, qId, ck - 1, 1);
            ret[queries[i][2]] = cAns;
        }
        return ret;
    }
};
int main() {
    Solution s;
    vector<int> a = { 31 };
    vector<int> b = { 17 };
    vector<vector<int>> q = { {1,79} };
    auto w = s.maximumSumQueries(a, b, q);
    for (auto x : w) {
        cout << x << ",";
    }
    return 0;
}