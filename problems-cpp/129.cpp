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
    int sum = 0;

    void dfs(TreeNode* tn, int prefix) {
        if (!tn) return;
        int newPrefix = prefix * 10 + tn->val;
        if (!tn->left && !tn->right) {
            sum += newPrefix;
            return;
        }
        if (tn->left) {
            dfs(tn->left, newPrefix);
        }
        if (tn->right) {
            dfs(tn->right, newPrefix);
        }
    }

    int sumNumbers(TreeNode* root) {
        dfs(root, 0);
        return sum;
    }
};