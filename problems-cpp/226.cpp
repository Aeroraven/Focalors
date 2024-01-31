#include <iostream>
#include <vector>

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};

class Solution {
public:
    void nodeSwap(auto& x, auto& y) {
        auto p = x;
        x = y;
        y = p;
    }

    TreeNode* invertTree(TreeNode* root) {
        if (root == nullptr)return;
        invertTree(root->left);
        invertTree(root->right);
        nodeSwap(root->left, root->right);
    }
};