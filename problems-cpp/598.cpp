#include <iostream>
#include <algorithm>
class Solution {
public:
    int maxCount(int m, int n, std::vector<std::vector<int>>& ops) {
        int a = m, b = n;
        for (auto& p : ops) {
            a = std::min(a, p[0]);
            b = std::min(b, p[1]);
        }
        return a * b;
    }
};