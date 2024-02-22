#include <iostream>
#include <vector>
#include <unordered_map>
using namespace std;

class MountainArray {
public:
    vector<int> w;
    MountainArray(vector<int> a) {
        w = a;
    }
    int get(int index) {
        return w[index];
    }
    int length() {
        return w.size();
    }
    
};

class Solution {
public:
    int findInMountainArray(int target, MountainArray& mountainArr) {
        int peak;
        int n = mountainArr.length();
        int l = 0, r = n - 1;
        int maxv = 0;
        //Find the peak
        while (l < r) {
            if (r == l + 1) {
                int lmv = mountainArr.get(l);
                int rmv = mountainArr.get(r);
             
                maxv = std::max(lmv, rmv);

                if (lmv > rmv) {
                    peak = l;
                    if (lmv == target)return l;
                    break;
                }
                else {
                    peak = r;
                    if (rmv == target)return r;
                    break;
                }
            }
            else {
                int mid = (l + r) / 2;
                int lmid = mid - 1;
                int rmid = mid + 1;
                int lmv = mountainArr.get(lmid);
                int rmv = mountainArr.get(rmid);

                if (lmv == rmv) {
                    l = lmid + 1;
                    r = rmid - 1;
                    peak = l;
                    if (mountainArr.get(l) == target) {
                        return peak;
                    }
                }
                else if (lmv > rmv) {
                    r = rmid - 1;
                }
                else {
                    l = lmid + 1;
                }
            }
        }
        //Find in Left Part
        l = 0, r = peak - 1;
        while (l < r) {
            int mid = (l + r) / 2;
            int val = mountainArr.get(mid);
            if (target > val) {
                l = mid + 1;
            }
            else if (target < val) {
                r = mid - 1;
            }
            else {
                return mid;
            }
        }
        if (mountainArr.get(l) == target)return l;

        //Find in Right Part
        l = peak + 1, r = n - 1;
        while (l < r) {
            int mid = (l + r) / 2;
            int val = mountainArr.get(mid);
            if (target > val) {
                r = mid - 1;
            }
            else if (target < val) {
                l = mid + 1;
            }
            else {
                return mid;
            }
        }
        if (mountainArr.get(l) == target)return l;
        return -1;
    }
};

int main() {
    Solution s;
    MountainArray m({ 3,5,3,2,0 });
    cout << s.findInMountainArray(5,m) << endl;
    return 0;
}