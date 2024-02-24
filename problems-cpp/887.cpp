#include <iostream>
using namespace std;

class Solution {
public:
    int superEggDrop(int k, int n) {
        int right = 1;
        int f[2][200];

        if (k == 1)return n;

        f[0][0] = 0;
        f[0][1] = 1;
        for (int i = 2;; i++) {
            f[0][i] = f[0][i - 1] + i - 1;
            right = i;
            if (f[0][i] > n)break;
        }

        for (int i = 3; i <= k; i++) {
            f[i % 2][1] = 1;
            right = 1;
            for (int j = 2;; j++) {
                f[i % 2][j] = f[i % 2][j - 1] + f[1 - i % 2][j - 1];
                right = j;
                if (f[i % 2][j] > n)break;
            }
        }
        int l = 0, r = right;
        while (l < r) {
            int mid = (l + r + 1) / 2;
            int midv = f[k % 2][mid];
            if (midv > n) {
                r = mid - 1;
            }
            else {
                l = mid;
            }
        }
        return l;
    }
};

int main() {
    Solution s;
    while (true) {
        int n, k;
        cin >> k >> n;
        cout << s.superEggDrop(k, n);
    }
    return 0;
}