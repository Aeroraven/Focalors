#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    bool validPartition(vector<int>& nums) {
        int n = nums.size();
        bool* vf = new bool[n + 1];
        memset(vf, 0, sizeof(bool) * (n + 1));
#define f(x) vf[(x)+1]
        f(-1) = true;
        for (int i = 0; i < n; i++) {
            if (i >= 1) {
                int b = nums[i], a = nums[i - 1];
                if (b == a) {
                    f(i) |= f(i - 2);
                }
            }
            if (i >= 2) {
                int c = nums[i], b = nums[i - 1], a = nums[i - 2];
                if (c == b && b == a) {
                    f(i) |= f(i - 3);
                }
                if (c - b == 1 && b - a == 1) {
                    f(i) |= f(i - 3);
                }
            }
        }
        return f(n - 1);
    }
};

int main() {
    Solution s;
    vector<int> a = { 1,1,2,3,4 };
    cout << s.validPartition(a) << endl;
    return 0;
}