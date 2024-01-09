#include <iostream>
#include <unordered_map>

class Node {
public:
    int val;
    Node* next;
    Node* random;

    Node(int _val) {
        val = _val;
        next = nullptr;
        random = nullptr;
    }
};

class Solution {
public:
    std::unordered_map<Node*, Node*> clonedNodeList;

    Node* copyRandomList(Node* head) {
        if (!head)return nullptr;
        Node* clone = new Node(head->val);
        clonedNodeList[head] = clone;
        if (head->next) {
            clone->next = copyRandomList(head->next);
        }
        if (head->random) {
            if (clonedNodeList.count(head->random)) {
                clone->random = clonedNodeList[head->random];
            }
            else {
                clone->random = nullptr;
            }
        }
        return clone;
    }

    void print(Node* root) {
        if (!root)return;
        std::cout << root->val << ",";
        if (root->next) {
            std::cout << "-NEXT->" << root->next->val;
        }
        if (root->random) {
            std::cout << "-RAND->" << root->random->val;
        }
        std::cout << std::endl;
        print(root->next);
    }
};

int main() {
    Solution s;
    Node* a = new Node(1);
    Node* b = new Node(2);
    a->next = b;
    a->random = b;
    b->random = b;

    auto w = s.copyRandomList(a);
    s.print(w);

    return 0;
}