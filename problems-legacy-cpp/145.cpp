class Solution {
public:
	std::vector<int> postorderTraversal(TreeNode* root) {
		struct LinkedListNode {
			TreeNode* data;
			bool lchildVis;
			LinkedListNode* prior, * next;
		};
		if (root == nullptr)return {};
		std::vector<int> returnValue;
		LinkedListNode* stack_head = new LinkedListNode(), * stack_top, * newElement, * stack_topElement;
		newElement = new LinkedListNode();
		newElement->data = root;
		newElement->lchildVis = false;
		newElement->prior = stack_head;
		newElement->next = nullptr;
		stack_head->next = newElement;
		stack_top = newElement;
		while (stack_head->next != nullptr) { //Loop until the stack is empty
			stack_topElement = stack_top;
			if (stack_topElement->lchildVis == false) {
				stack_topElement->lchildVis = true;
				if (stack_topElement->data->right != nullptr) {
					newElement = new LinkedListNode();
					newElement->next = nullptr;
					newElement->prior = stack_top;
					newElement->data = stack_topElement->data->right;
					newElement->lchildVis = false;
					stack_top->next = newElement;
					stack_top = newElement;
				}
				if (stack_topElement->data->left != nullptr) {
					newElement = new LinkedListNode();
					newElement->next = nullptr;
					newElement->prior = stack_top;
					newElement->data = stack_topElement->data->left;
					newElement->lchildVis = false;
					stack_top->next = newElement;
					stack_top = newElement;
				}
			}
			else {
				returnValue.push_back(stack_topElement->data->val);
				stack_top->prior->next = nullptr;
				stack_top = stack_top->prior;
			}
		}
		return returnValue;
	}
};