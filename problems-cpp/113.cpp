#include <vector>
#include <deque>
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
    std::deque<int> tp;
    std::vector<std::vector<int>> ans;
    void dfs(TreeNode* tr, int targetSum) {
        tp.push_back(tr->val);
        if (tr->left == nullptr && tr->right == nullptr) {
            if (targetSum - tr->val == 0) {
                std::vector<int> newAns;
                newAns.reserve(tp.size());
                std::copy(tp.begin(), tp.end(), newAns.begin());
                ans.push_back(std::move(newAns));
            }
            tp.pop_back();
            return;
        }
        if (tr->left) {
            dfs(tr->left, targetSum - tr->val);
        }
        if (tr->right) {
            dfs(tr->right, targetSum - tr->val);
        }
        tp.pop_back();
    }
    std::vector<std::vector<int>> pathSum(TreeNode* root, int targetSum) {
        dfs(root, targetSum);
        return ans;
    }
};