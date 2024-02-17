#include <iostream>
#include <string>
using namespace std;

class Solution {
public:
    int numberOfWays(string corridor) {
        int ans = 1;
        int seatCnt = 0;
        int lastSols = 1, curSols = 1;
        int n = corridor.size();
        for (int i = 0; i < n; i++) {
            if (corridor[i] == 'S') {
                if (seatCnt == 2) {
                    seatCnt = 0;
                    ans = (((long long)ans) * lastSols) % (1000000007);
                    lastSols = 1;
                }
                seatCnt++;
            }
            if (corridor[i] == 'P' && seatCnt == 2) {
                lastSols++;
            }
        }
        if (seatCnt != 2) {
            return 0;
        }
        return ans;
    }
};

int main() {
    Solution s;
    std::cout<<s.numberOfWays("PPSPSP");
    return 0;
}