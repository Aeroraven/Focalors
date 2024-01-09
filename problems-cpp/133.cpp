#include <unordered_map>
#include <vector>

class Node {
public:
    int val;
    std::vector<Node*> neighbors;
    Node() {
        val = 0;
        neighbors = std::vector<Node*>();
    }
    Node(int _val) {
        val = _val;
        neighbors = std::vector<Node*>();
    }
    Node(int _val, std::vector<Node*> _neighbors) {
        val = _val;
        neighbors = _neighbors;
    }
};

class Solution {
public:
    std::unordered_map<int, Node*> clonedVertList;

    Node* cloneGraph(Node* node) {
        if (node == nullptr) return nullptr;
        Node* clonedNode = new Node(node->val);
        clonedVertList[node->val] = clonedNode;
        for (auto p : node->neighbors) {
            if (!clonedVertList.count(p->val)) {
                auto childClonedNode = cloneGraph(p);
                clonedNode->neighbors.push_back(childClonedNode);
            }
            else {
                clonedNode->neighbors.push_back(clonedVertList[p->val]);
            }
        }
        return clonedNode;
    }
};