#include <string>
#include <queue>
#include <sstream>
#include <iostream>
using namespace std;

struct TreeNode {
    int val;
    TreeNode* left;
    TreeNode* right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

class Codec {
public:
    // Encodes a tree to a single string.
    string serialize(TreeNode* root) {
        int accuNull = 0;
        stringstream ss;
        queue<TreeNode*> q;
        q.push(root);
        while (!q.empty()) {
            auto tp = q.front();

            q.pop();
            if (tp == nullptr) {
                accuNull++;
            }
            else {
                if (accuNull) {
                    for (int i = 0; i < accuNull; i++) {
                        ss << "1001 ";
                    }
                    accuNull = 0;
                }
                ss << tp->val << " ";
                q.push(tp->left);
                q.push(tp->right);
                
            }
        }
        return ss.str();
    }

    // Decodes your encoded data to tree.
    TreeNode* deserialize(string data) {
        if (data.size() == 0)return nullptr;
        TreeNode* ret = nullptr;
        stringstream ss;
        ss << data;
        int counter = 0;
        queue<TreeNode*> q;
        while (ss.rdbuf()->in_avail()) {
            string d;
            ss >> d;
            if (d.size() == 0)break;
            int val = std::stoi(d);
            if (ret == nullptr) {
                ret = new TreeNode(val);
                q.push(ret);
            }
            else {
                auto tp = q.front();
                counter++;
                if (counter == 2) {
                    q.pop();
                    counter = 0;
                }
                TreeNode* child = (val==1001)?nullptr:new TreeNode(val);
                if (counter == 1) {
                    tp->left = child;
                }
                else {
                    tp->right = child;
                }
                if (child) {
                    q.push(child);
                }
            }
        }
        return ret;
    }

    void dfs(TreeNode* x) {
        if (!x)return;
        cout << x->val << ",";
        dfs(x->left);
        dfs(x->right);
        return;
    }
};

int main() {
    Codec s;
    TreeNode* root = new TreeNode(1);
    TreeNode* a = new TreeNode(2);
    TreeNode* b = new TreeNode(3);
    TreeNode* c = new TreeNode(4);
    TreeNode* d = new TreeNode(5);
    root->left = a;
    root->right = b;
    b->left = c;
    b->right = d;

    string data = s.serialize(nullptr);
    cout << data << endl;

    TreeNode* sv = s.deserialize(data);
    s.dfs(sv);

    return 0;
}