#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    int calculateMinimumHP(vector<vector<int>>& dungeon) {
        int rows = static_cast<int>(dungeon.size());
        int cols = static_cast<int>(dungeon[0].size());
        int* vf = new int[rows * cols];
        
        // F(i,j) denotes the minimal hitpoints required before entering
        // this grid cell
        // Then F(i,j)=max{min{F(i+1,j),F(i,j+1)}-A(i,j),1}

        auto f = [&](int i, int j)->int& {
            return vf[i * cols + j];
        };
        for (int i = rows - 1; i >= 0; i--) {
            for (int j = cols - 1; j >= 0; j--) {
                int baseReq = 0x7fffffff;
                if (i < rows - 1) {
                    baseReq = min(baseReq, f(i + 1, j));
                }
                if (j < cols - 1) {
                    baseReq = min(baseReq, f(i, j + 1));
                }
                if (baseReq == 0x7fffffff) {
                    baseReq = 1;
                }
                
                f(i, j) = max(baseReq - dungeon[i][j], 1);
                //cout << "F(" << i << "," << j << ")=" << f(i, j) << endl;
            }
        }
        return f(0, 0);
    }
};


int main() {
    Solution s;
    vector<vector<int>> p = { {-2,-3,3},{-5,-10,1},{10,30,-5} };
    cout << s.calculateMinimumHP(p);
	return 0;
}