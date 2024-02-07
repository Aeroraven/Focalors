#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>
struct Entry {
    int profits;
    int capital;
    bool operator <=(const Entry& p) const {
        return profits <= p.profits;
    }
    bool operator < (const Entry& p) const {
        return profits < p.profits;
    }
};

class Solution {
public:
    int findMaximizedCapital(int k, int w, std::vector<int>& profits, std::vector<int>& capital) {
        std::vector<Entry> p;
        int n = profits.size();
        for (int i = 0; i < n; i++) {
            p.push_back({ profits[i],capital[i] });
        }
        auto comparer = [](const Entry& a, const Entry& b) {
            return a.capital < b.capital;
        };
        std::sort(p.begin(), p.end(),comparer);

        int cur = 0;
        int ans = w, usedK = 0;
        std::priority_queue<Entry> q;

        //for (auto& x : p) {
        //    std::cout << x.capital << "," << x.profits << std::endl;
        //}

        while (usedK<k) {
            while (cur<n) {
                if (p[cur].capital <= ans) {
                    q.push(p[cur]);
                    cur++;
                    continue;
                }
                break;
            }
            if (q.empty())break;
            auto& best = q.top();
            ans += best.profits;
            //std::cout << "ADDED:" << best.profits << std::endl;
            q.pop();
            usedK++;
        }
        return ans;
    }
};
int main() {
    Solution s;
    std::vector<int> profits = { 1,2,3 };
    std::vector<int> capital = { 1,1,2 };
    std::cout << s.findMaximizedCapital(1, 2, profits, capital) << std::endl;
    return 0;
}