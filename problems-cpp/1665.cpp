#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;

class Solution {
public:
    int minimumEffort(vector<vector<int>>& tasks) {
        auto cmp = [&](const vector<int>& a, const vector<int>& b)->bool {
            int lA = a[1] - a[0], lB = b[1] - b[0];
            if (lA == lB) {
                return a[1] > b[1];
            }
            else {
                return lA > lB;
            }
        };
        sort(tasks.begin(), tasks.end(), cmp);
        int ans = 0, cur = 0;
        for (int i = 0; i < tasks.size(); i++) {
            if (cur < tasks[i][1]) {
                ans += (tasks[i][1] - cur);
                cur = tasks[i][1];
                cur -= tasks[i][0];
            }
            else {
                cur -= tasks[i][0];
            }
        }
        return ans;

    }
};

int main() {
    Solution s;
    vector<vector<int>> a = { {1,7},{2,8},{3,9},{4,10},{5,11},{6,12} };
    cout << s.minimumEffort(a) << endl;
    return 0;
}