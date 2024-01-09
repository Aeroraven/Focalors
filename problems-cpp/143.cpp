#include <deque>
#include <iostream>

struct ListNode {
    int val;
    ListNode* next;
    ListNode(int x) : val(x), next(nullptr) {}
};


class Solution {
public:
    void reorderList(ListNode* head) {
        if (!head)return;
        std::deque<ListNode*> lx;
        ListNode* cur = head;

        while (cur) {
            lx.push_back(cur);
            cur = cur->next;
        }
        int p = 0;
        ListNode* ret = nullptr;
        while (!lx.empty()) {
            if (p & 1) {
                auto w = lx.back();
                lx.pop_back();
                ret->next = w;
                w->next = nullptr;
                ret = w;
                
            }
            else {

                auto w = lx.front();
                lx.pop_front();
                if (ret) {
                    ret->next = w;
                }
                w->next = nullptr;
                ret = w;
            }
            p += 1;
        }
    }
    void print(ListNode* p) {
        if (!p)return;
        std::cout << p->val << "," << std::endl;
        print(p->next);
    }
};

int main() {
    Solution s;
    ListNode a(1), b(2), c(3), d(4),e(5);
    a.next = &b;
    b.next = &c;
    c.next = &d;
    d.next = &e;
    s.reorderList(&a);
    s.print(&a);
    return 0;
}