#include <iostream>
#include <vector>
#include <set>
#include <unordered_set>
#include <queue>
using namespace std;

class Solution {
public:
    vector<vector<int>> getAncestors(int n, vector<vector<int>>& edges) {
        vector<vector<int>> e(n);
        vector<set<int>> retw(n);
        vector<int> ind(n);
        for (auto& x : edges) {
            e[x[0]].push_back(x[1]);
            ind[x[1]]++;
        }
        
        queue<int> q;
        for (int i = 0; i < n; i++) {
            if (ind[i] == 0)q.push(i);
        }
        while (!q.empty()) {
            auto p = q.front();
            q.pop();
            for (auto v : e[p]) {
                retw[v].insert(p);
                for (auto& r : retw[p]) {
                    retw[v].insert(r);
                }
                ind[v]--;
                if (ind[v] == 0) {
                    q.push(v);
                }
            }
        }

        vector<vector<int>> ret(n);
        for (int i = 0; i < n; i++) {
            for (auto& v : retw[i]) {
                ret[i].push_back(v);
            }
        }
        return ret;
    }
};