#include <vector>
#include <unordered_map>
#include <iostream>
#include <map>
using namespace std;


class Solution {
public:
    int numberOfArithmeticSlices(vector<int>& nums) {
        int ans = 0;
        int n = nums.size();
        vector<unordered_map<long long, int>> f(n);
        for (int i = 1; i < n; i++) {
            for (int j = 0; j < i; j++) {
                long long d = (long long)(nums[i]) - (long long)nums[j];
                f[i][d] += 1;

                if (f[j].count(d)) {
                    auto last = f[j][d];
                    ans += last;
                    f[i][d] += last;
                }
            }
        }
        return ans;
    }
};

int main() {
    Solution s;
    vector<int> a = { 0,2000000000,-294967296 };
    cout << s.numberOfArithmeticSlices(a) << endl;
    return 0;
}