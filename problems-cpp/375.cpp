#include <iostream>
#include <cstdlib>
#include <algorithm>
using namespace std;
class Solution {
public:
    int getMoneyAmount(int n) {
        int* vf = new int[(n + 1) * (n + 1)];
#define f(l,r) vf[(l)*(n+1)+(r)]

        for (int i = 1; i <= n; i++) {
            f(i, i) = 0;
        }
        for (int i = 2; i <= n; i++) {
            for (int l = 1; l <= (n - i+1); l++) {
                int r = l + i - 1;
                f(l, r) = INT_MAX;
                for (int k = l; k <= r; k++) {
                    int rightCost = (k == r) ? 0 : f(k + 1, r);
                    int leftCost = (k == l) ? 0 : f(l, k - 1);
                    if (leftCost > 10000 || rightCost > 10000) {
                        throw;
                    }
                    f(l, r) = min(f(l, r), max(leftCost, rightCost) + k);
                }
            }
        }
        return f(1, n);
    }
};
int main() {
    Solution s;
    while (true) {
        int n;
        cin >> n;
        cout << s.getMoneyAmount(n) << endl;
    }
    return 0;
}