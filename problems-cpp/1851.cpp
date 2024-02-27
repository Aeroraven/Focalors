#include <iostream>
#include <vector>
#include <queue>
using namespace std;

struct Interval {
    int l, r;
    bool operator <(const Interval& p)const {
        int lA = r - l, lB = p.r - p.l;
        if (lA == lB) {
            return l > p.l;
        }
        else {
            return lA > lB;
        }
    }
};

class Solution {
public:
    vector<int> minInterval(vector<vector<int>>& ints, vector<int>& q) {
        vector<vector<int>> qs;
        for (int i = 0; i < q.size(); i++) {
            qs.push_back({ q[i],i });
        }

        priority_queue<Interval> p;
        auto cmp = [](const vector<int>& a, const vector<int>& b) {
            return a[0] < b[0];
            };
        sort(ints.begin(), ints.end(), cmp);
        sort(qs.begin(), qs.end(), cmp);

        vector<int> ret(qs.size());
        int icur = 0;
        for (int i = 0; i < q.size(); i++) {
            while (icur < ints.size() && ints[icur][0] <= qs[i][0]) {
                p.push({ ints[icur][0],ints[icur][1] });
                icur++;
            }
            int ans = -1;
            while (!p.empty()) {
                auto s = p.top();
                if (s.r < qs[i][0]) {
                    p.pop();
                    continue;
                }
                break;
            }

            if (!p.empty()) {
                auto v = p.top();
                //cout << qs[i][0] << "|" << v.l << "," << v.r << endl;
                ans = v.r - v.l + 1;
            }
            ret[qs[i][1]] = ans;
        }
        return ret;
    }
};

int main() {
    Solution s;
    vector<vector<int>> a = { {1,4},{2,4},{3,6},{4,4} };
    vector<int> p = { 2,3,4,5 };
    auto r = s.minInterval(a, p);
    for (auto& v : r) {
        cout << v << ",";
    }
    return 0;
}