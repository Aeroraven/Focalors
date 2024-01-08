#include <algorithm>
#include <vector>
#include <queue>
using namespace std;

struct TreeNode {
    int val;
    TreeNode* left;
    TreeNode* right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode* left, TreeNode* right) : val(x), left(left), right(right) {}
};

class Solution {
public:
    queue<TreeNode*> q;
    queue<int> dep;
    vector<vector<int>> answer;
    int cdep = -1;

    void bfs(TreeNode* root) {
        if (root == nullptr) return;
        q.push(root);
        dep.push(0);
        while (!q.empty()) {
            auto fr = q.front();
            auto dx = dep.front();
            q.pop();
            dep.pop();

            if (cdep < dx) {
                cdep++;
                answer.push_back(vector<int>());
            }
            answer[dx].push_back(fr->val);

            if (fr->left) {
                q.push(fr->left);
                dep.push(dx + 1);
            }
            if (fr->right) {
                q.push(fr->right);
                dep.push(dx + 1);
            }
        }
    }

    vector<vector<int>> zigzagLevelOrder(TreeNode* root) {
        bfs(root);
        for (int i = 0; i <= cdep; i++) {
            if (i % 2 == 1) {
                std::reverse(answer[i].begin(), answer[i].end());
            }
        }
        return answer;
    }
};