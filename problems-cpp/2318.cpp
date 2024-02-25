#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    int distinctSequences(int n) {
        if (n == 1)return 6;

        using DiceSeq = int[6][6];
        const int modf = 1000000007;
        vector<vector<int>> legalAdj = {
            {1,2,3,4,5},{0,2,4},{0,1,3,4},
            {0,2,4}, {0,1,2,3,5},{0,4}
        };
        DiceSeq* f = new DiceSeq[n];
        
        //Init
        memset(f, 0, sizeof(DiceSeq) * n);
        for (int i = 0; i < 6; i++) {
            for (auto& j : legalAdj[i]) {
                f[1][i][j] = 1;
            }
        }
        int ans = 0;
        for (int k = 2; k < n; k++) {
            for (int i = 0; i < 6; i++) {
                for (auto& j : legalAdj[i]) {
                    for (auto& p : legalAdj[j]) {
                        if (i == p)continue;
                        f[k][i][j] += f[k - 1][j][p];
                        f[k][i][j] %= modf;
                    }
                }
            }
            
        }
        for (int i = 0; i < 6; i++) {
            for (auto& j : legalAdj[i]) {
                ans += f[n - 1][i][j];
                ans %= modf;
            }
        }
        return ans;
    }
};

int main() {
    Solution s;
    while (true) {
        int a;
        cin >> a;
        cout << s.distinctSequences(a) << endl;
    }
    return 0;
}