#include <iostream>
#include <vector>
#include <cstring>
using namespace std;

class Solution {
public:
    int maximumScore(vector<int>& nums, vector<int>& multipliers) {
        int n = multipliers.size();
        int m = nums.size();
        int* vf = new int[2 * (n + 1)];
#define f(x,y) vf[((x)%2)+(y)*2]
        memset(vf, 0, sizeof(int) * 2 * n);
        for (int i = 1; i <= n; i++) {
            for (int j = 0; j <= i; j++) {
                f(i, j) = INT_MIN;
                if (j <= i - 1) {
                    int totalFetchRight = i - 1 - j;
                    int right = m - (totalFetchRight)-1;
                    cout << i << "/" << j << "," << nums[right] << "," << right << endl;
                    int v = nums[right] * multipliers[i - 1];
                    f(i, j) = f(i - 1, j) + v;
                }
                else if (j > 0) {
                    f(i, j) = std::max(f(i, j), f(i - 1, j - 1) + nums[j - 1] * multipliers[i - 1]);
                }
                else {
                    throw;
                }
            }
        }
        int ans = INT_MIN;
        for (int i = 0; i <= n; i++) {
            ans = max(ans, f(n, i));

        }
        return ans;
    }
};

int main() {
    Solution s;
    vector<int> x = { -5,-3,-3,-2,7,1 };
    vector<int> p = { -10,-5,3,4,6 };
    cout << s.maximumScore(x, p) << endl;
    return 0;

}