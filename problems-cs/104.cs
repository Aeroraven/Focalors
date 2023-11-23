
using System;

/**
 * Definition for a binary tree node.
 * public class TreeNode {
 *     public int val;
 *     public TreeNode left;
 *     public TreeNode right;
 *     public TreeNode(int val=0, TreeNode left=null, TreeNode right=null) {
 *         this.val = val;
 *         this.left = left;
 *         this.right = right;
 *     }
 * }
 */
public class Solution
{
    int answer = 0;
    public void MaxDpethRec(TreeNode root, int depth)
    {
        answer = Math.Max(depth, answer);
        if (root == null) return;
        MaxDpethRec(root.left, depth + 1);
        MaxDpethRec(root.right, depth + 1);

    }
    public int MaxDepth(TreeNode root)
    {
        MaxDpethRec(root, 0);
        return answer;
    }
}