#include <vector>
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
    vector<TreeNode*> dfs(int n) {
        if (n == 0)return{};
        if (n == 1)return { new TreeNode(0) };
        int rem = n - 1;
        vector<TreeNode*> ret = {};
        for (int i = 1; i <= n - 2; i += 2) {
            int leftRem = i;
            int rightRem = rem - i;
            vector<TreeNode*> left = dfs(i);
            vector<TreeNode*> right = dfs(rem - i);
            for (auto l : left) {
                for (auto r : right) {
                    ret.push_back(new TreeNode(0, l, r));
                }
            }
        }
        return ret;
    }
    vector<TreeNode*> allPossibleFBT(int n) {
        if (n % 2 == 0)return {};
        return dfs(n);
    }
};