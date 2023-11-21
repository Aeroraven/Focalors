
class Solution {
public:
	ListNode* mergeTwoLists(ListNode* l1, ListNode* l2) {
		ListNode* p1 = l1;
		ListNode* p2 = l2;
		ListNode* ret = nullptr;
		ListNode* cur;
		ListNode* tail;
		bool emptyList = true;
		while (p1 != nullptr || p2 != nullptr) {
			if (p2 == nullptr && p1 != nullptr) {
				cur = p1;
				p1 = p1->next;
			}
			else if (p1 == nullptr && p2 != nullptr) {
				cur = p2;
				p2 = p2->next;
			}
			else if (p1->val <= p2->val) {
				cur = p1;
				p1 = p1->next;
			}
			else if (p2->val < p1->val) {
				cur = p2;
				p2 = p2->next;
			}
			if (emptyList) {
				ret = cur;
				tail = cur;
				emptyList = false;
			}
			else {
				tail->next = cur;
				tail = cur;
			}

		}
		return ret;

	}
};