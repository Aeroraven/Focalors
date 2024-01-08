#include <unordered_map>
#include <vector>
#include <stack>

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
    TreeNode* root = nullptr;
    std::unordered_map<int, int> midOrderMap;
    

    TreeNode* buildTree(std::vector<int>& preorder, std::vector<int>& inorder) {
        for (int i = 0; i < inorder.size(); i++) {
            midOrderMap[inorder[i]] = i;
        }
    }
};