class Solution {
public:
	ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
		if (l1 == nullptr && l2 == nullptr)return nullptr;
		bool carry = 0;
		ListNode* cur = new ListNode(0);
		ListNode* tmp = nullptr;
		ListNode* ret = cur;
		while (l1 != nullptr && l2 != nullptr) {
			cur->val = l1->val + l2->val + (int)carry;
			carry = 0;
			if (cur->val >= 10)cur->val -= 10, carry = 1;
			l1 = l1->next;
			l2 = l2->next;
			if (l1 == nullptr && l2 == nullptr)break;
			tmp = new ListNode(0);
			cur->next = tmp;
			cur = tmp;
		}
		while (l1 != nullptr) {
			cur->val = l1->val + (int)carry;
			carry = 0;
			if (cur->val >= 10)cur->val -= 10, carry = 1;
			l1 = l1->next;
			if (l1 != nullptr) {
				tmp = new ListNode(0);
				cur->next = tmp;
				cur = tmp;
			}
		}
		while (l2 != nullptr) {
			cur->val = l2->val + (int)carry;
			carry = 0;
			if (cur->val >= 10)cur->val -= 10, carry = 1;
			l2 = l2->next;
			if (l2 != nullptr) {
				tmp = new ListNode(0);
				cur->next = tmp;
				cur = tmp;
			}
		}
		if (carry == 1) {
			tmp = new ListNode(0);
			cur->next = tmp;
			cur = tmp;
			cur->val = 1;
		}
		return ret;
	}
};