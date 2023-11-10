#include <iostream>
#include <algorithm>
#include <vector>
#include <deque>
#include <cmath>
#include <cstdlib>
using namespace std;

class Solution {
public:
    int consecutiveNumbersSum(int n) {
        int sq = sqrt((2ll * n)), res = 0, n2 = n * 2;
        for (int i = 1; i <= sq; i++) {
            if (n2 % i == 0) {
                int lx = (n2 / i - i + 1);
                if (lx % 2 == 0) {
                    int l = lx / 2;
                    if (l <= 0)return res;
                    res++;
                }
            }
        }
        return res;
    }
};

int main() {
    Solution sol;
    int x;
    cin >> x;
    cout << sol.consecutiveNumbersSum(x) << endl;
}