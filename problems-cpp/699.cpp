#include <iostream>
#include <algorithm>
#include <vector>
#include <map>
using namespace std;

class SegmentTree {
public:
    int* value = nullptr;
    int* lazy = nullptr;
    int n;
    SegmentTree(int n) {
        this->n = n;
        this->value = new int[(n << 2) + 4];
        this->lazy = new int[(n << 2) + 4];
        memset(this->value, 0, sizeof(int) * ((n << 2) + 4));
        memset(this->lazy, 0, sizeof(int) * ((n << 2) + 4));
    }
    void pushDown(int id) {
        if (lazy[id]) {
            this->value[id * 2] = this->lazy[id];
            this->value[id * 2 + 1] = this->lazy[id];
            this->lazy[id * 2] = this->lazy[id];
            this->lazy[id * 2 + 1] = this->lazy[id];
            lazy[id] = 0;
        }
    }
    int query(int l, int r, int id, int qL, int qR) {
        if (l == qL && r == qR) {
            return this->value[id];
        }
        else if (qR<l || qL>r || r < l) {
            return -1;
        }
        else {
            pushDown(id);
            int mid = (l + r) >> 1;
            int lans = query(l, mid, id * 2, qL, std::min(qR, mid));
            int rans = query(mid + 1, r, id * 2 + 1, std::max(mid + 1, qL), qR);
            return std::max(lans, rans);
        }
    }
    void add(int l, int r, int id, int qL, int qR, int val) {
        if (l == qL && r == qR) {
            this->value[id] = val;
            this->lazy[id] = val;
        }
        else if (qR<l || qL>r || r < l) {
            return;
        }
        else {
            int mid = (l + r) >> 1;
            add(l, mid, id * 2, qL, std::min(qR, mid),val);
            add(mid+1,r, id * 2 + 1, std::max(mid + 1, qL), qR,val);
            this->value[id] = std::max(this->value[id], val);
            
        }
    }
};
class Solution {
public:
    vector<int> fallingSquares(vector<vector<int>>& positions) {
        std::map<int,int> vals;
        for (auto& x : positions) {
            int start = x[0];
            int end = x[0] + x[1] - 1;
            if (!vals.count(start)) {
                vals[start] = 1;
            }
            if (!vals.count(end)) {
                vals[end] = 1;
            }
        }
        int cur = 0;
        for (auto& [k, v] : vals) {
            v = cur++;
        }
        int maxv = 0;
        SegmentTree tree(cur);
        vector<int> ans;
        for (auto& x : positions) {

            int start = x[0];
            int end = x[0] + x[1] - 1;
            int base = tree.query(0, cur - 1, 1, vals[start], vals[end]);
            
            maxv = std::max(maxv, base + x[1]);
            ans.push_back(maxv);
            tree.add(0, cur - 1, 1, vals[start], vals[end], base + x[1]);
        }

        return ans;
    }
};

int main() {
    Solution s;
    vector<vector<int>> w = { {1,2},{2,4},{1,1},{1,4},{4,1},{6,1},{6,1} };
    auto x = s.fallingSquares(w);
    for (auto p : x) {
        cout << p << ",";
    }
    return 0;
}