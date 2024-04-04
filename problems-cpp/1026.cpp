#include <iostream>
using namespace std;
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
    void dfs(TreeNode* p, int mx, int mi) {
        if (p == nullptr)return;
        mx = std::max(mx, p->val);
        mi = std::min(mi, p->val);
        ans = std::max(ans, mx - mi);

        dfs(p->left, mx, mi);
        dfs(p->right, mx, mi);
    }
    int maxAncestorDiff(TreeNode* root) {
        if (root == nullptr) return 0;
        dfs(root, root->val, root->val);
        return ans;
    }
};