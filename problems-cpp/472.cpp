#include <vector>
#include <string>
#include <algorithm>
#include <iostream>
using namespace std;

struct Node {
    bool tag = false;
    Node** child = nullptr;
};

class Solution {
public:
    Node* root = new Node();

    bool dfs(int start,const string& word) {
        if (start == word.size()) {
            return true;
        }
        Node* cur = root;
        int i = start;
        while (i < word.size()) {
            if (cur->child == nullptr) {
                return false;
            }
            cur = cur->child[word[i] - 'a'];
            if (cur == nullptr) {
                return false;
            }
            
            if (cur->tag) {
                auto t= dfs(i + 1, word);
                if (t)return true;
            }
            i++;
        }
        return false;
    }
    void insert(const string& word) {
        Node* cur = root;
        int i = 0;
        while (i < word.size()) {
            if (cur->child == nullptr) {
                cur->child = new Node*[26];
                memset(cur->child, 0, sizeof(Node*) * 26);
            }
            if (cur->child[word[i] - 'a'] == nullptr) {
                Node* nxt = new Node();
                cur->child[word[i] - 'a'] = nxt;
            }
            if (i == word.size() - 1) {
                cur->child[word[i] - 'a']->tag = true;
            }
            cur = cur->child[word[i] - 'a'];
            i++;
        }
    }
    vector<string> findAllConcatenatedWordsInADict(vector<string>& words) {
        auto cmp = [](const string& a, const string& b)->bool {
            return a.size() < b.size();
        };
        sort(words.begin(), words.end(), cmp);
        vector<string> ans;
        for (int i = 0; i < words.size(); i++) {
            bool valid = dfs(0, words[i]);
            
            if (valid) {
                ans.push_back(std::move(words[i]));
            }
            else {
                insert(words[i]);
            }
        }
        return ans;
    }
};

int main() {
    Solution s;
    vector<string> x = { "cat","cats","catsdogcats","dog","dogcatsdog","hippopotamuses","rat","ratcatdogcat" };
    auto w = s.findAllConcatenatedWordsInADict(x);
    for (auto& p : w) {
        cout << p << ",";
    }
    return 0;
}