#include <iostream>
#include <vector>
#include <functional>
using namespace std;
#define MOD 1000000007

class Solution {
public:
    int colorTheGrid(int m, int n) {
        const int base[6] = { 1,3,9,27,81,243 };
        vector<int> validStates;
        vector<vector<int>> validTrans;
        function<void(int, int,int)> dfs = [&](int x, int total, int last) {
            if (x == m) {
                validStates.push_back(total);
                return;
            }
            for (int i = 0; i < 3; i++) {
                if (i != last) {
                    dfs(x + 1, total + base[x] * i, i);
                }
            }
        };
        dfs(0, 0, -1);
        validTrans.reserve(validStates.size());
        validTrans.resize(validStates.size());
        for (int i = 0; i < validStates.size(); i++) {
            for (int j = 0; j < validStates.size(); j++) {
                bool flag = true;
                for (int k = 0; k < m; k++) {
                    int da = (validStates[i] / base[k]) % 3;
                    int db = (validStates[j] / base[k]) % 3;
                    if (da == db)flag = false;
                }
                if (flag) {
                    validTrans[i].push_back(validStates[j]);
                }
            }
        }
        int f[2][500];
        memset(f, 0, sizeof(f));
        for (auto p : validStates) {
            f[1][p] = 1;
        }
        for (int i = 2; i <= n; i++) {
            for (int j = 0; j < validStates.size();j++) {
                f[i % 2][validStates[j]] = 0;
                for (auto k : validTrans[j]) {
                    f[i % 2][validStates[j]] += f[(i + 1) % 2][k];
                    f[i % 2][validStates[j]] %= MOD;
                }
            }
        }

        int ans = 0;
        for (int i = 0; i < validStates.size(); i++) {
            ans += f[n % 2][validStates[i]];
            ans %= MOD;
        }
        return ans;
    }
};

int main() {
    Solution s;
    while (true) {
        int n, k;
        cin >> n >> k;
        cout << s.colorTheGrid(n, k) << endl;
    }
    return 0;
}