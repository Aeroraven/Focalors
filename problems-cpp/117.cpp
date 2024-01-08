#include <iostream>

class Node {
public:
    int val;
    Node* left;
    Node* right;
    Node* next;
    Node() : val(0), left(nullptr), right(nullptr), next(nullptr) {}
    Node(int _val) : val(_val), left(nullptr), right(nullptr), next(nullptr) {}
    Node(int _val, Node* _left, Node* _right, Node* _next)
        : val(_val), left(_left), right(_right), next(_next) {}
};

class Solution {
public:

    void dfs(Node* root, Node* next) {
        // "next" stores the leftmost successor node that lies in the same level as "root"
        root->next = next;

        /*
        if (next != nullptr) {
            std::cout << "LINKING" << root->val << "->" << next->val << std::endl;
        }
        else {
            std::cout << "LINKING" << root->val << "-> Nullptr" << std::endl;
        }*/
        
        Node* rightNextLayer = nullptr;
        if (next != nullptr) {
            Node* curCandidate = next;
            while (curCandidate) {
                if (curCandidate->left) {
                    rightNextLayer = curCandidate->left;
                    break;
                }
                if (curCandidate->right) {
                    rightNextLayer = curCandidate->right;
                    break;
                }
                curCandidate = curCandidate->next;
            }
        }
        
        // right subtree
        if (root->right) {
            dfs(root->right, rightNextLayer);
        }

        //left subtree
        if (root->left) {
            if (root->right) {
                dfs(root->left, root->right);
            }
            else {
                dfs(root->left, rightNextLayer);
            }
        }
    }

    Node* connect(Node* root) {
        if (root == nullptr) {
            return root;
        }
        dfs(root, nullptr);
        return root;
    }
};

int main() {

    Solution s;
    auto x = new Node(10,
        new Node(1,
            new Node(2, new Node(4,new Node(100),nullptr,nullptr), new Node(5), nullptr),
            new Node(3, nullptr, new Node(7), nullptr), nullptr
        ),
        new Node(11, new Node(9), new Node(12, nullptr,new Node(13),nullptr),nullptr),
        nullptr
    );
    s.connect(x);
}