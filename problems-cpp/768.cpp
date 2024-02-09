#include <iostream>
#include <vector>
#include <stack>
#include <tuple>
using namespace std;
class Solution {
public:
    int maxChunksToSorted(vector<int>& arr) {
        int bw = 0;
        int blocks = 0;
        int n = arr.size();
        stack<pair<int, int>> st;
        for (int i = 0; i < n; i++) {
            int rLeft = arr[i], rRight = arr[i];
            while (!st.empty() && (arr[i] < st.top().first || (arr[i] >= st.top().first && arr[i] < st.top().second))) {
                rLeft = std::min(rLeft, st.top().first);
                rRight = std::max(rRight, st.top().second);
                st.pop();
            }
            st.push({ rLeft,rRight });
        }
        return st.size();
    }
};

int main() {
    Solution s;
    vector<int> a = { 9,8,7,6,5,4,3,2,1 };
    cout << s.maxChunksToSorted(a);
    return 0;
}