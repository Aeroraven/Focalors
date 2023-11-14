#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>
using namespace std;

struct IntervalEndpoint {
    int index;
    bool leftEndpoint;
    int pos;
    int height;
};

struct Interval {
    int index;
    int height;
    
};

bool operator<(const Interval& a, const Interval& b) {
    return a.height < b.height;
}
class Solution {
public:
    vector<vector<int>> getSkyline(vector<vector<int>>& buildings) {
        constexpr static int LEFT = 0, RIGHT = 1, HEIGHT = 2;
        int bL = static_cast<int>(buildings.size());

        // First, record the endpoints of given intervals
        IntervalEndpoint* endpoints = new IntervalEndpoint[bL * 2];
        for (int i = 0; i < bL; i++) {
            endpoints[i * 2].index = i;
            endpoints[i * 2].leftEndpoint = true;
            endpoints[i * 2].pos = buildings[i][LEFT];
            endpoints[i * 2].height = buildings[i][HEIGHT];

            endpoints[i * 2 + 1].index = i;
            endpoints[i * 2 + 1].leftEndpoint = false;
            endpoints[i * 2 + 1].pos = buildings[i][RIGHT];
            endpoints[i * 2 + 1].height = buildings[i][HEIGHT];

        }

        std::sort(endpoints, endpoints + bL * 2, [](const IntervalEndpoint& a, const IntervalEndpoint& b) {
            return a.pos < b.pos;
        });

        // Use a heap to store the highest building.
        bool* active = new bool[bL];
        memset(active, 0, sizeof(bool) * bL);
        priority_queue<Interval> heap;
        int opL = 0;
        
        int lastHeight = 0;
        vector<vector<int>> answer = {};
        for (int i = 0; i < 2 * bL; i++) {
            // Gather all endpoints at the position `endpoint[i].pos`
            if (i + 1 < 2 * bL && endpoints[i + 1].pos == endpoints[i].pos) {
                continue;
            }
            // Peform operations on endpoints from opL to i
            for (int j = opL; j <= i; j++) {
                if (endpoints[j].leftEndpoint) {
                    // Insert into heap
                    heap.push({ endpoints[j].index,endpoints[j].height });
                    active[endpoints[j].index] = true;
                }
                else {
                    // Add lazy mark on right endpoints
                    active[endpoints[j].index] = false;
                }
            }

            // Query the height at the position `endpoint[i].pos`
            while ((!heap.empty()) && (!active[heap.top().index])) {
                heap.pop();
            }
            int curTop = heap.empty() ? 0 : heap.top().height;
            if (curTop != lastHeight) {
                answer.push_back({ endpoints[i].pos,curTop });
            }
            lastHeight = curTop;
            opL = i + 1;
        }
        return answer;

    }
};

int main() {
    Solution s;
    vector<vector<int>> a = { {{0,25,1},{1,3,5},{2,4,5},{4,6,10},{6,7,2},{9,11,3},{12,15,4},{16,18,9},{16,17,4},{17,18,20},{20,22,1},{20,21,15},{20,22,60},{20,21,130},{21,22,15}} };
    auto b = s.getSkyline(a);
    for (int i = 0; i < b.size(); i++) {
        cout << b[i][0] << "," << b[i][1] << endl;
    }
    return 0;
}