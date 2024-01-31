#include <iostream>
#include <vector>

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
    int ans = 0;
    int diameterOfBinaryTreeImpl(TreeNode* root) {
        if (root == nullptr)return 0;
        int left = diameterOfBinaryTreeImpl(root->left);
        int right = diameterOfBinaryTreeImpl(root->right);
        ans = std::max(left + right + 1, ans);
        return std::max(left, right) + 1;
    }
    int diameterOfBinaryTree(TreeNode* root) {
        diameterOfBinaryTreeImpl(root);
        return ans - 1;
    }
};