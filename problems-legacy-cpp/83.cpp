/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
class Solution {
public:
    ListNode* deleteDuplicates(ListNode* head) {
        if (head == nullptr) return head;
        int valp = head->val;
        ListNode* cur = head->next;
        ListNode* curp = head;
        while (cur) {
            while (cur) {
                if (cur->val == valp) {
                    curp->next = cur->next;
                    cur = curp->next;
                }
                else {
                    break;
                }
            }
            if (cur == nullptr) break;
            cur = cur->next;
            if (cur == nullptr) break;
            curp = curp->next;
            valp = curp->val;
        }
        return head;

    }
};