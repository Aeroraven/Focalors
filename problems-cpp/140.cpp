#include <iostream>
#include <string>
#include <vector>
#include <unordered_map>
using namespace std;

class Solution {
public:
    vector<string> wordBreak(string s, vector<string>& wordDict) {
        // Let F(i) denote the feasibility to break substr (0,i) using words in the dictionary.
        // F(i) = F(j) & Lookup(j+1,i), where Lookup is a hash-accelerated function.
        // For all (i,j) pairs that meet conds above, append j and look-up result to V[i]
        // By backtracking V[s.last], we can obtain all possible solutions.

        int sL = static_cast<int>(s.size());
        int wL = static_cast<int>(wordDict.size());

        // Build a hash map
        constexpr static int MOD = 65003;
        int head[MOD];
        memset(head, -1, sizeof(head));
        vector<int> refIndex;
        vector<int> refNext;

        auto hashFunction = [&](const string& w) {
            int val = 0;
            for (int i = w.size() - 1; i >= 0;i--) {
                val = (val * 31 + (w[i] - 'a')) % MOD;
            }
            return val;
        };
        for (int i = 0; i < wL; i++) {
            auto hashval = hashFunction(wordDict[i]);
            refIndex.push_back(i);
            refNext.push_back(head[hashval]);
            head[hashval] = i;
            //cout << wordDict[i] << "->" << hashval << endl;
        }

        // Find possible solutions, (forwarding process)
        bool* f = new bool[sL];
        memset(f, 0, sizeof(bool) * sL);
        vector<vector<int>> answerFrom(sL);
        vector<vector<int>> answerFromLookup(sL);
        for (int i = 0; i < sL; i++) {
            int srcHashVal = 0;
            for (int j = i; j >= 0; j--) {
                srcHashVal = (srcHashVal * 31 + (s[j] - 'a')) % MOD;
                if (j != 0 && f[j - 1] == false)continue;
                if (head[srcHashVal] == -1)continue;

                // Make strict comparison
                auto subs = s.substr(j, i - j + 1);
                for (int k = head[srcHashVal]; k != -1; k = refNext[k]) {
                    if (wordDict[refIndex[k]] == subs) {
                        f[i] = true;
                        answerFrom[i].push_back(j);
                        answerFromLookup[i].push_back(k);
                    }
                }
            }
        }
        // Backtracking to gather answers
        int* posStack = new int[sL+2];
        int* curVistingAnsw = new int[sL+2];
        int stackTop = 1;
        vector<string> totalAns;

        posStack[0] = sL - 1;
        curVistingAnsw[0] = -1;
        while (stackTop) {
            if (posStack[stackTop-1] == -1) {
                string ansA = "";
                for (int i = stackTop - 2; i >= 0; i--) {
                    ansA += wordDict[answerFromLookup[posStack[i]][curVistingAnsw[i]]];
                    if (i > 0) {
                        ansA += ' ';
                    }
                    
                }
                cout << ansA << endl;
                totalAns.push_back(ansA);
                stackTop--;
                continue;
            }
            //cout << "Current: " << posStack[stackTop - 1] << "," << stackTop << endl;
            curVistingAnsw[stackTop - 1]++;
            if (curVistingAnsw[stackTop - 1] >= answerFrom[posStack[stackTop-1]].size()) {
                stackTop--;
                continue;
            }
            int from = answerFrom[posStack[stackTop - 1]][curVistingAnsw[stackTop - 1]] - 1;
            stackTop++;
            //cout << "Stack Top++" << endl;
            posStack[stackTop - 1] = from;
            curVistingAnsw[stackTop - 1] = -1;
        }
        return totalAns;
    }
};

int main() {
    Solution s;
    vector<string> dict = { "a","aa","aaa","aaaa","aaaaa" };
    string t = "aaaaaaaaa";
    s.wordBreak(t, dict);
    return 0;
}