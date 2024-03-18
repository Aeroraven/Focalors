#include <iostream>
#include <vector>
#include <cstring>
#include <cmath>
using namespace std;

class Solution {
public:
    long long sellingWood(int m, int n, vector<vector<int>>& prices) {
        using ll = long long;
        m++;
        n++;
        ll* vf = new ll[m * n];
        memset(vf, 0, sizeof(ll) * m * n);
#define f(x,y) (vf[(x)*n+(y)])
        for (auto& b : prices) {
            f(b[0], b[1]) = b[2];
        }
        for (int i = 1; i < m; i++) {
            for (int j = 1; j < n; j++) {
                for (int k = 1; k < j; k++) {
                    f(i, j) = std::max(f(i, j), f(i, k) + f(i, j - k));
                }
                for (int k = 1; k < i; k++) {
                    f(i, j) = std::max(f(i, j), f(k, j) + f(i - k, j));
                }
            }
        }
        return f(m - 1, n - 1);
    }
};

int main() {
    vector<vector<int>> a = { {3,2,10},{1,4,2},{4,1,3} };
    Solution s;
    cout << s.sellingWood(4, 6, a) << endl;
    return 0;
}