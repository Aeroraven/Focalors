#include <iostream>

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
    bool isSymmetricImpl(TreeNode* lp, TreeNode* rp) {

        if (lp == nullptr && rp == nullptr) return true;
        if (lp != nullptr && rp == nullptr) return false;
        if (lp == nullptr && rp != nullptr) return false;
        if (lp->val != rp->val) return false;
        bool leftChild = isSymmetricImpl(lp->left, rp->right);
        bool rightChild = isSymmetricImpl(lp->right, rp->left);
        return leftChild && rightChild;
    }
    bool isSymmetric(TreeNode* root) {
        if (root == nullptr)return true;
        return isSymmetricImpl(root->left, root->right);
    }
};