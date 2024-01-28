#include <iostream>
#include <vector>

class Solution {
public:
    void rotateSwap(int& a, int& b) {
        int t = a;
        a = b;
        b = t;
    }

    void rotateImpl(std::vector<int>& a, int k, int n) {
        if (k == 0)return;
        int rounds = n / k;
        int remain = n % k;
        for (int i = 1; i < rounds; i++) {
            for (int j = 0; j < k; j++) {
                rotateSwap(a[j], a[i * k + j]);
            }
        }
        for (int i = 0; i < remain; i++) {
            rotateSwap(a[i], a[k * rounds + i]);
        }
        rotateImpl(a, (k - remain) % k, k);
    }

    void rotate(std::vector<int>& nums, int k) {
        rotateImpl(nums, k% nums.size(), nums.size());
    }
};

int main() {
    using namespace std;
    vector<int> nums = { 1,2 };
    int k = 19;
    Solution s;
    s.rotate(nums, k);
    for (auto& p : nums) {
        cout << p << ",";
    }
    return 0;
}