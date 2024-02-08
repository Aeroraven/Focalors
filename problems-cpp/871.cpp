#include <iostream>
#include <queue>
#include <algorithm>

class Solution {
public:
    int minRefuelStops(int target, int startFuel, std::vector<std::vector<int>>& stations) {
        std::priority_queue<int> fuelCands;
        int n = stations.size();
        auto comparer = [](const std::vector<int>& p, const std::vector<int>& q) {
            return p[0] < q[0];
        };
        std::sort(stations.begin(), stations.end(), comparer);
        int cur = 0;
        int ans = 0;
        for (;cur<n; cur++) {
            if (stations[cur][0] > startFuel)break;
            fuelCands.push(stations[cur][1]);
        }
        while (startFuel < target) {
            if (fuelCands.empty())return -1;
            int advance = fuelCands.top();
            fuelCands.pop();
            startFuel += advance;
            for (; cur < n; cur++) {
                if (stations[cur][0] > startFuel)break;
                fuelCands.push(stations[cur][1]);
            }
            ans++;
        }
        return ans;
    }
};

int main() {
    Solution s;
    std::vector<std::vector<int>> a = { {10,60},{20,30},{30,30},{60,40} };
    std::cout << s.minRefuelStops(100, 10, a);
    return 0;
}