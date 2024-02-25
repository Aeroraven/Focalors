#include <iostream>
#include <vector>
#include <cstring>
using namespace std;

class Solution {
public:
    int minSwap(vector<int>& nums1, vector<int>& nums2) {
        int n = nums1.size();
        int* vf = new int[2 * n];
#define f(x,y) vf[(x)*2+(y)]

        f(0, 0) = 0;
        f(0, 1) = 1;
        constexpr static const int mv = INT_MAX >> 1;
        for (int i = 1; i < n; i++) {
            f(i, 0) = mv;
            f(i, 1) = mv;
            if (nums1[i-1] < nums1[i] && nums2[i-1] < nums2[i]) {
                f(i, 0) = std::min(f(i, 0), f(i - 1, 0));
            }
            if (nums2[i - 1] < nums1[i] && nums1[i - 1] < nums2[i]) {
                f(i, 0) = std::min(f(i, 0), f(i - 1, 1));
            }
            if (nums1[i - 1] < nums2[i] && nums2[i - 1] < nums1[i]) {
                f(i, 1) = std::min(f(i, 1), f(i - 1, 0) + 1);
            }
            if (nums2[i - 1] < nums2[i] && nums1[i - 1] < nums1[i]) {
                f(i, 1) = std::min(f(i, 1), f(i - 1, 1) + 1);
            }
        }
        return std::min(f(n - 1, 1), f(n - 1, 0));
    }
};

int main() {
    Solution s;
    vector<int> a = { 5,2,3,8 };
    vector<int> b = { 1,6,7,4 };
    cout << s.minSwap(a, b);
    return 0;
}