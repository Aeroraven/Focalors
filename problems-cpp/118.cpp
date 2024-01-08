#include <vector>

class Solution {
public:
    std::vector<std::vector<int>> generate(int numRows) {
        std::vector<std::vector<int>> ans;
        if (numRows >= 1) {
            std::vector<int> tp;
            tp.push_back(1);
            ans.push_back(std::move(tp));
        }
        for (int i = 1; i < numRows; i++) {
            std::vector<int> tp;
            for (int j = 0; j <= i; j++) {
                if (j == 0 || j == i ) {
                    tp.push_back(1);
                }
                else {
                    tp.push_back(ans[i - 1][j] + ans[i - 1][j - 1]);
                }
            }
            ans.push_back(std::move(tp));
        }
        return ans;
    }
};

int main() {
    Solution s;
    s.generate(4);
    return 0;
}