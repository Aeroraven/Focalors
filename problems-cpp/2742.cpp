#include <vector>
#include <set>
#include <iostream>
using namespace std;
class Solution {
public:
    int paintWalls(vector<int>& cost, vector<int>& time) {
        //f[i,t] = min(f[i-1,t+1],f[i-1,t-time[i]]+cost[i])
        //answer = min(f[i,k]) for all k>=0
        int n = cost.size();
        auto sz = 2000;
        int* vf = new int[sz * 2];
        memset(vf, 0x7f, sz * sizeof(int) * 2);
#define f(x,y) vf[((x)&1)*sz+((y)+1000)]
        f(1, 0) = 0;
        for (int i = 0; i < n; i++) {
            for (int j = -500; j <=500 ; j++) {
                f(i, j) = min(f(i + 1, j + 1), f(i, j));
                f(i, j) = min(f(i + 1, j - time[i]) + cost[i], f(i, j));
            }
            memset(vf + (sz * (1 - (i & 1))), 0x7f, sizeof(int) * sz);
        }
        int ans = INT_MAX;
        for (int j = 0; j <= 500; j++) {
            ans = min(f(n - 1, j), ans);
        }
        return ans;
    }
};

int main() {
    vector<int> a = { 2,2,2 };
    vector<int> b = { 500,500,500 };
    Solution s;
    cout<< s.paintWalls(a, b);
    return 0;
}