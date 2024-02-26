#include <unordered_map>
#include <iostream>
#include <vector>
#include <functional>
#include <unordered_set>
using namespace std;

class Solution {
public:
    int numSquarefulPerms(vector<int>& nums) {
        int n = nums.size();
        int totlState = (1 << n);
        unordered_map<int, int> precReq;
        unordered_set<int> sqNums;
        for (int i = 0; i < 44721; i++) {
            sqNums.insert(i * i);
        }

        // When numbers are duplicated like [2,2,2], 
        // they should be chosen from the first one at first.
        int* pReq = new int[n];
        for (int i = 0; i < n; i++) {
            if (precReq.count(nums[i]) == 0) {
                precReq[nums[i]] = 0;
            }
            pReq[i] = precReq[nums[i]];
            precReq[nums[i]] |= (1 << i);
        }

        vector<vector<int>> base(13);
        function<void(int,int, int)> dfs = [&](int x, int cnt, int state)->void {
            if (x == n) {
                base[cnt].push_back(state);
                return;
            }
            dfs(x + 1, cnt, state);
            dfs(x + 1, cnt + 1, state | (1 << x));
        };
        dfs(0, 0, 0);

        int f[13][1024];
        
        //Init
        for (int i = 0; i < n; i++) {
            if (pReq[i] != 0)f[i][1 << i] = 0;
            else f[i][1 << i] = 1;
        }
        for (int k = 2; k <= n; k++) {
            for (auto& s : base[k]) {
                for (int i = 0; i < n; i++) {
                    f[i][s] = 0;
                    if ((s & pReq[i]) != pReq[i])continue;
                    if ((s | (1 << i)) != s)continue;
                    int curMask = (1 << i);
                    int preMask = s & (~curMask);
                    
                    for (int j = 0; j < n; j++) {
                        if (sqNums.count(nums[i] + nums[j])) {
                            f[i][s] += f[j][preMask];
                        }
                    }
                }
            }
        }

        int ans = 0;
        for (int i = 0; i < n; i++) {
            ans += f[i][totlState - 1];
        }
        return ans;
    }
};

int main() {
    Solution s;
    vector<int> a = { 1,17,8 };
    cout << s.numSquarefulPerms(a) << endl;
    return 0;
}