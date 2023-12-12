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
        ListNode* wr = new ListNode, * t;
        wr->next = head;
        t = wr;
        if (wr->next == nullptr)return head;
        ListNode* i = head;
        ListNode* j = head->next;
        while (j) {
            if (i->val == j->val) {
                j = j->next;
            }
            else {
                if (i->next != j) {
                    wr->next = j;
                    i = j;
                    j = j->next;
                }
                else {
                    wr = i;
                    i = i->next;
                    j = j->next;
                }
            }
        }
        if (i->next != j) {
            wr->next = j;
        }
        return t->next;
    }
};