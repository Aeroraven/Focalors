#include <string>
#include <vector>
#include <cstring>
#include <unordered_map>
#include <iostream>

class Solution {
public:
    constexpr static int MOD = 4397;

    bool wordBreak(std::string s, std::vector<std::string>& wordDict) {
        auto n = s.length();
        bool* vf = new bool[n+1];
        memset(vf, 0, sizeof(bool) * (n + 1));
        vf[0] = true;
        std::unordered_map<int, std::vector<std::string>> dictHashTable;
        auto f = [&](int x)->bool& {
            return vf[x + 1];
        };

        // Update dict hash table
        for (auto& cand : wordDict) {
            int hashValue = 0;
            for (int i = cand.size() - 1; i >= 0; i--) {
                hashValue = ((hashValue * 31) + (cand[i] - 'a' + 1)) % MOD;
            }
            if (!dictHashTable.count(hashValue)) {
                dictHashTable[hashValue] = std::vector<std::string>();
            }
            dictHashTable[hashValue].push_back(std::move(cand));
        }

        // Update feasibility 
        for (int i = 0; i < n; i++) {
            int hashValue = 0;
            bool& fx = f(i);
            for (int j = i - 1; j >= -1; j--) {
                hashValue = ((hashValue * 31) + (s[j+1] - 'a' + 1)) % MOD;
                if (f(j) && dictHashTable.count(hashValue)) {
                    auto substr = s.substr(j + 1, (i - j));
                    for (auto& cand : dictHashTable[hashValue]) {
                        if (substr == cand) {
                            f(i) = true;
                        }
                    }
                }
                if (fx)break;
            }
        }
        return f(n - 1);
    }
};

int main() {
    using namespace std;
    Solution s;
    vector<string> dict = { "aaa","cats","and","sand","dog" };
    string src = "aaa";
    cout << boolalpha<< s.wordBreak(src, dict) << endl;

    return 0;
}