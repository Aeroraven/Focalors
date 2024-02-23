#include <iostream>
#include <algorithm>
#include <vector>
#include <deque>
using namespace std;

class Solution {
public:
    int findMaxValueOfEquation(vector<vector<int>>& points, int k) {
        /*
        auto sortFunc = [](const vector<int>& a, const vector<int>& b)->bool {
            return a[0] < b[0];
        };
        
        sort(points.begin(), points.end(), sortFunc);*/
        int ans = INT_MIN;
        deque<int> q;
        int n = points.size();
        for (int i = 0; i < n; i++) {
            while (!q.empty()) {
                if (points[i][0] - points[q.front()][0] > k) {
                    q.pop_front();
                    continue;
                }
                break;
            }
            if (!q.empty()) {
                int tp = q.front();
                ans = std::max(ans, points[i][0] + points[i][1] + points[tp][1] - points[tp][0]);
            }
            int cv = points[i][1] - points[i][0];
            while (!q.empty()) {
                int tp = q.back();
                if (cv >= points[tp][1] - points[tp][0]) {
                    q.pop_back();
                    continue;
                }
                break;
            }
            q.push_back(i);
        }
        return ans;
    }
};

int main() {
    Solution s;
    vector<vector<int>> v = { {0,0},{3,0},{9,2} };
    cout << s.findMaxValueOfEquation(v, 3) << endl;
    return 0;
}