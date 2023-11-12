#include <iostream>
#include <memory>
#include <vector>
#include <queue>
using namespace std;

struct ListNode {
    int val;
    ListNode* next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode* next) : val(x), next(next) {}
};

class ListNodeCompare {
public:
    bool operator()(const ListNode* a, const ListNode* b) {
        return a->val < b->val;
    }
};

class Solution {
public:
    ListNode* mergeKLists(vector<ListNode*>& lists) {
        priority_queue<ListNode*,std::vector<ListNode*>,ListNodeCompare> heap;
        int vL = static_cast<int>(lists.size());
        for (auto& el : lists) {
            if (el != nullptr) {
                heap.push(el);
            }
        }
        ListNode* ret = nullptr;
        ListNode* tail = nullptr;
        while (!heap.empty()) {
            auto tp = heap.top();
            auto tpNext = tp->next;
            heap.pop();
            if (tail == nullptr) {
                ret = tp;
                tail = tp;
            }
            else {
                tail->next = tp;
                tail = tail->next;
            }
            tail->next = nullptr;
            if (tpNext != nullptr) {
                heap.push(tpNext);
            }
        }
        return ret;
    }
};


int main() {

	return 0;
}