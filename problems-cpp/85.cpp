#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    int maximalRectangle(vector<vector<char>>& matrix) {
        int rows = static_cast<int>(matrix.size());
        int cols = static_cast<int>(matrix[0].size());

        // Sum(i,j) = number of 1 in rectangle column j (first i elements)
        int* vSum = new int[rows * cols];
        auto sum = [&](int r, int c)->int& {
            return vSum[r * cols + c];
        };
        sum(0, 0) = matrix[0][0] - '0';
        for (int i = 1; i < cols; i++) {
            sum(0, i) = (matrix[0][i] - '0');
        }
        for (int i = 1; i < rows; i++) {
            for (int j = 0; j < cols; j++) {
                sum(i, j) = sum(i - 1, j) + (matrix[i][j] - '0');
            }
        }

        // Find the combination of rows (i,j)
        int ans = 0;
        for (int i = 0; i < rows; i++) {
            for (int j = i; j < rows; j++) {
                int colReq = j - i + 1;
                int l = 0;
                for (int k = 0; k < cols; k++) {
                    int colCur = sum(j, k);
                    if (i > 0) {
                        colCur -= sum(i - 1, k);
                    }
                    if (colCur < colReq) {
                        l = k + 1;
                    }
                    ans = max(ans, (k + 1 - l) * (colReq));
                }
            }
        }
        return ans;
    }
};


int main() {
    Solution sol;
    vector<vector<char>> a = {
        {'1','0','1','0','0'},
        {'1','0','1','1','1'},
        {'1','1','1','1','1'},
        {'1','0','0','1','0'}
    };
    cout << sol.maximalRectangle(a);
	return 0;
}