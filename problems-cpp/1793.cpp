#include <vector>
#include <iostream>
using namespace std;
class Solution {
public:
    int maximumScore(vector<int>& nums, int k) {
        int n = nums.size();
        int minv = nums[k], ans = nums[k], lcur = k - 1, rcur = k + 1;
        for (int i = 1; i < n; i++) {
            int lp = (lcur >= 0) ? nums[lcur] : INT_MIN;
            int rp = (rcur < n) ? nums[rcur] : INT_MIN;
            if (lp > rp) {
                minv = std::min(lp, minv);
                lcur--;
            }
            else {
                minv = std::min(rp, minv);
                rcur++;
            }
            ans = std::max(minv * (i + 1), ans);
        }
        return ans;
    }
};

int main() {
    Solution s;
    vector<int> a = { 5,5,4,5,4,1,1,1 };
    cout << s.maximumScore(a, 0);
    return 0;
}