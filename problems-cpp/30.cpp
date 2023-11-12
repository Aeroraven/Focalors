#include <iostream>
#include <string>
#include <vector>
#include <memory>
#include <deque>
#include <algorithm>
#include <map>
using namespace std;

constexpr static int MOD1 = 37633;
constexpr static int MOD2 = 112909;

template<typename T,typename U>
struct LinkedListNode {
    T value;
    U index;
    LinkedListNode<T,U>* next = nullptr;
};

using StringHashNode = LinkedListNode<const string*,int>;

class StringHashTable {
public:
    constexpr static int numBuckets = MOD1;
    StringHashNode buckets[numBuckets];

    int stringHash(const string& w) {
        int h = 0;
        for(const auto & p:w) {
            h = (h * 31 + (p - 'a')) % numBuckets;
        }
        return h;
    }
    int stringHashSubstr(const string& w, int bg, int ed) {
        int h = 0;
        for (int i = bg; i <= ed; i++) {
            h = (h * 31 + (w[i] - 'a')) % numBuckets;
        }
        return h;
    }
    void insertString(const string* w,const int& idx) {
        auto hashValue = stringHash(*w);
        auto node = new StringHashNode();
        node->index = idx;
        node->value = w;
        node->next = buckets[hashValue].next;
        buckets[hashValue].next = node;
    }
    int testExistenceSubstr(const string& w, int bg, int ed) {
        auto hashValue = stringHashSubstr(w, bg, ed);
        auto first = buckets[hashValue].next;
        while (first != nullptr) {
            bool validFlag = true;
            for (int i = bg; i <= ed; i++) {
                if (w[i] != (*first->value)[i - bg]) {
                    validFlag = false;
                    break;
                }
            }
            if (validFlag) {
                return first->index;
            }
            first = first->next;
        }
        return -1;
    }

};

class Solution {
public:
    StringHashTable hashTable;

    vector<int> findSubstring(string s, vector<string>& words) {
        
        //Store all required words into a hash table.
        int wordCounts = static_cast<int>(words.size());
        map<int, int> wordFreq;
        auto wordData = words.data();

        for (int i = 0; i < wordCounts; i++) {
            auto aIdx = hashTable.testExistenceSubstr(wordData[i], 0, wordData[i].size() - 1);
            if (aIdx == -1) {
                hashTable.insertString(&wordData[i], i);
                wordFreq[i] = 1;
            }
            else {
                wordFreq[aIdx] += 1;
            }

        }

        int* wordOccurrence = new int[wordCounts];
        int sumOccur = 0;
        int maxOffset = static_cast<int>(words[0].size());
        int gS = maxOffset;
        int sL = static_cast<int>(s.size());
        
        vector<int> ans;

        for (int offset = 0; offset < maxOffset; offset++) {
            //cout << "Query Offset=" << offset << endl;

            sumOccur = 0;
            memset(wordOccurrence, 0, sizeof(int) * wordCounts);
            deque<int> slideWindow;

            int startPos = offset;

            if (wordCounts * gS + offset - 1>=sL) {
                continue;
            }

            // Initialize the sliding window
            for (int i = 0; i < wordCounts; i++) {
               
                auto idx = hashTable.testExistenceSubstr(s, i * gS + offset, (i + 1) * gS + offset - 1);
                if (idx != -1) {
                    if (wordOccurrence[idx] < wordFreq[idx]) {
                        sumOccur += 1;
                    }
                    wordOccurrence[idx] += 1;
                }
                slideWindow.push_back(idx);
                
            }
            if (sumOccur == wordCounts) {
                ans.push_back(startPos);
            }

            // Start iterating the remaining part
            for (int i = wordCounts * gS + offset; i < sL; i += gS) {
                startPos += gS;
                if (i + gS - 1 >= sL) {
                    break;
                }
                // Pop the queue front
                auto front = slideWindow.front();
                slideWindow.pop_front();
                if (front != -1) {
                    if (wordOccurrence[front] <= wordFreq[front] && wordOccurrence[front] >= 1) {
                        sumOccur -= 1;
                    }
                    wordOccurrence[front]--;
                }

                // Insert into the queue tail
                auto idx = hashTable.testExistenceSubstr(s, i, i + gS - 1);
                
                if (idx != -1) {
                    if (wordOccurrence[idx] < wordFreq[idx]) {
                        sumOccur += 1;
                    }
                    wordOccurrence[idx] += 1;
                }
                slideWindow.push_back(idx);

                // Check if the substring meets the requirement
                if (sumOccur == wordCounts) {
                    ans.push_back(startPos);
                }
            }
        }

        // Although sort is not necessary...
        sort(ans.begin(), ans.end());

        return ans;
    }
};

Solution w;

int main() {
    int n;
    string s, a;
    vector<string> x;
    cin >> s >> n;
    for (int i = 0; i < n; i++) {
        cin >> a;
        x.push_back(a);
    }
    auto p = w.findSubstring(s, x);
    for (const auto& m : p) {
        cout << m << " ";
    }
    return 0;
}