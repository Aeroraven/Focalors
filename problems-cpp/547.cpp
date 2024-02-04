#include <iostream>
#include <vector>
#include <queue>
#include <cstring>

class Solution {
public:

    int findCircleNum(std::vector<std::vector<int>>& isConnected) {
        int n = isConnected.size();
        int* p = new int[n];
        int ans = 0;
        memset(p, 0, n * sizeof(int));

        for (int i = 0; i < n; i++) {
            if (!p[i]) {
                ans++;
                std::queue<int> q;
                q.push(i);
                p[i] = 1;
                while (!q.empty()) {
                    auto f = q.front();
                    q.pop();
                    
                    for (int j = 0; j < n; j++) {
                        if (isConnected[f][j] && !p[j]) {
                            p[j] = 1;
                            q.push(j);
                        }
                    }
                }
            }
        }
        return ans;
    }
};

int main() {
    Solution s;
    std::vector<std::vector<int>> g = { {1,0,0}, {1,0,0},{0,0,1} };
    std::cout << s.findCircleNum(g);
    return 0;
}