struct ListNode {
    int val;
    ListNode* next;
    ListNode(int x) : val(x), next(NULL) {}

};
class Solution {
public:
    ListNode* reverseList(ListNode* head) {
        if (head == nullptr)return nullptr;
        ListNode* cur = head;
        ListNode* prev = nullptr;
        ListNode* next = head->next;
        while (cur != nullptr) {
            next = cur->next;
            cur->next = prev;
            prev = cur;
            cur = next;
        }
        return prev;
    }
};