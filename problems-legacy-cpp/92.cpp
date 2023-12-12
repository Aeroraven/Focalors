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
    ListNode* reverseBetween(ListNode* head, int left, int right) {
        ListNode* p = new ListNode(0, head);
        ListNode* w = p;
        ListNode* q = nullptr;
        ListNode* r = nullptr;
        ListNode* s = nullptr;
        int i = 1;
        for (; i < left; i++)
        {
            p = p->next;
        }
        if (p == nullptr)
        {
            return w->next;
        }
        q = p->next;
        if (q == nullptr)
        {
            return w->next;
        }
        r = p->next->next;
        s = p->next;
        for (; i <= right; i++)
        {
            if (q == nullptr)
            {
                break;
            }
            q->next = p->next;
            p->next = q;
            s->next = r;
            q = r;
            if (r != nullptr)
            {
                r = r->next;
            }

        }
        return w->next;
    }
};