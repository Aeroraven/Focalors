#include <iostream>
#include <vector>
#include <algorithm>

struct WaterRange {
    int l, r;
    bool operator <(const WaterRange& p) {
        if (l == p.l) {
            return r > p.r;
        }
        return l < p.l;
    }
};

class Solution {
public:
    int minTaps(int n, std::vector<int>& ranges) {
        int reqR = n, curR = 0;
        n++;
        std::vector<WaterRange> a;
        for (int i = 0; i < n; i++) {
            a.push_back({ std::max(0,i - ranges[i]),i + ranges[i] });
        }
        std::sort(a.begin(), a.end());
        int cur = 0;
        int ans = 0;
        while (cur < n && curR < reqR) {
            std::cout << "AL:" << curR <<"/"<< a[cur].l<< std::endl;
            int newR = -1;
            while (cur<n&&a[cur].l <= curR) {
                newR = std::max(newR, a[cur].r);
                cur++;
            }
            if (newR == -1)return-1;
            ans += 1;
            curR = newR;
        }
        return ans;
    }
};

int main() {
    Solution s;
    std::vector<int> a = { 3,2,1,1,1,1 };
    std::cout << s.minTaps(5,a) << std::endl;
    return 0;
}