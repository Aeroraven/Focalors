#include <queue>
class Node {
public:
    int val;
    Node* left;
    Node* right;
    Node* next;
    Node() : val(0), left(NULL), right(NULL), next(NULL) {}
    Node(int _val) : val(_val), left(NULL), right(NULL), next(NULL) {}
    Node(int _val, Node* _left, Node* _right, Node* _next)
        : val(_val), left(_left), right(_right), next(_next) {}
};


class Solution {
public:
    Node* connect(Node* root) {
        if (root == nullptr) return nullptr;
        std::queue<Node*> q;
        int reqBase = 0, reqTotal = 1, cnt = 0;
        q.push(root);
        while (!q.empty()) {
            auto fr = q.front(); q.pop();
            cnt++;
            if (cnt == reqTotal) {
                reqBase++;
                reqTotal += (1 << reqBase);
            }
            else {
                if (!q.empty()) {
                    fr->next = q.front();
                }
            }
            if (fr->left) {
                q.push(fr->left);
            }
            if (fr->right) {
                q.push(fr->right);
            }
        }
        return root;
    }
};

int main() {

    return 0;
}