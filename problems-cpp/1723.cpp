#include <iostream>
#include <vector>
#include <cstring>
#include <functional>
using namespace std;

class Solution {
public:
    int minimumTimeRequired(vector<int>& jobs, int k) {
        int n = jobs.size();
        int totlState = (1 << n);
        constexpr static const int MAXV = INT_MAX / 2;
        int* g = new int[1 << n];
        int* vf = new int[k * (1 << n)];
        memset(vf, 0x7a, sizeof(int) * k * (1 << n));
#define f(x,y) (vf[(x)*totlState+(y)])
        std::function<void(int, int, int)> dfs = [&](int x, int state, int val)->void {
            if (x == n) {
                g[state] = val;
                return;
            }
            dfs(x + 1, state, val);
            dfs(x + 1, state | (1 << x), val + jobs[x]);
        };
        dfs(0, 0, 0);
        f(0,0) = MAXV;
        for (int i = 1; i < totlState; i++) {
            f(0,i) = g[i];
        }
        for (int i = 1; i < k; i++) {
            f(i, 0) = MAXV;
            for (int j = 1; j < totlState; j++) {
                for (int s = (j - 1) & j; s != 0; s = ((s - 1) & j)) {
                    int curWorker = s;
                    int preWorker = j & (~s);
                    if (curWorker != 0 && preWorker != 0) {
                        if (f(i - 1, preWorker) < 0) {
                            throw;
                        }
                        f(i,j) = std::min(f(i, j),std::max( f(i-1,preWorker) , g[s]));
                    }
                }
            }

        }
        return f(k - 1, totlState - 1);
    }
};

int main() {
    Solution s;
    vector<int> p = { 3,2,3 };
    cout << s.minimumTimeRequired(p, 2) << endl;
    return 0;
}