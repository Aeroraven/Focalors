#include <iostream>
#include <vector>
#include <queue>

struct Entry {
    int listId;
    int pt;
    int value;
    bool operator < (const Entry& p) const {
        return value > p.value;
    }
};

class Solution {
public:
    std::vector<int> smallestRange(std::vector<std::vector<int>>& nums) {
        int k = nums.size();

        std::priority_queue<Entry> leftBounds;
        int rightBound = -1000000;
        int bestL=-1000000, bestR=1000000, bestLen = 10000000;
        for (int i = 0; i < k; i++) {
            leftBounds.push({ i,0,nums[i][0] });
            rightBound = std::max(rightBound, nums[i][0]);
        }
        while (true) {
            auto tp = leftBounds.top();
            leftBounds.pop();
            int curL = tp.value, curR = rightBound;
            if (curR - curL < bestLen) {
                bestL = curL;
                bestR = curR;
                bestLen = curR - curL;
            }
            if (tp.pt == nums[tp.listId].size() - 1) {
                break;
            }
            rightBound = std::max(rightBound, nums[tp.listId][tp.pt + 1]);
            leftBounds.push({ tp.listId,tp.pt + 1, nums[tp.listId][tp.pt + 1] });
        }

        return { bestL,bestR };

    }
};

int main() {
    Solution s;
    std::vector<std::vector<int>> g = { {-5,1,2,3},{-4,1,2,3},{-3,1,2,3} };//{ {4,10,15,24,26 },{0, 9, 12, 20 }, { 5,18,22,30 } };
    auto w = s.smallestRange(g);
    std::cout << w[0]<<","<<w[1] << std::endl;
    return 0;
}