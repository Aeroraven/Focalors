#include <iostream>
#include <vector>
#include <queue>
#include <unordered_set>

class Solution {
public:
    int largestIsland(std::vector<std::vector<int>>& grid) {
        std::vector<int> areas = { 0,0 };
        int n = grid.size();
        int curv = 1;
        std::queue<int> q;
        int ans = 0;
        // Marking connected blocks
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                if (grid[i][j] == 1) {
                    int ar = 1;
                    curv++;
                    q.push(i * n + j);
                    grid[i][j] = curv;
                    while (!q.empty()) {
                        auto tp = q.front();
                        
                        q.pop();
                        auto tpx = tp / n, tpy = tp % n;
                        if (tpx > 0 && grid[tpx - 1][tpy] == 1) {
                            grid[tpx - 1][tpy] = curv;
                            ar += 1;
                            q.push((tpx - 1) * n + tpy);
                        }
                        if (tpx < n - 1 && grid[tpx + 1][tpy] == 1) {
                            grid[tpx + 1][tpy] = curv;
                            ar += 1;
                            q.push((tpx + 1) * n + tpy);
                        }
                        if (tpy > 0 && grid[tpx][tpy - 1] == 1) {
                            grid[tpx][tpy - 1] = curv;
                            ar += 1;
                            q.push(tpx * n + (tpy - 1));
                        }
                        if (tpy < n - 1 && grid[tpx][tpy + 1] == 1) {
                            grid[tpx][tpy + 1] = curv;
                            ar += 1;
                            q.push(tpx * n + (tpy + 1));
                        }
                    }

                    areas.push_back(ar);
                    ans = std::max(ans, ar);
                }
            }
        }

        // For each empty block, mark adjacent islands
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                if (grid[i][j] == 0) {
                    std::unordered_set<int> st;
                    int ax = 1;
                    if (i > 0 && grid[i-1][j]>=2) {
                        st.insert(grid[i - 1][j]);
                    }
                    if (i < n - 1 && grid[i + 1][j]>=2) {
                        st.insert(grid[i + 1][j]);
                    }
                    if (j > 0 && grid[i][j-1] >= 2) {
                        st.insert(grid[i][j - 1]);
                    }
                    if (j < n - 1 && grid[i][j + 1] >= 2) {
                        st.insert(grid[i][j + 1]);
                    }
                    for (auto x : st) {
                        ax += areas[x];
                    }
                    ans = std::max(ans, ax);
                }
            }
        }

        return ans;
    }
};

int main() {
    Solution s;
    std::vector<std::vector<int>> a = { {1,1},{1,1} };
    std::cout << s.largestIsland(a) << std::endl;
    return 0;
}