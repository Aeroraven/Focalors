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
    
    void rightSideViewImpl(TreeNode* root, std::vector<int>& ans,int depth) {
        if (root == nullptr) return;
        if (depth > ans.size()) {
            ans.push_back(root->val);
        }
        rightSideViewImpl(root->right, ans, depth + 1);
        rightSideViewImpl(root->left, ans, depth + 1);
    }
    std::vector<int> rightSideView(TreeNode* root) {
        std::vector<int> ans;
        rightSideViewImpl(root, ans, 1);
        return ans;
    }
};