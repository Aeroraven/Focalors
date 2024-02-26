#include <iostream>
#include <vector>
using namespace std;
class Solution {
public:
    int numberWays(vector<vector<int>>& hats) {
        //Dispatch People to Hats == Dispatch Hats to People OvO
        vector<vector<int>> mp(40);
        int n = hats.size();
        int tot = (1 << n);
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < hats[i].size(); j++) {
                mp[hats[i][j]-1].push_back(i);
            }
        }

        int f[40][1024];
        memset(f, 0, sizeof(f));
        f[0][0] = 1;
        for (int i = 0; i < mp[0].size(); i++) {
            f[0][1 << mp[0][i]] = 1;
        }

        for(int h=1;h<40;h++){

            for (int i = 0; i < tot; i++) {
                f[h][i] = f[h - 1][i];

                for (auto& j : mp[h]) {
                    int chat = (1 << j);
                    if ((i | chat) != i) continue;
                    int prev = i & (~chat);
                    f[h][i] += f[h - 1][prev];
                    f[h][i] %= 1000000007;
                }
            }
        }
        return f[39][tot - 1];
    }
};

int main() {
    Solution s;
    vector<vector<int>> x = { {3,4},{4,5},{5} };
    cout << s.numberWays(x) << endl;
    return 0;
}