#include <unordered_map>
#include <vector>
#include <iostream>
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

    std::unordered_map<int, int> midOrderMap;
    std::vector<int>* pOrd = nullptr;
    int cur = -1;
    int n;

    void dfs(TreeNode*& place, int lx, int rx) {
        if (cur == -1)return;
        int preOrdVal = (*pOrd)[cur ];
        int inOrdIdx = midOrderMap[preOrdVal];
        if (inOrdIdx >= lx && inOrdIdx <= rx) {
            place = new TreeNode(preOrdVal);
            cur--;
            dfs(place->right, inOrdIdx + 1, rx);
            dfs(place->left, lx, inOrdIdx - 1);
            
        }
    }

    TreeNode* buildTree(std::vector<int>& inorder, std::vector<int>& postorder) {
        for (int i = 0; i < inorder.size(); i++) {
            midOrderMap[inorder[i]] = i;
        }
        n = inorder.size();
        cur = n - 1;
        pOrd = &postorder;
        if (inorder.size() == 0) {
            return nullptr;
        }
        TreeNode* rt = nullptr;
        dfs(rt, 0, inorder.size() - 1);
        return rt;
    }

    void dfsDebug(TreeNode* p) {
        if (!p)return;
        std::cout << p->val << std::endl;
        dfsDebug(p->left);
        dfsDebug(p->right);
    }

    void dfsDebugMd(TreeNode* p) {
        if (!p)return;
        dfsDebugMd(p->left);
        std::cout << p->val << std::endl;
        dfsDebugMd(p->right);
    }
};

int main() {

    Solution s;
    std::vector<int> pr = { 9,15,7,20,3 };
    std::vector<int> md = { 9,3,15,20,7 };
    auto x = s.buildTree(md,pr);
    s.dfsDebug(x);
    std::cout << "xxxx\n";
    s.dfsDebugMd(x);
    return 0;
}