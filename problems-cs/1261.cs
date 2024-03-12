

using System.Collections.Generic;

public class TreeNode
{
    public int val;
    public TreeNode? left;
    public TreeNode? right;
    public TreeNode(int val = 0, TreeNode? left = null, TreeNode? right = null)
    {
        this.val = val;
        this.left = left;
        this.right = right;
    }
}

public class FindElements
{
    public HashSet<int> hset = new HashSet<int>();

    public FindElements(TreeNode root)
    {
        root.val = 0;
        hset.Add(root.val);
        Build(root);
    }

    public void Build(TreeNode root)
    {
        if (root.left != null)
        {
            root.left.val = root.val * 2 + 1;
            hset.Add(root.left.val);
            Build(root.left);
        }
        if (root.right != null)
        {
            root.right.val = root.val * 2 + 2;
            hset.Add(root.right.val);
            Build(root.right);
        }
    }

    public bool Find(int target)
    {
        return this.hset.Contains(target);
    }
}