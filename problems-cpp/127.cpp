#include <iostream>
#include <string>
#include <vector>
#include <queue>
using namespace std;


// Might be optimized ?
// The code req 1300ms+ running time

class Solution {
public:
    int ladderLength(string beginWord, string endWord, vector<string>& wordList) {
        int sL = beginWord.length();
        int bwIdx = -1;
        int wL = wordList.size();

        // Find if begin word in word list
        for (int i = 0; i < wL; i++) {
            if (beginWord == wordList[i]) {
                bwIdx = i;
            }
        }
        if (bwIdx == -1) {
            wordList.push_back(beginWord);
            wL = wordList.size();
            bwIdx = wL - 1;
        }
        vector<vector<int>> adjNodes(wordList.size());
        
        // Find end word
        int ewIdx = -1;
        for (int i = 0; i < wL; i++) {
            if (endWord == wordList[i]) {
                ewIdx = i;
            }
        }
        if (ewIdx == -1) {
            return 0;
        }

        // Calculate edit distance 
        for (int i = 0; i < wL; i++) {
            for (int j = i + 1; j < wL; j++) {
                int diffs = 0;
                for (int k = 0; k < sL; k++) {
                    if (wordList[i][k] != wordList[j][k]) {
                        diffs += 1;
                    }
                }
                if (diffs == 1) {
                    adjNodes[i].push_back(j);
                    adjNodes[j].push_back(i);

                    //cout << "Build Adj:" << wordList[j] << "-" << wordList[i] << endl;
                }
            }
        }

        // BFS
        int* vis = new int[wL];
        memset(vis, -1, sizeof(int) * wL);
        queue<int> qlist;

        //Mark starting point
        qlist.push(bwIdx);
        vis[bwIdx] = 1;

        while (!qlist.empty()) {
            int front = qlist.front();
            //cout<<"At Word:"<<
            qlist.pop();
            int fL = adjNodes[front].size();
            for (int i = 0; i < fL; i++) {
                if (vis[adjNodes[front][i]] == -1) {
                    vis[adjNodes[front][i]] = vis[front] + 1;
                    qlist.push(adjNodes[front][i]);

                    if (adjNodes[front][i] == ewIdx) {
                        return  vis[adjNodes[front][i]];
                    }
                }
            }
        }
        return 0;
    }
};

int main() {

    vector<string> wl = { "cog","dot","dog","lot","log" };
    string ew = "cog";
    string bw = "hit";
    Solution sol;
    cout << sol.ladderLength(bw, ew, wl);
	return 0;
}