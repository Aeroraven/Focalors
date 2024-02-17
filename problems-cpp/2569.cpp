#include <iostream>
#include <vector>
using namespace std;

class SegmentTree {
public:
    int* lazy;
    int* sum;
    
    SegmentTree(vector<int>& s){
        int v = 4 * (s.size()) + 8;
        lazy = new int[v];
        sum = new int[v];
        memset(lazy, 0, sizeof(int) * v);
        memset(sum, 0, sizeof(int) * v);
        this->build(s, 0, s.size() - 1, 1);
    }
    void build(vector<int>& s, int l, int r, int id) {
        if (l == r) {
            sum[id] = s[l];
        }
        else {
            int mid = (l + r) / 2;
            build(s, l, mid, id * 2);
            build(s, mid + 1, r, id * 2 + 1);
            sum[id] = sum[id * 2] + sum[id * 2 + 1];
            
        }
    }
    void pushDown(int l, int r, int id) {
        if (lazy[id] % 2 != 0 && l!=r) {
            int mid = (l + r) / 2;
            sum[id * 2] = (mid - l + 1) - sum[id * 2];
            sum[id * 2 + 1] = (r - (mid + 1) + 1) - sum[id * 2 + 1];
            lazy[id * 2] += 1;
            lazy[id * 2 + 1] += 1;
        }
        lazy[id] = 0;
    }

    void reverse(int l, int r, int qL, int qR, int id) {
        if (l == qL && r == qR) {
            pushDown(l, r, id);
            sum[id] = (r - l + 1) - sum[id];
            lazy[id] = 1;
        }
        else if (r<l || l>qR || r < qL) {
            return;
        }
        else {
            int mid = (l + r) / 2;
            pushDown(l, r, id);
            reverse(l, mid, qL, std::min(mid, qR), id * 2);
            reverse(mid + 1, r, std::max(mid + 1, qL), qR, id * 2 + 1);
            sum[id] = sum[id * 2] + sum[id * 2 + 1];
            
        }
    }
    int simulatedReverse(vector<int>& s, int l, int r) {
        for (int i = l; i <= r; i++) {
            s[i] = 1 - s[i];
        }
        int sumv = 0;
        for (int i = 0; i < s.size(); i++) {
            sumv += s[i];
        }
        return sumv;
    }
};


class Solution {
public:
    vector<long long> handleQuery(vector<int>& nums1, vector<int>& nums2, vector<vector<int>>& queries) {
        long long sum2 = 0;
        for (int i = 0; i < nums2.size(); i++) {
            sum2 += nums2[i];
        }
        SegmentTree tree(nums1);
        vector<long long>ans;
        for (auto& q : queries) {
            if (q[0] == 1) {
                tree.reverse(0, nums1.size(), q[1], q[2], 1);
            }
            else if(q[0]==2){
                sum2 += q[1] * (long long)tree.sum[1];
            }
            else {
                ans.push_back(sum2);
            }
        }

        return ans;
    }
};

int main() {
    Solution s;
    vector<int> a = { 1,0,1 };
    vector<int> b = { 1,0,0 };
    vector<vector<int>> q = { {1,1,1}};
    s.handleQuery(a, b, q);
    return 0;
}