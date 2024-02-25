#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    vector<vector<int>> edgeList;
    vector<int> numChild;
    vector<int> downPath;
    vector<int> vis;
    vector<int> ans;

    void dfs1(int id) {
        numChild[id] = 1;
        downPath[id] = 0;
        vis[id] = 1;
        for (int i = 0; i < edgeList[id].size(); i++) {
            int to = edgeList[id][i];
            if (!vis[to]) {
                dfs1(to);
                numChild[id] += numChild[to];
                downPath[id] += numChild[to] + downPath[to];
            }
        }
    }

    void dfs2(int id,int accuPathLen,int accuNode) {
        vis[id] = 2;
        ans[id]=(accuPathLen+downPath[id]);


        for (int i = 0; i < edgeList[id].size(); i++) {
            int to = edgeList[id][i];
            if (vis[to]==1) {
                int outerNodes = numChild[id] - numChild[to];
                int nextAccPath = downPath[id] - (downPath[to]+numChild[to]);

                int totlOuterNodes = outerNodes + accuNode;
                int totlAccPath = accuPathLen + nextAccPath + totlOuterNodes;
                dfs2(to, totlAccPath, totlOuterNodes);
            }
        }
    }

    vector<int> sumOfDistancesInTree(int n, vector<vector<int>>& edges) {
        edgeList.reserve(n);
        edgeList.resize(n);
        numChild.reserve(n);
        numChild.resize(n);
        downPath.reserve(n);
        downPath.resize(n);
        ans.reserve(n);
        ans.resize(n);
        for (int i = 0; i < n - 1; i++) {
            vis.push_back(0);
            edgeList[edges[i][0]].push_back(edges[i][1]);
            edgeList[edges[i][1]].push_back(edges[i][0]);
        }
        vis.push_back(0);
        dfs1(0);
        dfs2(0, 0, 0);
        return ans;
    }
};

int main() {
    Solution s;
    vector<vector<int>> a = { {0,1},{0,2},{2,3},{2,4},{2,5} };
    vector<int> p = s.sumOfDistancesInTree(6, a);
    for (auto i : p) {
        cout << i << ",";
    }
    return 0;
}