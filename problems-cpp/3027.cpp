#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

class Solution {
public:
    int numberOfPairs(vector<vector<int>>& p) {
        int n = p.size();
        sort(p.begin(), p.end(), [&](const vector<int>& a, const vector<int>& b)->bool {
            if (a[0] == b[0])return a[1] > b[1];
            return a[0] < b[0];
        });
        int ans = 0;
        for (int i = 0; i < n; i++) {
            int lim = INT_MIN;
            for (int j = i + 1; j < n; j++) {
                if (p[j][1] > p[i][1])continue;
                if (p[j][1] > lim) {
                    ans++;
                    lim = p[j][1];
                }
            }
        }
        return ans;
    }
};

int main() {
    Solution s;
    vector<vector<int>> a = { {6,2},{4,4},{2,6} };
    cout << s.numberOfPairs(a) << endl;
    return 0;
}