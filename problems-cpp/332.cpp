#include <iostream>
#include <vector>
#include <string>
#include <map>
#include <functional>
#include <algorithm>
using namespace std;

class Solution {
public:
    vector<string> findItinerary(vector<vector<string>>& tickets) {
        auto hashFunc = [](const string& st) {
            return 100000 * (st[0] - 'A') + 1000 * (st[1] - 'A') + (st[2] - 'A');
        };
        int* del = new int[tickets.size()];
        memset(del, 0, sizeof(int) * tickets.size());
        map<int, vector<pair<int,int>>> edge;
        for (int i = 0; i < tickets.size(); i++) {
            int start = hashFunc(tickets[i][0]);
            int end = hashFunc(tickets[i][1]);
            cout << start << tickets[i][0] << "->" << end << tickets[i][1] << endl;
            if (!edge.count(start)) {
                edge[start] = vector<pair<int,int>>();
            }
            edge[start].push_back({ end,i });
        }
        for (auto& [k, v] : edge) {
            sort(edge[k].begin(), edge[k].end(), [](const pair<int, int>& a, const pair<int, int>& b) {
                return a.first < b.first;
            });
        }
        vector<string> ans;
        function<void(int)> dfs = [&](int node) {
            for (int i = 0; i < edge[node].size(); i++) {
                cout << node<<"->>"<< edge[node][i].first << endl;
                if (del[edge[node][i].second]) {
                    continue;
                }
                del[edge[node][i].second] = 1;
                
                dfs(edge[node][i].first);
                ans.push_back(std::move(tickets[edge[node][i].second][1]));
                
            }
        };
        dfs(hashFunc("JFK"));
        ans.push_back("JFK");
        std::reverse(ans.begin(), ans.end());
        return ans;
    }
};

int main() {
    Solution s;
    vector<vector<string>> x = { {"EZE","AXA"},{"TIA","ANU"},{"ANU","JFK"},{"JFK","ANU"},{"ANU","EZE"},{"TIA","ANU"},{"AXA","TIA"},{"TIA","JFK"},{"ANU","TIA"},{"JFK","TIA"} };
    auto w = s.findItinerary(x);
    for (auto& p : w) {
        cout << p << ",";
    }
    return 0;
}