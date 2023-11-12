#include <iostream> 
using namespace std;


struct ListNode {
     int val;
     ListNode *next;
     ListNode() : val(0), next(nullptr) {}
     ListNode(int x) : val(x), next(nullptr) {}
     ListNode(int x, ListNode *next) : val(x), next(next) {}
};
 
class Solution {
public:
    ListNode* reverseLinkList(ListNode* first, ListNode* last) {
        ListNode* opL = first, * opR = first->next, * opRR = nullptr;
        while (true) {
            if (opR == nullptr || opL == last) {
                return opL;
            }
            opRR = opR->next;
            opR->next = opL;
            opL = opR;
            opR = opRR;
        }
    }
    ListNode* reverseKGroup(ListNode* head, int k) {
        ListNode* ret = nullptr;
        ListNode* tail = nullptr;

        bool validFlag = true;
        ListNode* left = head;
        ListNode* right = head;
        ListNode* rightNext = nullptr;
        while(true){
            rightNext = nullptr;
            for (int i = 0; i < k - 1; i++) {
                if (right == nullptr) {
                    validFlag = false;
                    break;
                }
                right = right->next;
            }
            if (!validFlag||right==nullptr) {
                break;
            }
            if (right->next) {
                rightNext = right->next;
            }

            // (left,...,right)->(rightNext,....)
            ListNode* rp = reverseLinkList(left, right);
            if (tail == nullptr) {
                ret = rp;
                tail = left;
            }
            else {
                tail->next = rp;
                tail = left;
            }
            tail->next = rightNext;
        }
        return ret;
    }
};

int main() {
    return 0;
}