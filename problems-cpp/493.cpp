#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    int mergeSort(vector<int>& a,vector<int>& dest, int l, int r) {
        if (l == r) {
            return 0;
        }
        int mid = (l + r) / 2;
        int lv = mergeSort(a,dest, l, mid);
        int rv = mergeSort(a,dest, mid + 1, r);
        int lpos = l, rpos = mid+1, rtwpos = mid+1;
        int cur = l;
        int ans = 0;
        while (lpos<=mid&&rpos<=r) {
            if (a[lpos] <= a[rpos]) {
                while (rtwpos <= r && a[lpos] > 2ll * a[rtwpos]) {
                    rtwpos++;
                }
                dest[cur++] = a[lpos++];
                ans += (rtwpos - mid - 1);
            }
            else {
                dest[cur++] = a[rpos++];
            }
        }
        while (lpos <= mid) {

            while (rtwpos <= r && a[lpos] > 2ll * a[rtwpos]) {
                rtwpos++;
            }
            dest[cur++] = a[lpos++];
            ans += (rtwpos - mid - 1);
        }
        while (rpos <= r) {
            dest[cur++] = a[rpos++];
        }
        std::copy(dest.begin() + l, dest.begin() + r + 1, a.begin() + l);
        return ans + lv + rv;
    }
    int reversePairs(vector<int>& nums) {
        int n = nums.size();
        vector<int> temp(n);
        int v = mergeSort(nums, temp, 0, n - 1);
        return v;
    }
};

int main() {
    Solution s;
    vector<int> p = { 2,4,3,5,1 };
    cout<< s.reversePairs(p);
    return 0;
}