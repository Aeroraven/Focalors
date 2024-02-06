#include <vector>
#include <iostream>

class Solution {
public:
    int setFind(int* f, int a) {
        int pa = a;
        while (f[pa] != pa)pa = f[pa];
        while (f[a] != a) {
            int nxt = f[a];
            f[a] = pa;
            a = nxt;
        }
        return pa;
    }

    std::vector<int> findRedundantDirectedConnection(std::vector<std::vector<int>>& edges) {
        int n = edges.size();
        int* f = new int[n];
        int* ind = new int[n];
        int abnormalChild = -1;
        std::vector<int>* ans = nullptr;
        std::vector<std::vector<int>*> abnormalFather;

        for (int i = 0; i < n; i++)f[i] = i, ind[i] = 0;
        for (auto& e : edges) {
            ind[e[1] - 1]++;
            if (ind[e[1] - 1] >= 2) {
                abnormalChild = e[1] - 1;
            }
        }
        //Indeg==1
        for (auto& e : edges) {
            int ch = e[1] - 1, fa = e[0] - 1;
            if (abnormalChild == ch) {
                abnormalFather.push_back(&e);
                continue;
            }
            if (f[ch] != ch || ch == fa || setFind(f, ch) == setFind(f, fa)) {
                ans = &e;
                break;
            }
            else {
                f[setFind(f, ch)] = f[setFind(f, fa)];
            }
        }
        //Indeg==2
        for (auto& pe : abnormalFather) {
            auto e = *pe;
            int ch = e[1] - 1, fa = e[0] - 1;
            if (f[ch] != ch || ch == fa || setFind(f, ch) == setFind(f, fa)) {
                ans = pe;
                break;
            }
            else {
                f[setFind(f, ch)] = f[setFind(f, fa)];
            }
        }

        return std::move(*ans);
    }
};

int main() {
    Solution s;
    std::vector<std::vector<int>> p = { {2,1},{3,1},{4,2},{1,4} };
    auto px = s.findRedundantDirectedConnection(p);
    std::cout << px[0] << "," << px[1] << std::endl;
    return 0;
}