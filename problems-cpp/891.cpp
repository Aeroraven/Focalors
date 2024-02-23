#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

class Solution {
public:
    int sumSubseqWidths(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        constexpr static const int modf = 1000000007;
        long long upper = 0, ubase = 1;
        long long lower = 0, lbase = 1;
        int n = nums.size();
        for (int i = 0; i < n; i++) {
            upper += ubase * nums[i];
            upper %= modf;
            ubase = (ubase * 2) % modf;
            lower += lbase * nums[n - 1 - i];
            lower %= modf;
            lbase = (lbase * 2) % modf;
        }
        return static_cast<int>(upper - lower + modf) % modf;
    }
};
int main() {
    Solution s;
    vector<int> a = { 2,1,3 };
    cout << s.sumSubseqWidths(a) << endl;
    return 0;
}