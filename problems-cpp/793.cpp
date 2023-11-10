#include <iostream>
#include <algorithm>
#include <vector>
#include <deque>
#include <cmath>
#include <cstdlib>
using namespace std;


class Solution {
public:
    int findFactors(int x) {
        int level = 1, res = 0;
        while (x) {
            res += x / level;
            x /= 5;
        }
        return res;
    }
    int preimageSizeFZF(int k) {
        int l = 0, r = k, p = -1;
        while (l <= r) {
            int mid = (l + r) >> 1;
            int midv = findFactors(mid);
            if (midv < k) {
                l = mid + 1;
            }
            else if (midv > k) {
                r = mid - 1;
            }
            else {
                p = mid;
                break;
            }
        }
        return (p == -1) ? 0 : 5;
    }
};

int main() {
    int a;
    Solution s;
    cin >> a;
    cout << s.preimageSizeFZF(a) << endl;
    cout << s.findFactors(a) << endl;
    return 0;
}