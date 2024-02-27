#include <algorithm>
#include <vector>
#include <iostream>
using namespace std;

class Solution {
public:
    int sumOfPower(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        long long accu = 0;
        int ans = 0;
        const int MOD = 1000000007;
        for (int i = 0; i < nums.size(); i++) {
            long long cpw = nums[i] * nums[i];
            cpw %= MOD;
            cpw *= (accu + nums[i]);
            cpw %= MOD;

            ans += cpw;
            ans %= MOD;

            accu *= 2;
            accu %= MOD;
            accu += nums[i];
            accu %= MOD;
        }
        return ans;
    }
};

int main() {
    Solution s;
    vector<int> a = { 1,1,1 };
    cout << s.sumOfPower(a) << endl;
    return 0;
}