#include <vector>
#include <queue>

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
    std::vector<std::vector<int>> levelOrderBottom(TreeNode* root) {
        std::vector<std::vector<int>> answer;
        int cx = -1;
        if (root != nullptr) {
            std::queue<TreeNode*> qx;
            std::queue<int> dx;
            qx.push(root);
            dx.push(0);
            while (!qx.empty()) {
                auto fr = qx.front(); qx.pop();
                auto frd = dx.front(); dx.pop();
                if (cx < frd) {
                    cx++;
                    answer.push_back(std::vector<int>());
                }
                answer[frd].push_back(fr->val);
                if (fr->left) {
                    qx.push(fr->left);
                    dx.push(frd + 1);
                }
                if (fr->right) {
                    qx.push(fr->right);
                    dx.push(frd + 1);
                }
            }
            std::reverse(answer.begin(), answer.end());
        }
        return answer; //RVO ?
    }
};