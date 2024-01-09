#include <iostream>

struct ListNode {
    int val;
    ListNode* next;
    ListNode(int x) : val(x), next(nullptr) {}
};
class Solution {
public:
    ListNode* detectCycle(ListNode* head) {
        // Assume the length of cycle list is 'c' and the remaining part is 'a'
        // When the slow pointer enter the cycle, it has already moved 'a' steps
        // And the fast pointer has moved 2a steps, it's currently at element ([a%c]) (in cycle)
        // To make two pointers meet, 'b' steps is required for the slower pointer, and (b+d) step for faster pointer
        // 'd' is the remaining distance for faster ptr to reach the starting point of cycle again
        // Here, slower ptr moved (a+b) steps and faster ptr moved (a+b+b+d) steps
        // Obviously, a=d

        ListNode* slower = head, *faster = head;
        bool flag = false;
        while (slower && faster) {
            
            slower = slower->next;
            faster = faster->next;
            if (faster) {
                faster = faster->next;
            }
            if (slower == nullptr || faster == nullptr)return nullptr;

            if (slower == faster) {
                flag = true;
                break;
            }
        }
        if (!flag)return nullptr;

        ListNode* rep = head;
        while (true) {
            if (rep == slower)return rep;
            rep = rep->next;
            slower = slower->next;
        }
        return nullptr;
    }
};

int main() {
    Solution s;
    ListNode a(3);
    ListNode a2(9);
    ListNode b(2);
    ListNode c(0);
    ListNode d(4);
    a.next = &a2;
    a2.next = &b;
    b.next = &c;
    c.next = &d;
    d.next = &a2;
    auto p = s.detectCycle(&a);
    std::cout << p->val << std::endl;
    return 0;
}