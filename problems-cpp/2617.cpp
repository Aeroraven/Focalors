#include <vector>
#include <queue>
#include <iostream>
using namespace std;

struct Grid {
    int rightBound;
    int minStep;
    bool operator < (const Grid& p) const {
        if (minStep == p.minStep) {
            return rightBound > p.rightBound;
        }
        return minStep > p.minStep;
    }
};

class Solution {
public:
    int minimumVisitedCells(vector<vector<int>>& grid) {
        int n = grid.size(), m = grid[0].size();
        vector<priority_queue<Grid>> colq(m);
        for (int i = 0; i < n; i++) {
            priority_queue<Grid> rowq;
            if (i == 0) {
                colq[0].push({ grid[0][0],1 });
                rowq.push({ grid[0][0],1 });
                grid[0][0] = 1;
            }
            for (int j = (i == 0) ? 1 : 0; j < m; j++) {
                int minSteps = 9000000;
                //Update from rows
                while (!rowq.empty()) {
                    auto w = rowq.top();
                    if (w.rightBound < j) {
                        rowq.pop();
                        continue;
                    }
                    minSteps = std::min(minSteps, w.minStep + 1);
                    break;
                }
                //Update from cols
                while (!colq[j].empty()) {
                    auto w = colq[j].top();
                    if (w.rightBound < i) {
                        colq[j].pop();
                        continue;
                    }
                    minSteps = std::min(minSteps, w.minStep + 1);
                    break;
                }
                rowq.push({ grid[i][j] + j,minSteps });
                colq[j].push({ grid[i][j] + i,minSteps });
                grid[i][j] = minSteps;
            }
        }
        if (grid[n - 1][m - 1] == 9000000) {
            return -1;
        }
        return grid[n - 1][m - 1];
    }
};

int main() {
    Solution s;
    vector<vector<int>> a = { {0} };
    cout << s.minimumVisitedCells(a) << endl;
    return 0;
}