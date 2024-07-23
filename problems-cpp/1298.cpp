#include <iostream>
#include <vector>
#include <cstring>
#include <queue>
using namespace std;

class Solution {
public:
    int maxCandies(vector<int>& status, vector<int>& candies, vector<vector<int>>& keys, vector<vector<int>>& containedBoxes, vector<int>& initialBoxes) {        
        int n = status.size();
        int* ind = new int[n];
        int* accessible = new int[n];
        memset(ind, 0, sizeof(int) * n);
        memset(accessible, 0, sizeof(int) * n);
        for (int i = 0; i < n; i++) {
            for (auto j : containedBoxes[i]) {
                ind[j]++;
            }
        }

        int answ = 0;
        queue<int> q;
        for (auto u : initialBoxes) {
            ind[u] = 0;
            accessible[u] = 1;
            if (status[u] == 1) {
                status[u] = 2;
                q.push(u);
            }
        }
        int ans = 0;
        while (!q.empty()) {
            auto u = q.front();
            q.pop();
            ans += candies[u];
            for (auto v : containedBoxes[u]) {
                ind[v]--;
                if (status[v] == 1 && ind[v]==0) {
                    status[v] = 2;
                    q.push(v);
                }
                accessible[v] = 1;
            }
            for (auto v : keys[u]) {
                if (status[v] == 0) {
                    status[v] = 1;
                }
                if (status[v] == 1 && ind[v] == 0 && accessible[v]) {
                    status[v] = 2;
                    q.push(v);
                }
                
            }
        }
        return ans;
    }
};

int main() {
    Solution sl;
    vector<int> s = { 1,0,1,0 };
    vector<int> c = { 7,5,4,100 };
    vector<vector<int>> k = { {},{},{1},{} };
    vector<vector<int>> cb = { {1,2},{3},{},{} };
    vector<int> init = { 0 };
    cout << sl.maxCandies(s, c, k, cb, init) << endl;
    return 0;
}