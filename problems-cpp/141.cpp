#include <iostream>

struct ListNode {
    int val;
    ListNode* next;
    ListNode(int x) : val(x), next(nullptr) {}
};

class Solution {
public:
    bool hasCycle(ListNode* head) {
        ListNode* slow = head, * fast  = head;
        if (head) {
            fast = slow->next;
        }
        while (slow && fast) {
            if (slow == fast)return true;
            slow = slow->next;
            fast = fast->next;
            if (fast) {
                fast = fast->next;
            }
            else {
                fast = nullptr;
            }
        }
        return false;
    }
};

int main() {
    Solution s;
    ListNode a(3);
    ListNode b(2);
    ListNode c(0);
    ListNode d(4);
    a.next = &b;
    b.next = &c;
    c.next = &d;
    d.next = &b;
    std::cout << s.hasCycle(&a);
}