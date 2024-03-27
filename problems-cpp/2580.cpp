#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
class Solution {
public:
    int countWays(vector<vector<int>>& ranges) {
        int groups = 0;
        int solutions = 1;
        const int MODF = 1000000007;
        std::sort(ranges.begin(), ranges.end(), [](const vector<int>& a, const vector<int>& b) {
            return (a[0] < b[0]) || ((a[0] == b[0]) && (a[1] < b[1]));
        });
        int r = -1;
        for (const auto& p : ranges) {
            if (p[0] > r) {
                groups++;
                solutions *= 2;
                solutions %= MODF;
            }
            r = std::max(r, p[1]);
        }
        //solutions = (solutions - 2 + MODF) % MODF;
        return solutions;
    }
};

int main() {
    Solution s;
    vector<vector<int>> p = { {1,3},{10,20},{2,5},{4,8} };
    cout << s.countWays(p) << endl;
    return 0;
}