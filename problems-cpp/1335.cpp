#include <vector>
#include <iostream>
#include <algorithm>
#include <cstring>
using namespace std;
class Solution {
public:
    int minDifficulty(vector<int>& jobDifficulty, int d) {
        int n = jobDifficulty.size();
        if (n < d)return -1;

        int* vf = new int[n * d];
#define f(x,y) (vf[(x)*d+(y)])

        int maxv = 0;
        for (int i = 0; i < n; i++) {
            maxv = std::max(maxv, jobDifficulty[i]);
            f(i, 0) = maxv;
        }
        for (int i = 1; i < d; i++) {
            for (int j = 0; j < n; j++) {
                //f(j,i) = min(f(k,i-1)+max(diff[k+1]...diff[j]))
                maxv = jobDifficulty[j];
                f(j, i) = 40000000;
                for (int k = j - 1; k >= 0; k--) {
                    f(j, i) = std::min(f(j, i), f(k, i - 1) + maxv);
                    maxv = std::max(maxv, jobDifficulty[k]);
                }
            }
        }
        return f(n - 1, d - 1);
    }
};
int main() {
    Solution s;
    vector<int> a = { 1,1,1 };
    cout << s.minDifficulty(a, 3) << endl;
    return 0;
}