#include <iostream>
#include <vector>
class Solution {
public:
    inline int sLog2(int x) {
        int v = x | (x >> 1);
        v |= (v >> 2);
        v |= (v >> 4);
        v |= (v >> 8);
        v |= (v >> 16);
        v = v - (v >> 1);
        int c = 31;
        if (v & 0x0000ffff)c -= 16;
        if (v & 0x00ff00ff)c -= 8;
        if (v & 0x0f0f0f0f)c -= 4;
        if (v & 0x33333333)c -= 2;
        if (v & 0x55555555)c -= 1;
        return c;
    }
    std::vector<int> cycleLengthQueries(int n, std::vector<std::vector<int>>& queries) {
        std::vector<int> ans;
        for (auto& query : queries) {
            int a = query[0], b = query[1];
            int qa = a, qb = b;
            int depthA = sLog2(a), depthB = sLog2(b), bu, aq;
            if (depthA > depthB) {
                aq = depthA - depthB;
                qa >>= aq;
                bu = depthB;
            }
            else if (depthB > depthA) {
                aq = depthB - depthA;
                qb >>= aq;
                bu = depthA;
            }
            else {
                bu = depthA;
                aq = 0;
            }
            int d = qa ^ qb;
            if (d != 0) {
                int logd = sLog2(d) + 1;
                int lcaDepth = bu - logd;
                aq = (depthA - lcaDepth) + (depthB - lcaDepth);
            }
            aq++;
            ans.push_back(aq);
        }
        return ans;
    }
};
int main() {
    Solution s;
    std::vector<std::vector<int>> a = { {5,3},{4,7},{2,5} };
    s.cycleLengthQueries(30,a);
    return 0;
}