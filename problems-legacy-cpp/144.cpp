class Solution {
public:
	std::vector<int> preorderTraversal(TreeNode* root) {
		std::vector<int> returnValues;
		struct LinkListNode {
			TreeNode* value;
			LinkListNode* next, * prior;
		};
		LinkListNode* stack_Head = new LinkListNode(), * newElement, * stack_Top;
		if (root == nullptr)return {};
		newElement = new LinkListNode();
		newElement->value = root;
		newElement->next = nullptr;
		newElement->prior = stack_Head;
		stack_Head->next = newElement;
		stack_Top = newElement;
		while (stack_Head->next != nullptr) { //Loop until the stack is empty
			TreeNode* stack_TopElement = stack_Top->value;
			LinkListNode* priorNode = stack_Top->prior;
			returnValues.push_back(stack_TopElement->val);
			priorNode->next = nullptr;
			delete stack_Top;
			stack_Top = priorNode;
			if (stack_TopElement->right != nullptr) { //Insert the right child node
				newElement = new LinkListNode();
				newElement->next = nullptr;
				newElement->prior = stack_Top;
				newElement->value = stack_TopElement->right;
				stack_Top->next = newElement;
				stack_Top = newElement;
			}
			if (stack_TopElement->left != nullptr) { //Insert the left child node
				newElement = new LinkListNode();
				newElement->next = nullptr;
				newElement->prior = stack_Top;
				newElement->value = stack_TopElement->left;
				stack_Top->next = newElement;
				stack_Top = newElement;
			}
		}
		return returnValues;
	}
};