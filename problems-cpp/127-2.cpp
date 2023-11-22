#include <iostream>
#include <string>
#include <vector>
#include <queue>
#include <unordered_map>
using namespace std;


class HashMap {
public:
    int nodes = 0;
    int edges = 0;
    unordered_map<string, int> hmap;
    vector<vector<int>> heads;
    vector<int> v;
    int getWord(string& wd) {
        
        if (hmap.count(wd))return hmap[wd];
        hmap[wd] = nodes++;
        heads.push_back(vector<int>());
        return nodes - 1;
    }
    void addEdge(int _u, int _v) {
        heads[_u].push_back(edges++);
        v.push_back(_v);
    }
    void addWordRelations(string& wd) {
        int id1 = getWord(wd);
        for (char& p : wd) {
            char t = p;
            p = '#';
            int id2 = getWord(wd);
            p = t;
            addEdge(id1, id2);
            addEdge(id2, id1);
        }
    }
    bool checkExist(const string& w) {
        if (hmap.count(w) != 0)return true;
        return false;
    }


};


class Solution {
public:
    int ladderLength(string beginWord, string endWord, vector<string>& wordList) {

        int sL = beginWord.length();
        int bwIdx = -1;
        int wL = wordList.size();
        HashMap graph;

        // Find if begin word in word list
        graph.addWordRelations(beginWord);

        // Create Word Dictionary
        for (auto& w : wordList) {
            graph.addWordRelations(w);
        }

        // Find end word
        int ewIdx = -1;
        if (graph.checkExist(endWord) == false) {
            return 0;
        }
        bwIdx = graph.getWord(beginWord);
        ewIdx = graph.getWord(endWord);

        // BFS
        int* vis = new int[graph.nodes];
        memset(vis, -1, sizeof(int) * graph.nodes);
        queue<int> qlist;

        //Mark starting point
        qlist.push(bwIdx);
        vis[bwIdx] = 0;

        while (!qlist.empty()) {
            int front = qlist.front();
            qlist.pop();

            int fL = graph.heads[front].size();
            for (int i = 0; i < fL; i++) {
                int v = graph.v[graph.heads[front][i]];

                if (vis[v] == -1) {
                    vis[v] = vis[front] + 1;
                    qlist.push(v);

                    if (v == ewIdx) {
                        return  vis[v] / 2 + 1;
                    }
                }
            }
        }
        return 0;
    }
};

int main() {

    vector<string> wl = { "hot","bog","bot","hit"};
    string bw = "bog";
    string ew = "hit";

    Solution sol;
    cout << sol.ladderLength(bw, ew, wl);
    return 0;
}