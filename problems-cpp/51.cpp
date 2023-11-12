#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    void solveImpl(int curLvl, int dstLvl, int* place, vector<vector<string>>& answ) {
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
            // Insert the answer
            vector<string>* sp = new vector<string>();
            for (int i = 0; i < dstLvl; i++) {
                //cout << place[i] << ",";
                string lx = "";
                for (int j = 0; j < dstLvl; j++) {
                    if (j != place[i]) {
                        lx += ".";
                    }
                    else {
                        lx += "Q";
                    }
                }
                sp->push_back(lx);
            }
            //cout << endl;
            answ.push_back(*sp);
        }
        
    }

    vector<vector<string>> solveNQueens(int n) {
        vector<vector<string>> ret = {};
        int* place = new int[n];
        solveImpl(0, n, place, ret);
        return ret;
    }
};

int main() {
    Solution sol;
    int n;
    cin >> n;
    cout << sol.solveNQueens(n).size() << endl;
    return 0;
}