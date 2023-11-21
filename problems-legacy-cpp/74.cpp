class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        int i = 0;
        if (matrix[0][0] > target)return false;
        while (i + 1 < matrix.size()) {
            if (i + 1 < matrix.size()) {
                if (matrix[i + 1][0] > target) {
                    break;
                }
            }
            i++;
        }
        for (int j = 0; j < matrix[0].size(); j++) {
            if (matrix[i][j] == target) {
                return true;
            }
        }
        return false;
    }
};