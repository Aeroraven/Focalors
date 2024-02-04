#include <iostream>
#include <algorithm>
#include <vector>
#include <deque>
#include <cmath>
#include <cstdlib>
#include <unordered_map>
#include <unordered_set>
#include <queue>
using namespace std;

class Solution {
public:
    int minJumps(vector<int>& arr) {
        constexpr int INF = 0x7fffffff;
        const auto arrSz = arr.size();
        using HashTableContainer = unordered_set<int>;
        unordered_map<int, HashTableContainer*> hashTable;
        vector<int> minDist(arrSz);
        queue<int> q;

        for (auto i = 0; i < arrSz; i++) {
            cout << i << endl;
            minDist[i] = INF;
            if (hashTable.count(arr.at(i)) == 0) {
                hashTable[arr[i]] = new HashTableContainer();
            }
            hashTable[arr[i]]->insert(i);
        }
        q.push(0);
        minDist[0] = 0;
        while (!q.empty()) {
            auto front = q.front();
            q.pop();
            auto& vx = hashTable[arr[front]];
            if (front == arrSz - 1) {
                return minDist[front];
            }
            vector<int> rmElements = {};
            for (auto p : *vx) {
                rmElements.push_back(p);
                if (minDist[p] == INF) {
                    minDist[p] = minDist[front] + 1;
                    q.push(p);
                    if (p == arrSz - 1) {
                        return minDist[front] + 1;
                    }
                }
            }
            for (auto p : rmElements) {
                vx->erase(p);
            }
            if ((front + 1 < arrSz) && minDist[front + 1] == INF) {
                minDist[front + 1] = minDist[front] + 1;
                q.push(front + 1);
                if (front + 1 == arrSz - 1) {
                    return minDist[front] + 1;
                }
            }
            if ((front - 1 >= 0) && minDist[front - 1] == INF) {
                minDist[front - 1] = minDist[front] + 1;
                q.push(front - 1);
            }
        }
        return -1;
    }
};

int main() {
    Solution s;
    vector<int> x = { 1 };
    cout << s.minJumps(x);
    return 0;
}