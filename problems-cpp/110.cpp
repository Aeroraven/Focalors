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
    bool flag = true;
    int dfs(TreeNode* root) {
        if (!root || flag == false) return 0;
        int left = dfs(root->left) + 1;
        int right = dfs(root->right)+1;
        int diff = left - right, mvx = left;
        if (right > mvx)mvx = right;
        if (diff < 0)diff = -diff;
        if (diff > 1)flag = false;
        return mvx;

    }
    bool isBalanced(TreeNode* root) {
        dfs(root);
        return flag;
    }
};