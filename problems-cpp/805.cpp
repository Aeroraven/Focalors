#include <iostream>
#include <vector>
#include <functional>
#include <unordered_set>

using namespace std;

class Solution {
public:
    vector<unordered_set<int>> leftPart = vector<unordered_set<int>>(30);
    int sumAll = 0;

    void dfsLeft(int x, int k,int val, int r, vector<int>& nums) {
        if (x == r + 1) {
            leftPart[k].insert(val);
            return;
        }
        dfsLeft(x + 1, k, val, r, nums);
        dfsLeft(x + 1, k + 1, val + nums[x], r, nums);
    }
    bool dfsRight(int x, int k, int val, int r, vector<int>& nums) {
        if (x == r + 1) {
            //Choose p numbers from the arrray, already taken k from the right, require p-k from the left
            //Sum should be All/n*p => N*sum should be All*p = N*(left[p-k]+right[k])
            //left[p-k] = (All*p-N*right[k])/N
            for (int p = std::max(1,k); p < nums.size(); p++) {
                int numo = sumAll * p - nums.size() * val;
                if (numo % nums.size() == 0) {
                    int dval = numo / nums.size();
                    if (leftPart[p - k].count(dval)) {
                        return true;
                    }

                }
            }

            return false;
        }
        auto lp = dfsRight(x + 1, k, val, r, nums);
        auto rp = dfsRight(x + 1, k + 1, val + nums[x], r, nums);
        return lp || rp;
    }

    bool splitArraySameAverage(vector<int>& nums) {
        for (int i = 0; i < nums.size();i++) {
            sumAll += nums[i];
        }
        int mid = (nums.size()-1) / 2;
        dfsLeft(0, 0, 0, mid, nums);
        auto val = dfsRight(mid + 1, 0, 0, nums.size() - 1, nums);
        return val;
    }
};


int main() {
    Solution s;
    vector<int> a = { 1,2,3,4,5,6,7,8 };
    
    cout << s.splitArraySameAverage(a) << endl;
    return 0;
}