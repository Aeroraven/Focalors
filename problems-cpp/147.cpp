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
    ListNode* insertionSortList(ListNode* head) {
        if (head == nullptr || head->next == nullptr)return head;
        ListNode* ret = head;
        ListNode* cur = head->next;

        ret->next = nullptr;
        while (cur) {
            auto next = cur->next;
            if (cur->val < ret->val) {
                cur->next = ret;
                ret = cur;
            }
            else {
                ListNode* inspPrev = nullptr;
                auto insp = ret;
                while (insp != nullptr && cur->val >= insp->val) {
                    inspPrev = insp;
                    insp = insp->next;
                }
                cur->next = insp;
                if (inspPrev != nullptr) {
                    inspPrev->next = cur;
                }
            }
            cur = next;
        }   
        return ret;
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
    auto w = arrayToList({ 1,1 });
    w = s.insertionSortList(w);
    while (w) {
        std::cout << w->val << ",";
        w = w->next;
    }
    return 0;
}