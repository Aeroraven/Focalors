
public class TreeNode
{
    public int val;
    public TreeNode? left;
    public TreeNode? right;
    public TreeNode(int val = 0, TreeNode left = null, TreeNode right = null)
    {
        this.val = val;
        this.left = left;
        this.right = right;
    }
}

public class Solution
{
    public TreeNode? tail = null;
    public void Flatten(TreeNode root)
    {
        if (root == null) return;
        TreeNode? left = root.left;
        TreeNode? right = root.right;

        if (tail != null)
        {
            tail.right = root;
        }
        tail = root;
        tail.left = null;
        tail.right = null;
        Flatten(left);
        Flatten(right);
    }
}