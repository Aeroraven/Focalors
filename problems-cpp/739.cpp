#include <iostream>
#include <stack>
#include <vector>

class Solution {
public:
    std::vector<int> dailyTemperatures(std::vector<int>& temperatures) {
        std::stack<int> dec;
        int n = temperatures.size();
        std::vector<int> ans(n);
        for (int i = 0; i < n; i++) {
            ans[i] = 0;
            while (!dec.empty()) {
                auto tp = dec.top();
                if (temperatures[tp] < temperatures[i]) {
                    ans[tp] = i - tp;
                    dec.pop();
                    continue;
                }
                break;
            }
            dec.push(i);
        }
        return ans;
    }
};

int main() {
    Solution s;
    std::vector<int> a = { 73,74,75,71,69,72,76,73 };
    auto p = s.dailyTemperatures(a);
    for (auto& x : p) {
        std::cout << x << ",";
    }
    return 0;
}