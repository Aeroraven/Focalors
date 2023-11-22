
using System.Collections.Generic;
using System;
using System.Text;

public class TreeNode
{
    public int val;
    public TreeNode left;
    public TreeNode right;
    public TreeNode(int val = 0, TreeNode left = null, TreeNode right = null)
    {
        this.val = val;
        this.left = left;
        this.right = right;
    }
}

public class Solution
{
    public bool IsValidBSTRecursive(TreeNode root, long L, long R)
    {
        if (root == null) return true;
        if (!(root.val > L && root.val < R)) return false;
        return IsValidBSTRecursive(root.left, L, root.val) && IsValidBSTRecursive(root.right, root.val, R);

    }
    public bool IsValidBST(TreeNode root)
    {
        return IsValidBSTRecursive(root, -0x90000000L, 0x90000000);
    }
    public static int Main()
    {
        Solution s = new Solution();

        return 0;
    }
}

