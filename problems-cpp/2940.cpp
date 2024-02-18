#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

class Solution {
public:
    vector<int> leftmostBuildingQueries(vector<int>& heights, vector<vector<int>>& queries) {
        vector<int> monoStack;

        int stTop = -1;
        for (int i = 0; i < queries.size(); i++) {
            queries[i].push_back(i);
        }
        auto sortFunc = [](const vector<int>& a, const vector<int>& b) {
            return std::max(a[0], a[1]) > std::max(b[0], b[1]);
        };
        std::sort(queries.begin(), queries.end(), sortFunc);

        int n = heights.size(), m = queries.size(), curq = 0;
        vector<int> ans(m);

        for (int i = n - 1; i >= 0; i--) {
            

            while (curq<m && std::max(queries[curq][0], queries[curq][1])  == i) {

                int minPos = std::min(queries[curq][0], queries[curq][1]);
                int maxPos = std::max(queries[curq][0], queries[curq][1]);
                int minHeight = heights[minPos];
                int maxHeight = heights[maxPos];
                if (minHeight < maxHeight || (minPos==maxPos)) {
                    ans[queries[curq][2]] = maxPos;
                    curq++;
                    continue;
                }


                int l = 0;
                int r = stTop;
                int src = std::max(heights[queries[curq][0]], heights[queries[curq][1]]);

                while (l < r && r>=0) {
                    int mid = (l + r+1) / 2;
                    if (src < heights[monoStack[mid]]) {
                        l = mid ;
                    }
                    else if (src >= heights[monoStack[mid]]) {
                        r = mid - 1;
                    }


                }
                if (l > stTop || stTop==-1 ||src>= heights[monoStack[l]]) {
                    ans[queries[curq][2]] = -1;
                }
                else {
                    ans[queries[curq][2]] = monoStack[l];
                }
                curq++;
            }

            while (stTop >= 0 && heights[monoStack[stTop]] <= heights[i]) {
                stTop--;
            }
            if (monoStack.size() - 1 == stTop) {
                monoStack.push_back(i);
                stTop++;
            }
            else {
                monoStack[++stTop] = i;
            }
        }
        return ans;

    }
};

int main() {
    Solution s;
    vector<int> h = { 10,9,8,7,6,7,8,9,10 };
    vector<vector<int>> q = { {3,5} };
    auto x = s.leftmostBuildingQueries(h, q);
    for (auto v : x) {
        cout << v << ",";
    }
    return 0;
}