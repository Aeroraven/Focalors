#include <vector>
#include <stack>
#include <iostream>
using namespace std;

class Solution {
public:
    vector<int> secondGreaterElement(vector<int>& nums) {
        int n = nums.size(), stp = 0;
        vector<int> ret(n, -1), st(n);
        stack<int> second;
        for (int i = 0; i < n; i++) { 
            while (!second.empty() && nums[i] > nums[second.top()]) {
                ret[second.top()] = nums[i];
                second.pop();
            }
            int rep = stp;
            while (stp > 0 && nums[st[stp - 1]] < nums[i]) {
                stp--;
            }
            for (int j = stp; j < rep; j++) {
                second.push(st[j]);
            }
            st[stp++] = i;
            
        }
        return ret;
    }
};

int main() {
    Solution s;
    vector<int> a = { 3,3,3,3,3,3,3,3,3,3,3 };
    auto p = s.secondGreaterElement(a);
    for (auto x : p) {
        cout << x << ",";
    }
    return 0;
}