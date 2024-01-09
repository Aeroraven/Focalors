#include <vector>
#include <iostream>


class Solution {
public:
    int canCompleteCircuit(std::vector<int>& gas, std::vector<int>& cost) {
        int currentGas = -1000;
        int currentStart = 0;
        int n = gas.size();
        for (int i = 0; i < n; i++) {
            if (currentGas < 0) {
                currentGas = gas[i] - cost[i];
                currentStart = i;
            }
            else {
                currentGas += gas[i] - cost[i];
            }
           
        }
        int cx = 0;
        for (int i = 0; i < n; i++) {
            cx += gas[(i+currentStart)%n] - cost[(i+currentStart)%n];
            if (cx < 0) {
                return -1;
            }
        }
        return currentStart;
    }
};

int main() {
    Solution s;
    std::vector<int> sp = { 1,2,300,4,5 };
    std::vector<int> cs = { 1,300,2,4,4 };
    std::cout << s.canCompleteCircuit(sp, cs) << std::endl;
    return 0;
}