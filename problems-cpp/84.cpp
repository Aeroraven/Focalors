#include <iostream>
#include <vector>
#include <cstdlib>
using namespace std;

class Solution {
public:
    int largestRectangleArea(vector<int>& heights) {
        int numBars = heights.size();
        int* stackHeights = new int[numBars];
        int* stackCoords = new int[numBars];
        int stackTop = -1;
        int bestAns = 0;
        //Iterate bars
        for (auto i = 0; i < numBars; i++) {
            auto h = heights[i];
            auto popPos = i;
            //If not in ascending order
            while (stackTop >= 0 && stackHeights[stackTop] > h) {
                auto bw = (i - stackCoords[stackTop]);
                popPos = min(popPos, stackCoords[stackTop]);
                bestAns = max(bestAns, bw * stackHeights[stackTop]);
                stackTop--;
            }
            stackTop++;
            stackHeights[stackTop] = h;
            stackCoords[stackTop] = popPos;
        }
        //Handle remaining elements
        for (auto i = 0; i <= stackTop; i++) {
            auto bw = (numBars - 1) - stackCoords[i] + 1;
            bestAns = max(bestAns, bw * stackHeights[i]);
        }
        return bestAns;
    }
};

int main() {
    Solution a;
    std::vector<int> v = { 2,4 };
    cout << a.largestRectangleArea(v) << endl;
    return 0;
}