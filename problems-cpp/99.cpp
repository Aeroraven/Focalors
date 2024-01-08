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
    TreeNode* last = nullptr, *first = nullptr, *firstNext=nullptr, *second = nullptr;
    bool flag = false;
    void midOrderTraversal(TreeNode* p) {
        if (!p || second!=nullptr)return;
        midOrderTraversal(p->left);
        if (second != nullptr)return;
        if (last != nullptr && first==nullptr && (p->val<last->val)) {
            first = last;
            firstNext = p;
        }
        else if (last != nullptr && first != nullptr && (p->val < last->val)) {
            second = p;
        }
        last = p;
        midOrderTraversal(p->right);
    }
    void recoverTree(TreeNode* root) {
        midOrderTraversal(root);
        auto swapValue = [&](TreeNode* a, TreeNode* b)->void {
            auto f = a->val;
            a->val = b->val;
            b->val = f;
        };
        if (second == nullptr) {
            swapValue(first, firstNext);
        }
        else {
            swapValue(first, second);
        }
    }

    void printResult(TreeNode* p) {
        if (!p)return;
        printResult(p->left);
        std::cout << p->val << std::endl;
        printResult(p->right);
    }
};

int main() {
    auto x = new TreeNode(1, new TreeNode(3, nullptr, new TreeNode(2)), nullptr);
    Solution s;
    s.printResult(x);
    std::cout << "===\n";
    s.recoverTree(x);
    s.printResult(x);
    return 0;
}