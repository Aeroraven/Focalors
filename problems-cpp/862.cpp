#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    int shortestSubarray(vector<int>& nums, int k) {
        int n = nums.size();
        long long accu = 0;
        long long* psum = new long long[n];
        int* deq = new int[n];
        int ans = 10000000;
        int lcur = 0, rcur = -1;

        for (int i = 0; i < n; i++) {
            accu += nums[i];
            psum[i] = accu;

            // Require psum[i]-psum[j]>=k, length=(i-j)
            // Find the optimal k
            while (lcur<=rcur) {
                if (i - deq[lcur] > ans) {
                    lcur++;
                    continue;
                }
                break;
            }

            if (accu >= k) {
                ans = std::min(ans, i + 1);
            }

            //When the array does not start form the first element
            if (lcur <= rcur) {
                int l = lcur, r = rcur;
                while (l < r) {
                    int mid = (l + r + 1) / 2;
                    long long midv = psum[deq[mid]];
                    if (psum[i] - midv >= k) {
                        l = mid;
                    }
                    else {
                        r = mid - 1;
                    }
                }
                if (psum[i] - psum[deq[l]]>=k) {
                    ans = std::min(i - deq[l], ans);
                }
            }

            // Prepare for the next
            while (lcur <= rcur) {
                if (psum[i] < psum[deq[rcur]]) {
                    rcur--;
                    continue;
                }
                break;
            }
            deq[++rcur] = i;
        }
        if (ans == 10000000)return -1;
        return ans;
    }
};

int main() {
    Solution s;
    vector<int> x = { 17,85,93,-45,-21 };
    cout << s.shortestSubarray(x, 150) << endl;
    return 0;
}