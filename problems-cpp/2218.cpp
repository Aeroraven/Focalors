#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    int maxValueOfCoins(vector<vector<int>>& piles, int k) {
        //F[i][j] Max value that can be obtained after fetching from pile i and Remain j chances
        //F[i][j] = F[i-1][k] + Sum[0...k-j] (for k>j) => scroll

        int f[2][2001];
        for (int i = 0; i < k; i++)f[1][i] = INT_MIN;
        f[1][k] = 0;
        for (int i = 0; i < piles.size(); i++) {
            for (int j = 1; j < piles[i].size(); j++) {
                piles[i][j] = piles[i][j - 1] + piles[i][j];
            }
        }
        for (int i = 0; i < piles.size(); i++) {
            for (int j = 0; j <= k; j++) {
                f[i % 2][j] = INT_MIN;
                for (int d = j; d <= std::min(k, static_cast<int>(j + piles[i].size())); d++) {
                    int fetch = d - j;
                    int fetv = (fetch) ? piles[i][fetch - 1] : 0;
                    f[i % 2][j] = std::max(f[i % 2][j], f[(i + 1) % 2][d] + fetv);
                }
            }
        }
        return f[(piles.size() - 1) % 2][0];
    }
};

int main() {
    Solution s;
    vector<vector<int>> a = { {1,100,3},{7,8,9} };
    cout << s.maxValueOfCoins(a, 2) << endl;
    return 0;
}