#include <vector>
#include <cstring>
#include <functional>
#include <iostream>

class Solution {
public:
    int rows = 0, cols = 0;
    std::vector<std::vector<char>>* grid = nullptr;
    int* retainFlag = nullptr;
    std::function<int& (int, int)> r;

    void markRetain(int x, int y) {
        r(x, y) = 1;
        if (x > 0 && (*grid)[x - 1][y] == 'O' && r(x - 1, y) == 0) markRetain(x - 1,y);
        if (x < rows - 1 && (*grid)[x + 1][y] == 'O' && r(x + 1, y) == 0)markRetain(x + 1, y);
        if (y > 0 && (*grid)[x][y - 1] == 'O' && r(x, y - 1) == 0) markRetain(x, y - 1);
        if (y < cols - 1 && (*grid)[x][y + 1] == 'O' && r(x, y + 1) == 0) markRetain(x, y + 1);
    }

    void solve(std::vector<std::vector<char>>& board) {
        rows = board.size();
        cols = board[0].size();
        retainFlag = new int[rows * cols];
        memset(retainFlag, 0, sizeof(int) * rows * cols);
        r = [&](int x, int y)->int& {
            return retainFlag[x * cols + y];
        };
        grid = &board;

        // Mark cells to retain
        for (int i = 0; i < cols; i++) {
            if (board[0][i] == 'O' && r(0, i) == 0) {
                markRetain(0, i);
            }
            if (board[rows - 1][i] == 'O' && r(rows - 1, i) == 0) {
                markRetain(rows - 1, i);
            }
        }

        for (int i = 0; i < rows; i++) {
            if (board[i][0] == 'O' && r(i, 0) == 0) {
                markRetain(i, 0);
            }
            if (board[i][cols - 1] == 'O' && r(i, cols - 1) == 0) {
                markRetain(i, cols - 1);
            }
        }

        // Discard surrounded cells
        for (int i = 0; i < rows; i++) {
            for (int j = 0; j < cols; j++) {
                if (board[i][j] == 'O' && r(i, j) == 0) {
                    board[i][j] = 'X';
                }
            }
        }
    }

    void print(std::vector<std::vector<char>>& board) {
        for (auto& p : board) {
            for (auto& q : p) {
                std::cout << q << ",";
            }
            std::cout << std::endl;
        }
    }
};

int main() {
    Solution s;
    std::vector<std::vector<char>> p = { {'X','O','X'},{'O','X','O'},{'X','O','X'} };
    s.solve(p);
    s.print(p);
    return 0;
}