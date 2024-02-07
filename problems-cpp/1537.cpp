#include <vector>
#include <iostream>

class Solution {
public:
    int maxSum(std::vector<int>& nums1, std::vector<int>& nums2) {
        int n1 = nums1.size(), n2 = nums2.size();
        int cur1 = 0, cur2 = 0;
        unsigned long long ans = 0, accu1 = 0, accu2 = 0;
        constexpr static int modf = 1000000000 + 7;

        while (cur1 < n1 && cur2 < n2) {
            if (nums1[cur1] < nums2[cur2]) {
                accu1 += nums1[cur1];
                cur1++;
            }
            else if (nums1[cur1] > nums2[cur2]) {
                accu2 += nums2[cur2];
                cur2++;
            }
            else {
                ans += std::max(accu1, accu2) + nums1[cur1];
                accu1 = 0, accu2 = 0;
                cur1++; cur2++;
            }
        }
        while (cur1 < n1) {
            accu1 += nums1[cur1];
            cur1++;
        }
        while (cur2 < n2) {
            accu2 += nums2[cur2];
            cur2++;
        }
        ans += std::max(accu1, accu2);
        return ans % modf;
    }
};

int main() {
    Solution s;
    std::vector<int> a = { 1,2,3,4,5 };
    std::vector<int> b = { 6,7,8,9,10 };
    std::cout << s.maxSum(a, b);
    return 0;
}