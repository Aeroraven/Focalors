#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    void solveImpl(int curLvl, int dstLvl, int* place, int& answ) {
        if (curLvl < dstLvl) {
            bool* blocked = new bool[dstLvl];
            for (int i = 0; i < dstLvl; i++) {
                blocked[i] = false;
            }
            for (int i = 0; i <= curLvl - 1; i++) {
                blocked[place[i]] = true; //Column restriction
                int lineDiff = curLvl - i;
                if (place[i] + lineDiff < dstLvl && place[i] + lineDiff >= 0) {
                    blocked[place[i] + lineDiff] = true;
                }
                if (place[i] - lineDiff < dstLvl && place[i] - lineDiff >= 0) {
                    blocked[place[i] - lineDiff] = true;
                }
            }
            for (int i = 0; i < dstLvl; i++) {
                if (!blocked[i]) {
                    place[curLvl] = i;
                    solveImpl(curLvl + 1, dstLvl, place, answ);
                }
            }
            delete[] blocked;
        }
        else {
            answ += 1;
        }
    }

    int totalNQueens(int n) {
        int ret = 0;
        int* place = new int[n];
        solveImpl(0, n, place, ret);
        return ret;
    }
};
int main() {
    Solution sol;
    int n;
    cin >> n;
    cout << sol.totalNQueens(n) << endl;
    return 0;
}