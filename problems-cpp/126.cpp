#include <iostream>
#include <string>
#include <vector>
#include <queue>
#include <unordered_map>
#include <unordered_set>
using namespace std;


class HashMap {
public:
    int nodes = 0;
    int edges = 0;
    unordered_map<string, int> hmap;
    unordered_map<int, int> remap;
    vector<unordered_set<int>> heads;
    int getWord(string& wd) {

        if (hmap.count(wd))return hmap[wd];
        hmap[wd] = nodes++;
        heads.push_back(unordered_set<int>());
        return nodes - 1;
    }
    void addEdge(int _u, int _v) {
        heads[_u].insert(_v);
    }
    void addWordRelations(string& wd,int remapId = -1) {
        int id1 = getWord(wd);
        remap[id1] = remapId;
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
    vector<int> record;
    HashMap graph;
    int* vis = nullptr;
    vector<vector<string>> answer;
    int answerDepth = 0;

    void findLaddersDfs(int curId,int curDepth, vector<string>& wordList,string& beginWord) {
        if (curDepth == 0) {
            vector<string> newAnswer;
            for (int i = 0; i <= answerDepth; i+=2) {
                int idx = graph.remap[record[i]];
                if (idx >= 0) {
                    newAnswer.push_back(wordList[idx]);
                }
                else {
                    newAnswer.push_back(beginWord);
                }
            }
            answer.push_back(std::move(newAnswer));
        }
        else {
            int fL = static_cast<int>(graph.heads[curId].size());
            for (auto v : graph.heads[curId]) {
                //cout << "Travel:" << curId << "," << v << endl;
                if (vis[curId] == vis[v] + 1) {
                    record[curDepth - 1] = v;
                    findLaddersDfs(v, curDepth - 1, wordList, beginWord);
                }
            }
        }
    }

    vector<vector<string>> findLadders(string beginWord, string endWord, vector<string>& wordList) {

        int sL = beginWord.length();
        int bwIdx = -1;
        int wL = wordList.size();

        // Create Word Dictionary
        int di = 0;
        for (auto& w : wordList) {
            graph.addWordRelations(w,di++);
        }

        // Find if begin word in word list
        graph.addWordRelations(beginWord);

        // Find end word
        int ewIdx = -1;
        if (graph.checkExist(endWord) == false) {
            return answer;
        }
        bwIdx = graph.getWord(beginWord);
        ewIdx = graph.getWord(endWord);

        // BFS
        vis = new int[graph.nodes];
        memset(vis, -1, sizeof(int) * graph.nodes);
        queue<int> qlist;

        //Mark starting point
        qlist.push(bwIdx);
        vis[bwIdx] = 0;
        bool findFlag = false;
        while (!qlist.empty()) {
            int front = qlist.front();
            qlist.pop();

            int fL = graph.heads[front].size();
            for (auto v : graph.heads[front]) {
                if (vis[v] == -1) {
                    vis[v] = vis[front] + 1;
                    qlist.push(v);

                    if (v == ewIdx) {
                        //return  vis[v] / 2 + 1;
                        findFlag = true;
                        break;
                    }
                }
            }
            if (findFlag)break;
        }
        if (vis[ewIdx] == -1) {
            return answer;
        }

        //Backtrace to get answers
        record.resize(vis[ewIdx] + 1);
        answerDepth = vis[ewIdx];
        record[vis[ewIdx]] = ewIdx;
        findLaddersDfs(ewIdx, vis[ewIdx], wordList, beginWord);

        return answer;
    }
};

int main() {

    vector<string> wl = { "hot","dot","dog","lot","log" };
    string bw = "hit";
    string ew = "cog";

    Solution sol;
    auto x = sol.findLadders(bw, ew, wl);
    for (auto& ls : x) {
        //cout << "==============" << endl;
        for (auto& p : ls) {
            cout << p << ",";
        }
        cout << endl;
    }
    //cout << sol.ladderLength(bw, ew, wl);
    return 0;
}