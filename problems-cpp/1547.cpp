#include <vector>
#include <iostream>
#include <cstring>
#include <algorithm>
using namespace std;

class Solution {
public:
    int minCost(int n, vector<int>& cuts) {

#define f(x,y) vf[(x)*m+(y)]
        cuts.push_back(n);
        sort(cuts.begin(), cuts.end());
        int m = cuts.size();
        int* vf = new int[m * m];
        for (int i = 0; i < m; i++) {
            f(i, i) = 0;
        }
        for (int len = 2; len <= m; len++) {
            for (int i = 0; i < m; i++) {
                int j = i + len - 1;
                if (j >= m)break;
                f(i, j) = INT_MAX;
                int cost = cuts[j] - ((i == 0) ? 0 : cuts[i - 1]);
                for (int k = i; k < j; k++) {
                    f(i, j) = std::min(f(i, j), f(i, k) + f(k + 1, j));
                }
                f(i, j) += cost;
            }
        }
        return f(0, m - 1);
    }
};

int main() {
    Solution s;
    vector<int> a = { 5,6,1,4,2 };
    cout << s.minCost(9,a) << endl;
    return 0;
}