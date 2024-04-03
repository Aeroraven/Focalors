#include <iostream>
#include <vector>
using namespace std;
class Solution {
public:
    int gcd(int a, int b) {
        if (b == 0)return a;
        return gcd(b, a % b);
    }
    bool isGoodArray(vector<int>& nums) {
        if (nums.size() == 1) {
            return std::abs(nums[0]) == 1;
        }
        int init = gcd(nums[0], nums[1]);
        for (int i = 2; i < nums.size(); i++) {
            init = gcd(init, nums[i]);
            if (init == 1)return true;
        }
        return init == 1; 
    }
};

int main() {
    vector<int> a = { 15,15,15,18,35,35,42,42,7 };
    Solution s;
    cout << s.isGoodArray(a) << endl;
    return 0;
}