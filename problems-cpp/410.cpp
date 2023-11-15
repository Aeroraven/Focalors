#include <iostream>
#include <vector>
#include <cstring>
using namespace std;

#define f(i,j) vf[(i & 1) * (nL + 1) + (j + 1)]

class Solution {
public:
    int splitArray(vector<int>& nums, int k) {
        // F[k][i] = min{max(F[k-1][j],sum[i]-sum[j])}, subject to j<i

        int nL = static_cast<int>(nums.size());
        int* vf = new int[2 * (nL + 1)];

        int* psum = new int[nL];
        memset(vf, 0xff, sizeof(int) * (2 * (nL + 1)));
        psum[0] = nums[0];
        for (int i = 1; i < nL; i++) {
            f(0, i) = 0x6fffffff;
            psum[i] = psum[i - 1] + nums[i];
        }

        f(0, -1) = 0;
        f(0, 0) = 0x6fffffff;

        for (int i = 1; i <= k; i++) {
            for (int j = 0; j < nL; j++) {
                if(i==1) f(i, j) = f(i - 1, -1) + psum[j];
                else f(i,j) = 0x6fffffff;
                for (int p = 0; p < j; p++) {
                    f(i, j) = min(f(i, j), max(f(i - 1, p), psum[j] - psum[p]));
                }
                cout << i << "," << j << " " << f(i, j) << endl;
            }
            f(i, -1) = 0x6fffffff;
            
        }
        int ret = f(k, nL - 1);
        delete[] psum;
        delete[] vf;
        return ret;
    }
};

int main() {
    int n, k;
    cin >> n >> k;
    int w;
    vector<int> g;
    for (int i = 0; i < n; i++) {
        cin >> w;
        g.push_back(w);
    }
    Solution s;
    cout << s.splitArray(g, k) << endl;
    return 0;
}