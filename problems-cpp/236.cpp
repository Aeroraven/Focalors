#include <iostream>
#include <vector>
#include <map>

struct TreeNode {
    int val;
    TreeNode* left = nullptr;
    TreeNode* right = nullptr;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode* left, TreeNode* right) : val(x), left(left), right(right) {}
};

class Solution {
public:
    TreeNode* lca = nullptr;
    bool lcaImpl(TreeNode* root, TreeNode* p, TreeNode* q) {
        if (root == nullptr || lca != nullptr)return;
        bool leftCrit = lcaImpl(root->left, p, q);
        bool rightCrit = lcaImpl(root->right, p, q);
        bool contain = (p == root || q == root);
        if (lca == nullptr) {
            if (contain  && (leftCrit || rightCrit)) {
                lca = root;
                return true;
            }
            else if (leftCrit && rightCrit) {
                lca = root;
                return true;
            }
        }
        return leftCrit || rightCrit || contain;


    }
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        if (p == q && p == root) {
            return root;
        }
        lcaImpl(root, p, q);
        return lca;
    }
};