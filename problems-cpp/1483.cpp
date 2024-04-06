#include <iostream>
#include <vector>
using namespace std;

class TreeAncestor {
public:
    vector<vector<int>> e;
    vector<int> st;
    vector<int> vanc;
    int root = 0;
#define anc(p,k) vanc[(p)*16+(k)]

    TreeAncestor(int n, vector<int>& parent) {
        e.reserve(n);
        e.resize(n);
        vanc.reserve(n * 16);
        vanc.resize(n * 16);
        for (int i = 0; i < parent.size(); i++) {
            if (parent[i] == -1) {
                root = i;
                continue;
            }
            e[parent[i]].push_back(i);
        }
        build(root);
    }

    void build(int u) {
        auto totl = st.size();
        for (int i = totl - 1, j = 0; j < 16 && i>=0; i = totl - (1 << (++j))) {
            anc(u, j) = st[i] + 1;
        }
        st.push_back(u);
        for (auto& v : e[u]) {
            build(v);
        }
        st.pop_back();
    }

    int getKthAncestor(int node, int k) {
        if (node == -1)return -1;
        if (k == 0)return node;
        int i;
        for (i = 15; i >=0; i--) {
            if (k & (1 << i)) {
                break;
            }
        }
        return getKthAncestor(anc(node, i) - 1, k - (1 << i));
    }
};

int main() {
    vector<int> p = { -1,0,0,1,1,2,2 };
    TreeAncestor s(7, p);
    return 0;
}

/**
 * Your TreeAncestor object will be instantiated and called as such:
 * TreeAncestor* obj = new TreeAncestor(n, parent);
 * int param_1 = obj->getKthAncestor(node,k);
 */