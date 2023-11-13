#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

class Solution {
public:
    int candy(vector<int>& ratings) {
        constexpr static int NINF = -20000000;
        int rL = static_cast<int>(ratings.size());
        int* idx = new int[rL];
        int* f = new int[rL];
        for (int i = 0; i < rL; i++) {
            idx[i] = i;
            f[i] = 0;
        }
        sort(idx, idx + rL, [&](int a, int b) {
            return ratings[a] < ratings[b];
        });
        int ans = 0;
        for (int i = 0; i < rL; i++) {
           
            int leftIdx = idx[i] - 1;
            int left = (leftIdx >= 0) ? ratings[leftIdx] : -NINF;
            int rightIdx = idx[i] + 1;
            int right = (rightIdx < rL) ? ratings[rightIdx] : -NINF;
            f[idx[i]] = 1;
            if (ratings[idx[i]] > left) {
                f[idx[i]] = max(f[leftIdx] + 1, f[idx[i]]);
            }
            if (ratings[idx[i]] > right) {
                f[idx[i]] = max(f[rightIdx] + 1, f[idx[i]]);
            }
            ans += f[idx[i]];
        }
        return  ans;
    }
};

int main() {
    Solution s;
    int n;
    int r;
    while (true) {
        cin >> n;
        vector<int> w;
        for (int i = 0; i < n; i++) {
            cin >> r;
            w.push_back(r);
        }
        cout << s.candy(w) << endl;
    }
    
    
	return 0;
}