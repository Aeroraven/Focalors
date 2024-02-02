 struct ListNode {
    int val;
    ListNode* next;
    ListNode(int x) : val(x), next(NULL) {}
    
};
class Solution {
public:
    int getListLength(ListNode* p) {
        int w = 0;
        while (p != nullptr) {
            w++;
            p = p->next;
        }
        return w;
    }
    ListNode* getIntersectionNode(ListNode* headA, ListNode* headB) {
        int la = getListLength(headA), lb = getListLength(headB);
        if (la > lb) {
            for (int i = 0; i < la - lb; i++) {
                headA = headA->next;
            }
        }
        else if (la < lb) {
            for (int i = 0; i < lb - la; i++) {
                headB = headB->next;
            }
        }
        while (headB != nullptr && headA != nullptr) {
            if (headA == headB)return headA;
            headA = headA->next;
            headB = headB->next;
        }
        return nullptr;
    }
};