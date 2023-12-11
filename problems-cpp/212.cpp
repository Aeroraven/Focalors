#include <iostream>
#include <vector>
#include <string>
using namespace std;


constexpr static int INF = INT_MAX;

struct TrieNode {
    TrieNode* successor[26] = { nullptr };
    bool ban = false;
};

class TrieGrid {
public:
    vector<vector<char>>* board = nullptr;
    TrieNode* root = new TrieNode();
    int rows = 0;
    int cols = 0;

    int maxPrefix = -1;
    bool existenceFlag = false;
    int startPosition = 0;

    void setBoard(vector<vector<char>>* b) {
        board = b;
        rows = board->size();
        cols = board[0].size();
    }

    TrieNode* createNode(const string& wd, TrieNode* node, int layer, int destLayer) {
        if (layer == destLayer + 1) {
            return node;
        }
        if (node->successor[wd[layer] - 'a'] == nullptr) {
            node->successor[wd[layer] - 'a'] = new TrieNode();
        }
        if (node->ban) {

        }
        return createNode(wd, node->successor[wd[layer] - 'a'], layer + 1, destLayer);
    }

    void banPrefix(const string& wd, TrieNode* root, int prefixLength) {
        auto p = createNode(wd, root, 0, prefixLength + 1);
        p->ban = true;
    }

    void searchBoardRecur(const string& wd, int pos, int layer) {
        const static int dx[] = { 0, 0, 1, -1 };
        const static int dy[] = { 1, -1, 0, 0 };
        int px = pos / cols;
        int py = pos % cols;

        maxPrefix = max(maxPrefix, layer);
        if (layer == wd.size() - 1) {
            existenceFlag = true;
            return;
        }
        bool haveDesc = false;
        for (int i = 0; i < 4; i++) {
            int tx = px + dx[i];
            int ty = py + dy[i];
            if (tx >= 0 && tx < rows && ty >= 0 && ty < cols) {
                if (wd[layer + 1] == (*board)[tx][ty]) {
                    searchBoardRecur(wd, tx * cols, layer + 1);
                    haveDesc = true;
                }
            }
        }
    }

    bool judgeWordValidity(const string& wd) {
        auto startPos = 0;
        existenceFlag = false;
        for (int i = startPos; i < rows * cols; i++) {
            int px = i / cols;
            int py = i % cols;
            startPosition = i;
            if (wd[0] == (*board)[px][py]) {
                searchBoardRecur(wd, i, root->successor[wd[0] - 'a'], 0);
            }
        }
    }

};

class Solution {
public:
    vector<string> findWords(vector<vector<char>>& board, vector<string>& words) {

    }
};

int main() {
    return 0;
}