#include <iostream>
#include <tuple>
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
    const int MAXV = 100000;
    vector<tuple<int, int, int>> f = { {0,0,0} };
    void dfs(TreeNode* root) {
        if (root == nullptr)return;
        if (root->val == 0) {
            root->val = f.size();
            f.push_back({ 1,0,0 });
        }
        dfs(root->left);
        dfs(root->right);
        
        int leftIns = MAXV, leftCov = 0, leftMiss = 0;
        int rightIns = MAXV, rightCov = 0, rightMiss = 0;
        if (root->left) {
            leftIns = std::get<0>(f[root->left->val]);
            leftCov = std::get<1>(f[root->left->val]);
            leftMiss = std::get<2>(f[root->left->val]);
        }
        if (root->right) {
            rightIns = std::get<0>(f[root->right->val]);
            rightCov = std::get<1>(f[root->right->val]);
            rightMiss = std::get<2>(f[root->right->val]);
        }
        //If add monitor
        std::get<0>(f[root->val]) += std::min(std::min(leftIns, leftCov), leftMiss);
        std::get<0>(f[root->val]) += std::min(std::min(rightIns, rightCov), rightMiss);
        //Without monitor but with coverage from children
        std::get<1>(f[root->val]) = std::min(
            leftIns + std::min(std::min(rightIns, rightCov), rightMiss),
            rightIns + std::min(std::min(leftIns, leftCov), leftMiss)
        );
        //Without monitor but with chihldren covered
        std::get<2>(f[root->val]) = leftCov + rightCov;
    }
    int minCameraCover(TreeNode* root) {
        dfs(root);
        if (root == nullptr)return 0;
        return std::min(std::get<0>(f[root->val]), std::get<1>(f[root->val]));
    }
};

int main() {
    return 0;
}