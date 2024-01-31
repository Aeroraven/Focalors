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
    int reqk = 0, curk = 0;
    void search(TreeNode* root) {
        if (root == nullptr || curk>=reqk)return;
        search(root->left);
        if (++curk == reqk) {
            ans = root->val;
            return;
        }
        search(root->right);
    }
    int kthSmallest(TreeNode* root, int k) {
        reqk = k;
        search(root);
        return ans;
    }
};