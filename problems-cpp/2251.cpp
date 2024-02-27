#include <vector>
#include <queue>
#include <iostream>
#include <algorithm>
using namespace std;

class Solution {
public:
    vector<int> fullBloomFlowers(vector<vector<int>>& flowers, vector<int>& people) {
        vector<pair<int, int>> rangeW;
        vector<pair<int, int>> pw;
        for (int i = 0; i < flowers.size(); i++) {
            rangeW.push_back({ flowers[i][0],1 });
            rangeW.push_back({ flowers[i][1] + 1,-1 });
        }
        for (int i = 0; i < people.size(); i++) {
            pw.push_back({ people[i],i });
        }
        auto cmp = [](const pair<int, int>& a, const pair<int, int>& b)->bool {
            return a.first < b.first;
        };
        sort(rangeW.begin(), rangeW.end(), cmp);
        sort(pw.begin(), pw.end(), cmp);
        int cur = 0;
        int curFlowers = 0;
        vector<int> ret(people.size());
        for (int i = 0; i < people.size(); i++) {
            while (cur < rangeW.size() && rangeW[cur].first <= pw[i].first) {
                curFlowers += rangeW[cur].second;
                cur++;
            }
            ret[pw[i].second] = curFlowers;
        }

        return ret;
    }
};
int main() {
    Solution s;
    vector<vector<int>> fl = { {30,41},{15,16},{65,98},{30,31},{41,58},{61,90} };
    vector<int> pw = { 92,144,122,56,56,64,30,16,102,111,10,54,52,120,139,20,79,19 };
    auto p = s.fullBloomFlowers(fl, pw);
    for (auto x : p) {
        cout << x << endl;
    }
    
    return 0;
}