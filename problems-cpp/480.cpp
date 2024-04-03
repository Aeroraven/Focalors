#include <vector>
#include <queue>
#include <iostream>
using namespace std;

struct Element {
    int val, idx;
    bool operator < (const Element& p) const {
        if (val == p.val)return idx < p.idx;
        return val < p.val;
    }
    bool operator > (const Element& p) const {
        if (val == p.val)return idx > p.idx;
        return val > p.val;
    }
};
class Solution {
public:
    vector<double> medianSlidingWindow(vector<int>& nums, int k) {
        int n = nums.size();
        vector<double> ret;

        priority_queue<Element> qL;
        priority_queue<Element, vector<Element>, greater<Element>> qR;
        int rdL = 0, rdR = 0;

        for (int i = 0; i < k; i++) {
            if (qL.empty()) {
                qL.push({ nums[i],i });
            }
            else if (qL.top().val > nums[i]) {
                qL.push({ nums[i],i });
            }
            else {
                qR.push({ nums[i],i });
            }
            while (qL.size() > qR.size() + 1) {
                qR.push(qL.top());
                qL.pop();
            }
            while (qR.size() > qL.size()) {
                qL.push(qR.top());
                qR.pop();
            }
        }

        if (k % 2 == 0) {
            ret.push_back((1.0 * qL.top().val + qR.top().val) * 0.5);
        }
        else {
            ret.push_back(qL.top().val);
        }
        for (int i = k; i < n; i++) {
            if (nums[i - k] < qL.top().val || (nums[i - k] == qL.top().val && i - k <= qL.top().idx)) {
                rdL++;
            }
            else {
                rdR++;
            }
            if (qL.top().val > nums[i]) {
                qL.push({ nums[i],i });
            }
            else {
                qR.push({ nums[i],i });
            }

            while (true) {
                if (!qL.empty() && qL.top().idx <= i - k) {
                    qL.pop();
                    rdL--;
                    continue;
                }
                if (!qR.empty() && qR.top().idx <= i - k) {
                    qR.pop();
                    rdR--;
                    continue;
                }

                int vL = qL.size() - rdL, vR = qR.size() - rdR;

                if (vL > vR + 1) {
                    auto x = qL.top();
                    qR.push(x);
                    qL.pop();
                    continue;
                }
                if (vR > vL) {
                    auto x = qR.top();
                    qL.push(x);
                    qR.pop();
                    continue;
                }
                if (vL < 0 || vR < 0) {
                    throw;
                }
                break;
            }
            if (k % 2 == 0) {
                ret.push_back((1.0 * qL.top().val + qR.top().val) * 0.5);
            }
            else {
                ret.push_back(qL.top().val);
            }
        }
        return ret;
    }
};
int main() {
    Solution s;
    vector<int> p = { 2147483647,1,2,3,4,5,6,7,2147483647 }; //
    auto k = s.medianSlidingWindow(p, 2);
    for (auto x : k) {
        cout << x << ",";
    }
    return 0;
}