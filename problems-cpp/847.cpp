#include <iostream>
#include <vector>
#include <queue>

class Solution {
public:
    int bfs(std::vector<std::vector<int>>& graph, int start) {
        int n = graph.size();
        int visitMask = (1 << n) - 1;
        int total = (((n-1) << n) | visitMask) + 1;
        int* f = new int[total];
        memset(f, 0, sizeof(int) * total);
        std::queue<int> q;
        int beginStatus = (start << n) | (1 << start);
        f[beginStatus] = 1;
        q.push(beginStatus);
        while (!q.empty()) {
            int front = q.front();
            q.pop();
            auto curStatus = front & visitMask;
            auto curFinal = front >> n;
            for (auto& p : graph[curFinal]) {
                int nextHistory = (curStatus | (1 << p));
                int nextLabel = (p << n) | nextHistory;
                int value = f[front] + 1;
                if (f[nextLabel] == 0) {
                    if ((nextHistory & visitMask) == visitMask) {
                        return value - 1;
                    }
                    f[nextLabel] = value;
                    q.push(nextLabel);
                }
            }
        }
        return 0xffffff;
    }
    int shortestPathLength(std::vector<std::vector<int>>& graph) {
        int n = graph.size();
        if (n == 1) {
            return 0;
        }
        int ans = 0x7fffffff;
        for (int i = 0; i < n; i++) {
            ans = std::min(ans, bfs(graph, i));
        }
        return ans;
    }
};

int main() {
    Solution s;
    std::vector<std::vector<int>> g = { {1,2},{0},{0} };
    std::cout << s.shortestPathLength(g);
    return 0;
}