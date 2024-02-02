#include <iostream>
#include <vector>
using namespace std;

struct ListNode {
    int val;
    ListNode* next;
    ListNode(int x) : val(x), next(nullptr) {}
};

class Solution {
public:
    ListNode* reverseList(ListNode* head) {
        if (head == nullptr)return head;
        ListNode* cur = head;
        ListNode* prev = nullptr;
        ListNode* next;
        while (cur != nullptr) {
            next = cur->next;
            cur->next = prev;
            prev = cur;
            cur = next;
        }
        return prev;
    }
    bool isPalindrome(ListNode* head) {
        if (head == nullptr || head->next == nullptr)return true;
        ListNode* slow = head;
        ListNode* fast = head;
        while (fast!=nullptr) {
            slow = slow->next;
            fast = fast->next;
            if (fast != nullptr) {
                fast = fast->next;
            }
        }
        ListNode* tail = reverseList(slow);
        bool flag = true;
        while (tail != nullptr) {
            if (tail->val != head->val) {
                flag = false;
                break;
            }
            tail = tail->next;
            head = head->next;
        }
        return flag;
    }
};

ListNode* arrayToList(vector<int> p) {
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
    auto w = arrayToList({ 1 });
    cout << s.isPalindrome(w) << endl;
    return 0;
}