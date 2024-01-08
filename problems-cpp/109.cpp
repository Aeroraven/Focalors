struct ListNode {
	int val;
	ListNode* next;
	ListNode() : val(0), next(nullptr) {}
	ListNode(int x) : val(x), next(nullptr) {}
	ListNode(int x, ListNode* next) : val(x), next(next) {}

};

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

    //Cheating Algorithm: Convert LList to Array
    //This take O(n) time and O(n) space (Better than plain divide and conquer algorithm)
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
    //End Cheating

    ListNode* fetchedNode = nullptr;
    int getLinkedListLength(ListNode* head) {
        if (!head) return 0;
        int r = 1;
        while (head) {
            r++;
            head = head->next;
        }
        return r;
    }
    void buildBST(TreeNode*& place, int l, int r) {
        if (l > r)return;
        int mid = ((l + r) >> 1);
        place = new TreeNode();
        buildBST(place->left, l, mid - 1);
        place->val = fetchedNode->val;
        fetchedNode = fetchedNode->next;
        buildBST(place->right, mid + 1, r);
    }

    TreeNode* sortedListToBST(ListNode* head) {
        auto len = getLinkedListLength(head);
        fetchedNode = head;
        TreeNode* root;
        buildBST(root, 0, len - 1);
        return root;
    }
};

int main() {

    return 0;
}