#include <iostream>
#include <vector>
#include <deque>
using namespace std;

class Solution {
public:
    int constrainedSubsetSum(vector<int>& nums, int k) {
        int* f = new int[nums.size()+1];
        memset(f, 0, sizeof(int) * (nums.size()+1));
        int ans = INT_MIN;
        deque<int> cands;
        for (int i = 0; i < nums.size(); i++) {
            int lastBest = 0;
            while (!cands.empty()) {
                if (i - cands.front() > k) {
                    cands.pop_front();
                    continue;
                }
                break;
            }
            if (!cands.empty()) {
                lastBest = f[cands.front()];
            }
            f[i] = lastBest + nums[i];
            ans = std::max(f[i], ans);
            if (f[i]>0) {
                while (!cands.empty()) {
                    if (f[i] >= f[cands.back()]) {
                        cands.pop_back();
                        continue;
                    }
                    break;
                }
                cands.push_back(i);
            }
        }
        return ans;
    }
};

int main() {
    Solution s;
    vector<int> x = { 10,-2,-10,-5,20 };
    cout << s.constrainedSubsetSum(x, 2) << endl;
    return 0;
}