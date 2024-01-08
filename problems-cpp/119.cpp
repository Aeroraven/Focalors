#include <vector>
#include <iostream>
class Solution {
public:
    std::vector<int> getRow(int rowIndex) {
        int* vf = new int[(rowIndex+1) * 2];
        auto f = [&](int x, int y)->int& {
            return vf[(rowIndex + 1) * (x % 2) + y];
        };
        for (int i = 0; i <= rowIndex; i++) {
            for (int j = 0; j <= i; j++) {
                if (j == 0 || j == i) f(i, j) = 1;
                else f(i, j) = f(i - 1, j - 1) + f(i - 1, j);
            }
        }
        std::vector<int> rtn(rowIndex + 1);
        std::copy(&f(rowIndex, 0), &f(rowIndex, rowIndex)+1, rtn.begin());
        return rtn;
    }
};

int main() {
    Solution s;
    for (auto x : s.getRow(4)) {
        std::cout << x << ",";
    }
    return 0;
}