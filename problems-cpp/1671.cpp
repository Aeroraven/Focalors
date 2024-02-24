#include <iostream>
#include <vector>
#include <algorithm>
#include <cstring>
using namespace std;

class Solution {
public:
    int minimumMountainRemovals(vector<int>& nums) {
        int n = nums.size();
        int* lf = new int[n];
        int* rf = new int[n];
        //LTR
        int* seq = new int[n];
        int m = -1;
        int ans = INT_MAX;
        int loopParam[2][3] = {{0,n - 1,1},{n - 1,0,-1}};
        int* ptr[2] = { lf,rf };
        for (int k = 0; k < 2; k++) {
            m = -1;
            for (int i = loopParam[k][0]; (k==0)?(i <= loopParam[k][1]): (i >= loopParam[k][1]); i+=loopParam[k][2]) {
                if (m == -1 || nums[i] > seq[m]) {
                    seq[++m] = nums[i];
                    ptr[k][i] = m + 1;
                }
                else if (nums[i] == seq[m]) {
                    ptr[k][i] = m + 1;
                }
                else {
                    int l = 0, r = m;
                    int target = nums[i];
                    while (l < r) {
                        int mid = (l + r) / 2;
                        int midv = seq[mid];
                        if (midv < target) {
                            l = mid + 1;
                        }
                        else if (midv > target) {
                            r = mid;
                        }
                        else {
                            l = mid;
                            break;
                        }
                    }
                    seq[l] = nums[i];
                    ptr[k][i] = l + 1;
                    
                }

                if (k == 1) {
                    
                    int lis = n - (lf[i] + rf[i] - 1);
                    if (lf[i] == 1 || rf[i] == 1)continue;
                    ans = std::min(lis, ans);
                    
                }
            }
            
        }
        return ans;
    }
};


int main() {
    Solution s;
    vector<int> a = { 12,15,4,1,16,2,0,18,7,17,13,6,8,10,9,3,14,11,5,19 };

    cout << endl;
    cout << s.minimumMountainRemovals(a) << endl;
    return 0;
}