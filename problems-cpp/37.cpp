#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    using Board = vector<vector<char>>;
    Board* vp = nullptr;
    bool simpleFilterFlag = true;
    bool illegalPlacement[9][9][9];
    int invalidPlacements[9][9];
    bool completeFlag = false;

    vector<int> emptyRow;
    vector<int> emptyCol;

    int rowBits[9];
    int colBits[9];
    int boxBits[3][3];


    void recurSearch(int cur, int dest) {
        // When the puzzle is solved, just return
        if (cur == dest) {
            cout << "Solution Found" << endl;
            completeFlag = true;
            return;
        }
        // Otherwise, check for available placements in cell "cur"
        int row = emptyRow[cur];
        int col = emptyCol[cur];
        int bx = (row / 3), by = (col / 3);
        Board& board = *vp;

        int& rowCond = rowBits[row];
        int& colCond = colBits[col];
        int& boxCond = boxBits[bx][by];
        
        int cond = (rowCond | colCond | boxCond) ;
        for (int i = 0; i < 9; i++) {
            if ((cond & (2 << i)) == 0) {
                board[row][col] = i + '1';
                rowCond = rowCond | (2 << i);
                colCond = colCond | (2 << i);
                boxCond = boxCond | (2 << i);
                recurSearch(cur + 1, dest);
                if (completeFlag) {
                    return;
                }
                boxCond = boxCond & (~(2 << i));
                colCond = colCond & (~(2 << i));
                rowCond = rowCond & (~(2 << i));
            }
        }
        board[row][col] = '.';
    }

    void findEmtpyCells() {
        // Find and record all emtpy cells.
        Board& board = *vp;

        for (int i = 0; i < 9; i++) {
            for (int j = 0; j < 9; j++) {
                if (board[i][j] == '.') {
                    emptyRow.push_back(i);
                    emptyCol.push_back(j);
                }
            }
        }

        // Initialize bits
        memset(rowBits, 0, sizeof(rowBits));
        memset(colBits, 0, sizeof(colBits));
        memset(boxBits, 0, sizeof(boxBits));

        for (int i = 0; i < 9; i++) {
            for (int j = 0; j < 9; j++) {
                if (board[i][j] != '.') {
                    rowBits[i] |= (2 << (board[i][j] - '1'));
                    colBits[j] |= (2 << (board[i][j] - '1'));
                }

            }
        }
        for (int i = 0; i < 3; i++) {
            for (int j = 0; j < 3; j++) {

                for (int u = i * 3; u < (i + 1) * 3; u++) {
                    for (int v = j * 3; v < (j + 1) * 3; v++) {
                        if (board[u][v] != '.') {
                            boxBits[i][j] |= (2 << (board[u][v] - '1'));
                        }
                    }
                }

            }
        }

    }

    void simpleFilter() {
        // Find available digits for empty cells by finding existing values in corresponding rows, 
        // columns and boxes.
        simpleFilterFlag = false;
        Board& board = *vp;
        for (int i = 0; i < 9; i++) {
            for (int j = 0; j < 9; j++) {
                if (board[i][j] == '.') {
                    //Reset counter
                    invalidPlacements[i][j] = 0;
                    for (int k = 0; k < 9; k++) {
                        illegalPlacement[i][j][k] = false;
                    }

                    //Check row i
                    for (int k = 0; k < 9; k++) {
                        if (board[i][k] != '.') {
                            illegalPlacement[i][j][board[i][k] - '1'] = true;
                        }
                    }
                    //Check column j
                    for (int k = 0; k < 9; k++) {
                        if (board[k][j] != '.') {
                            illegalPlacement[i][j][board[k][j] - '1'] = true;
                        }
                    }
                    //Check box
                    int bX = (i / 3) * 3, bY = (j / 3) * 3;
                    for (int u = bX; u < bX + 3; u++) {
                        for (int v = bY; v < bY + 3; v++) {
                            if (board[u][v] != '.') {
                                illegalPlacement[i][j][board[u][v] - '1'] = true;
                            }
                        }
                    }
                    //Check illegal placements
                    int lastLegalVal = 0;
                    for (int k = 0; k < 9; k++) {
                        if (illegalPlacement[i][j][k]) {
                            invalidPlacements[i][j] += 1;
                        }
                        else {
                            lastLegalVal = k;
                        }
                    }
                    if (invalidPlacements[i][j] == 8) {
                        board[i][j] = lastLegalVal + '1';
                        simpleFilterFlag = true;
                        //cout << "Found use first filter" << endl;
                        break;
                    }
                }
                if (simpleFilterFlag)break;
            }
            if (simpleFilterFlag)break;
        }

    }

    void solveSudoku(vector<vector<char>>& board) {
        vp = &board;
        memset(illegalPlacement,0,sizeof(illegalPlacement));

        simpleFilterFlag = true;
        while (simpleFilterFlag) {
            simpleFilter();
        }
        findEmtpyCells();
        recurSearch(0, emptyRow.size());
        
        for (int i = 0; i < 9; i++) {
            for (int j = 0; j < 9; j++) {
                cout << board[i][j] << ",";
            }
            cout << endl;
        }
        cout << endl;
    }
};

int main() {
    Solution s;

    // Following example might produce TLE for some non-bit-based solutions
    // However, the case is not included in the official test set.

    vector<vector<char>> b = { 
        {'3','.','6','.','.','.','2','.','.'},
        {'2','.','.','8','.','.','.','.','.'},
        {'.','.','.','.','.','.','.','.','.'},
        {'7','8','.','4','.','.','.','.','.'},
        {'.','.','.','.','6','.','3','.','.'},
        {'.','.','.','.','.','2','.','.','.'},
        {'.','5','.','.','.','.','.','1','8'},
        {'.','.','9','.','3','.','.','.','.'},
        {'.','.','.','.','.','.','.','7','.'} 
    };

    s.solveSudoku(b);
	return 0;
}