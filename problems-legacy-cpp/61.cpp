class Solution {
public:
    ListNode* rotateRight(ListNode* head, int k) {
        if (head == nullptr)return nullptr;
        int cntlen = 0;
        int t = 0;
        ListNode* g = new ListNode(), * w;
        g->next = head;
        ListNode* i = g->next;
        while (i) {
            cntlen++;
            if (i->next == nullptr) {
                w = i;
            }
            i = i->next;
        }
        k = k % cntlen;
        if (k == 0) {
            return head;
        }
        i = g->next;
        while (i) {
            t++;
            if (t == cntlen - k) {
                break;
            }
            i = i->next;
        }
        ListNode* j = i->next;
        i->next = nullptr;
        w->next = g->next;
        g->next = j;
        return g->next;

    }
};
¿ØÖÆÌ¨
