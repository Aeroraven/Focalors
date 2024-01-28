#include <iostream>
#include <vector>
class Solution {
public:
    std::vector<int> productExceptSelf(std::vector<int>& nums) {
        int prefixProd = 1;
        int n = nums.size();
        std::vector<int> suffixProd(n);
        if (n - 1 >= 0) {
            suffixProd[n - 1] = nums[n - 1];
        }
        for (int i = n - 2; i >= 1; i--) {
            suffixProd[i] = suffixProd[i + 1] * nums[i];
        }
        for (int i = 0; i < n-1; i++) {
            suffixProd[i] = prefixProd * suffixProd[i + 1];
            prefixProd *= nums[i];
        }
        if (n - 1 >= 0) {
            suffixProd[n - 1] = prefixProd;
        }
        return suffixProd;
    }
};

int main() {
    using namespace std;
    vector<int> a = { 9,2 };
    Solution s;
    auto p = s.productExceptSelf(a);
    for (auto& x : p) {
        cout << x << ",";
    }
    return 0;
}