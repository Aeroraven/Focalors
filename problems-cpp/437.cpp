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
    int reqTarget = 0;
    int ans = 0;
    std::map<long long, int> pr;

    void insertPrefix(long long pref) {
        if (pr.count(pref)) {
            pr[pref]++;
        }
        else {
            pr[pref] = 1;
        }
    }
    int getSumPrefix(long long pref) {
        if (pr.count(pref)) {
            return pr[pref];
        }
        return 0;
    }

    void pathSumImpl(TreeNode* root, long long prefixSum) {
        if (root == nullptr)return;
        auto curPrefix = prefixSum + root->val;
        ans += getSumPrefix(reqTarget - curPrefix);
        insertPrefix(curPrefix);
        pathSumImpl(root->left, curPrefix);
        pathSumImpl(root->right, curPrefix);
        pr[curPrefix]--;
    }
    int pathSum(TreeNode* root, int targetSum) {
        pr[0]++;
        reqTarget = targetSum;
        pathSumImpl(root, 0);
        return ans;
    }
};