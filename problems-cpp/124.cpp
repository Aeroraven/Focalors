#include <iostream>
#include <cstdlib>
#include <algorithm>
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
    constexpr static int NINF = ~0x7fffffff;
    int answer = NINF;

    int maxPathSumRecur(TreeNode* root) {
        // Returns the max path sum, starting with node `root` and 
        // ending with a node in left or right subtree

        if (root == nullptr) {
            return NINF;
        }
        int leftMaxPath = maxPathSumRecur(root->left);
        int rightMaxPath = maxPathSumRecur(root->right);
        
        int lrMaxPath = max(leftMaxPath, 0) + max(rightMaxPath, 0) + root->val;
        int stMaxPath = max(max(leftMaxPath, rightMaxPath), 0) + root->val;
        answer = max(answer, max(lrMaxPath, stMaxPath));

        return stMaxPath;
    }

    int maxPathSum(TreeNode* root) {
        maxPathSumRecur(root);
        return answer;
    }
};

int main() {

	return 0;
}