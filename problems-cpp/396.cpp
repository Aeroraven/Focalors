#include <iostream>
#include <vector>
using namespace std;
class Solution {
public:
    int maxRotateFunction(vector<int>& nums) {
        using ll = long long;
        int p = 0, s = 0, ans = 0;
        int n = nums.size();
        for (int i = 0; i < n; i++) {
            s += nums[i];
            p += i * nums[i];
        }
        ans = p;
        for (int i = 0; i < n; i++) {
            p -= nums[(n - 1 - i)] * n;
            p += s;
            ans = max(p, ans);
        }
        return ans;
    }
};
int main() {
    Solution s;
    vector<int> a = { 4,3,2,6 };
    cout << s.maxRotateFunction(a) << endl;
    return 0;
}