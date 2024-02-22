#include <cstring>
#include <iostream>
using namespace std;

class Solution {
public:
    int check(int n) {
        int digits = 0;
        for (int i = 0; i <= 31; i++) {
            if ((1 << i) > n) {
                digits = i + 1;
                break;
            }
        }
        for (int i = 0; i < digits - 2;i++) {
            int lm = n & (1 << i);
            int rm = n & (1 << (i + 1));
            if (lm && rm) {
                return 0;
            }
        }
        return 1;
    }
    int plainCheck(int n) {
        int ans = 0;
        for (int i = 0; i <= n; i++) {
            ans += check(i);
        }
        return ans;
    }
    int findIntegers(int n) {
        if (n == 0)return 1;
        if (n == 1)return 2;

        int digits = 0;
        for (int i = 0; i <= 31; i++) {
            if ((1ll << i) > n) {
                digits = i + 1;
                break;
            }
        }
        using Rec = int[2];
        Rec* f = new Rec[digits + 1];
        memset(f, 0, sizeof(Rec) * (digits + 1));
        f[0][0] = 1;
        f[0][1] = 1;
        for (int i = 1; i < digits - 1; i++) {
            f[i][0] = f[i - 1][0] + f[i - 1][1];
            f[i][1] = f[i - 1][0];
        }
        
        int ans = 1;
        for (int i = digits - 2; i >= 0; i--) {
            if (n&(1ll<<i)) {
                ans += f[i][0];
                if (n&(1ll<<(i+1))) {
                    ans--;
                    break;
                }
            }
        }

        return ans;
    }
};
int main() {
    Solution s;
    for (int i = 0; i < 5000; i++) {
        int l = s.plainCheck(i);
        int r = s.findIntegers(i);
        if (l != r) {
            throw;
        }
        cout << "I=" << i << " STD:" << l << " ANS:" << r << endl;
    }
    return 0;
}