#include <iostream>
#include <vector>
#include <ranges>
using namespace std;


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
    vector<TreeNode*> answer;


    void cloneTreeNodeImpl (TreeNode* src,TreeNode* dst) {
        dst->val = src->val;
        if (src->left) {
            dst->left = new TreeNode();
            cloneTreeNodeImpl(src->left,dst->left);
        }
        if (src->right) {
            dst->right = new TreeNode();
            cloneTreeNodeImpl(src->right,dst->right);
        }
    }

    TreeNode* cloneTreeNode(TreeNode* src) {
        TreeNode* tn = new TreeNode();
        cloneTreeNodeImpl(src, tn);
        return tn;
    }

    vector<TreeNode*> recursiveProcess(int val, int l, int r, int n) {
        vector<TreeNode*> left, right;
        vector<TreeNode*> rtn;

        // Left solutions
        for (int i = l; i <= val - 1; i++) {
            auto p = recursiveProcess(i, l, val - 1, n);
            left.reserve(left.size() + std::distance(p.begin(), p.end()));
            left.insert(left.end(), p.begin(), p.end());
        }

        //Right solutions
        for (int i = val + 1; i <= r; i++) {
            auto p = recursiveProcess(i, val+1,r, n);
            right.reserve(right.size() + std::distance(p.begin(), p.end()));
            right.insert(right.end(), p.begin(), p.end());
        }

        if (left.size() != 0 && right.size() != 0) {
            for (auto lx : left) {
                for (auto rx : right) {
                    TreeNode* cp = new TreeNode(val);
                    cp->left = cloneTreeNode(lx);
                    cp->right = cloneTreeNode(rx);
                    rtn.push_back(cp);
                }
            }
        }
        else if (right.size() != 0 ) {
            for (auto rx : right) {
                TreeNode* cp = new TreeNode(val);
                cp->left = nullptr;
                cp->right = rx;
                rtn.push_back(cp);
            }
        }
        else if (left.size() != 0) {
            for (auto lx : left) {
                TreeNode* cp = new TreeNode(val);
                cp->left = lx;
                cp->right = nullptr;
                rtn.push_back(cp);
            }
        }
        else {
            TreeNode* cp = new TreeNode(val);
            rtn.push_back(cp);
        }

        return rtn; //RVO?
    }
    
    vector<TreeNode*> generateTrees(int n) {
        vector<TreeNode*> ans;
        for (auto i = 1; i < n + 1; i++) {
            auto v = recursiveProcess(i, 1, n, n);
            ans.reserve(ans.size() + std::distance(v.begin(), v.end()));
            ans.insert(ans.end(), v.begin(), v.end());
        }
        return ans;
    }
};

int main() {
    Solution s;
    auto x = s.generateTrees(8);
    std::cout << x.size() << std::endl;
    return 0;
}