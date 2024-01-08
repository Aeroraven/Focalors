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
    void partition(TreeNode*& place, const std::vector<int>& nums, int l, int r) {
        if (l > r)return;
        int mid = ((l + r) >> 1);
        place = new TreeNode(nums[mid]);
        partition(place->left, nums, l, mid - 1);
        partition(place->right, nums, mid + 1, r);
    }

    TreeNode* sortedArrayToBST(std::vector<int>& nums) {
        TreeNode* rt;
        partition(rt, nums, 0, nums.size() - 1);
        return rt;
    }
};