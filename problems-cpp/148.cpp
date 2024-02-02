#include <iostream>
#include <vector>

struct ListNode {
    int val;
    ListNode* next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode* next) : val(x), next(next) {}
};

class Solution {
public:
    ListNode* sortList(ListNode* head) {
        // Partition
        ListNode* slow = head;
        ListNode* fast = head;
        ListNode* slowPrev = nullptr;
        while (fast != nullptr) {
            slowPrev = slow;
            slow = slow->next;
            fast = fast->next;
            if (fast) {
                fast = fast->next;
            }
        }
        if (slow == nullptr) {
            return head;
        }
        slowPrev->next = nullptr;
        auto left = sortList(head);
        auto right = sortList(slow);

        // Merge
        ListNode* retHead = nullptr;
        ListNode* retTail = nullptr;

        while (left && right) {
            ListNode* chosen;
            if (left->val <= right->val) {
                chosen = left;
                left = left->next;
            }
            else {
                chosen = right;
                right = right->next;
            }

            if (retHead == nullptr) {
                retHead = chosen;
                retTail = chosen;
            }
            else {
                retTail->next = chosen;
                chosen->next = nullptr;
                retTail = chosen;
            }
        }

        while (left) {
            auto cur = left;
            left = left->next;
            retTail->next = cur;
            cur->next = nullptr;
            retTail = cur;
        }

        while (right) {
            auto cur = right;
            right = right->next;
            retTail->next = cur;
            cur->next = nullptr;
            retTail = cur;
        }
        return retHead;
    }
};

ListNode* arrayToList(std::vector<int> p) {
    ListNode* head = nullptr;
    ListNode* tail = nullptr;
    for (auto x : p) {
        if (head == nullptr) {
            head = new ListNode(x);
            tail = head;
        }
        else {
            auto w = new ListNode(x);
            tail->next = w;
            tail = w;
        }
    }
    return head;
}

int main() {
    Solution s;
    auto w = arrayToList({ 9,8,7,6,5,4,3,2 });
    w = s.sortList(w);
    while (w) {
        std::cout << w->val << ",";
        w = w->next;
    }
    return 0;
}