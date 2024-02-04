#include <stack>
#include <iostream>
#include <vector>

class Solution {
public:
    std::vector<int> canSeePersonsCount(std::vector<int>&heights) {
        int n = heights.size();
        std::vector<int> ans(n);
        std::stack<int> elim;
        std::stack<int> p;
        for (int i = 0; i < n; i++) {
            int contPops = 0;
            int elims = 1;
            while (!p.empty()) {
                auto tp = p.top();
                if (heights[i] > heights[tp]) {
                    ans[tp] = elims;
                    p.pop();
                    elims = elim.top() + 1;
                    elim.pop();
                    continue;
                }
                break;
            }
            elim.push(elims);
            p.push(i);
        }
        int elemx = 0;
        while (!p.empty()) {
            auto tp = p.top();
            ans[tp] = elemx;
            elemx = elim.top();
            p.pop();
            elim.pop();
        }
        //ans[n - 1] = 0;
        return ans;
    }
};

int main() {
    Solution s;
    std::vector<int> g = { 12,6,3,1,8,4,2,5,7,9 };
    auto w = s.canSeePersonsCount(g);
    for (auto& p : w) {
        std::cout << p << ",";
    }
    return 0;
}