#include<iostream>
#include<vector>
using namespace std;

class Solution {
public:
    int firstMissingPositive(vector<int>& nums) {
        //DAMN EEEEEXTRA SPACE!
        int sL = nums.size();

        // Reset useless numbers
        for (int i = 0; i < sL; i++) {
            if (nums[i]<0 || nums[i]>sL) {
                nums[i] = 0;
            }
        }
        // Mark numbers
        for (int i = 0; i < sL; i++) {
            if (nums[i] <= 0) {
                continue;
            }
            int cur = i;
            int idx = nums[cur] - 1;
            while (nums[idx] > 0) {
                int tmp = nums[idx];
                nums[idx] = -1;
                idx = tmp - 1;
            }
            nums[idx] = -1;
        }

        // Find answer
        int answ = sL + 1;
        for (int i = 1; i <= sL; i++) {
            if (nums[i - 1] == -1) {
                continue;
            }
            return i;
        }
        return answ;
    }
};

int main() {
    int n;
    Solution s;
    while (true) {
        vector<int> x;
        int w;
        cin >> n;
        for (int i = 0; i < n; i++) {
            cin >> w;
            x.push_back(w);
        }
        cout << s.firstMissingPositive(x) << endl;
    }
	return 0;
}