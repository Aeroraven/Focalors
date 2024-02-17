#include <vector>
#include <iostream>
#include <cstring>
using namespace std;

class SegmentTree {
public:
    int* val = nullptr;
    SegmentTree() {
        val = new int[4 * 100001];
        memset(val, 0, sizeof(int) * 400004);
    }
    int query(int l, int r, int qL, int qR, int id) {

        if (l >= qL && r <= qR) {
            return val[id];
        }
        else if (l > qR || r < l || r < qL) {
            return 0;
        }
        else {
            int mid = (l + r) >> 1;
            int lv = query(l, mid, qL, qR, id * 2);
            int rv = query(mid + 1, r, qL, qR, id * 2 + 1);
            return std::max(lv, rv);
        }
    }
    int add(int l, int r, int p, int v, int id) {
        if (l == r && l == p) {
            val[id] = std::max(val[id], v);
            return val[id];
        }
        else if (l > p || r < p || r < l) {
            if (!(r < l))return val[id];
            return 0;
        }
        else {
            int mid = (l + r) >> 1;
            int lv = add(l, mid, p, v, id * 2);
            int rv = add(mid + 1, r, p, v, id * 2 + 1);
            val[id] = std::max(lv, rv);
            return val[id];
        }
    }
};

class Solution {
public:
    int lengthOfLIS(vector<int>& nums, int k) {
        SegmentTree tree;
        constexpr static int maxVal = 100000;
        int bestAns = 0;
        for (auto& x : nums) {
            int ans = tree.query(1, maxVal, std::max(1, x - k), x - 1, 1);
            bestAns = std::max(ans + 1, bestAns);
            tree.add(1, maxVal, x, ans + 1, 1);
            cout << "At Pos:" << x << " Ans=" << ans + 1 << endl;
        }
        return bestAns;
    }
};

int main() {
    Solution s;
    vector<int> x = { 4,2,1,4,3,4,5,8,15,7,4,5,1,8,12,4,7 };
    cout << s.lengthOfLIS(x,500) << endl;
    return 0;
}