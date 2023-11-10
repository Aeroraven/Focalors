#include <iostream>
#include <vector>
#include <cstdlib>

using namespace std;

class Solution {
public:
    int trap(vector<int>& height) {
        int* leftMax = new int[height.size()];
        int* rightMax = new int[height.size()];
        int lm = -1, rm = -1;

        for (auto i = 0; i < height.size(); i++) {
            lm = max(lm, height[i]);
            leftMax[i] = lm;
        }
        for (auto i = height.size() - 1; true; i--) {
            rm = max(rm, height[i]);
            rightMax[i] = rm;
            if (i == 0) {
                break;
            }
        }
        int ans = 0;
        for (auto i = 0; i < height.size(); i++) {
            ans += min(leftMax[i], rightMax[i]) - height[i];
        }
        return ans;
    }
};

int main() {
    Solution* s = new Solution();
    std::vector<int> a = { 0,2,14,5,34,30,4,21,0,6,18,35,3,15,0,3,7,20,5,13,38,6,20,16,9,10,7,19,16,10,15,22,39,0,5,12,25,1,22,33,26,6,26,1,17,20,10,40,17,5,36,36,34,29,25,6,30,19,23,21,22,40,32,13,6,13,6,16,19,13,14,5,4,29,7,37,39,23,36,10,15,4,7,10,38,30,28,8,27,30,15,31,13,37,34,11,36,6,3,0,1,22,27,15,37,20,23,25,13,10,5,23,4,0,9,15,22,6,27,1,8,18,4,28,11,22,21,29,13,8,38,1,9,35,7,34,29,1,33,35,35,14,13,16,1,19,29,38,37,7,28,37,17,7,12,11,7,2,29,6,18,23,21,28,18,25,25,23,24,30,24,39,40,25,36,3,16,34,26,6,8,29,32,4,30,21,8,37,6,37,23,26,31,14,39,35,14,38,8,19,39,0,36,16,34,1,34,1,27,40,10,11,9,40,13,1,22,15,19,7,13,25,5,11,13,11,4,26,36,29,19,11,23,34,32,2,9,21,3,26,32,11,7,38,39,11,18,16,8,11,21,23,6,0,37,34,34,31,3,10,34,3,8,23,29,40,39,16,4,4,29,12,18,5,40,20,13,0,39,0,36,29,22,8,38,5,9,6,38,22,19,7,25,40,8,39,40,10,25,4,10,8,5,38,4,34,6,21,35,2,15,27,22,32,15,21,4,6,11,14,5,17,4,13,38,37,7,24,30,32,23,21,15,2,15,25,27,28,3,38,34,33,7,18,25,9,3,2,40,21,37,5,3,9,18,2,27,4,10,0,24,3,16,7,22,16,26,1,12,23,7,39,21,16,22,29,16,9,22,7,20,40,37,18,23,24,16,38,29,31,24,18,37,13,19,17,34,18,27,39 };
    std::cout << (s->trap(a)) << std::endl;
    return 0;
}