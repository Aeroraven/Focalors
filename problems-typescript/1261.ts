

class TreeNode {
    val: number
    left: TreeNode | null
    right: TreeNode | null
    constructor(val?: number, left?: TreeNode | null, right?: TreeNode | null) {
        this.val = (val===undefined ? 0 : val)
        this.left = (left===undefined ? null : left)
        this.right = (right===undefined ? null : right)
    }
}

class FindElements {
    public tgtMap: Set<number>
    constructor(root: TreeNode | null) {
        this.tgtMap = new Set<number>();
        if (root != null) {
            root.val = 0;
            this.tgtMap.add(root.val);
            this.build(root);
        }
    }
    build(root: TreeNode | null) {
        if (root.left != null) {
            root.left.val = 2 * root.val + 1;
            this.tgtMap.add(2 * root.val + 1);
            this.build(root.left);
        }
        if (root.right != null) {
            root.right.val = 2 * root.val + 2;
            this.tgtMap.add(2 * root.val + 2);
            this.build(root.right);
        }
    }
    find(target: number): boolean {
        return this.tgtMap.has(target);
    }
}
