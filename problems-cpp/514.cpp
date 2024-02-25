#include <iostream>
#include <cstring>
using namespace std;

class Solution {
public:
    int findRotateSteps(string ring, string key) {
        const int MAXV = 90000000;
        int n = ring.size();
        int m = key.size();

        int* vf = new int[m*n];
#define f(x,y) (vf[(x)*n+(y)])

        //Init
        for (int i = 0; i < n;i++) {
            if (ring[i] == key[0]) {
                f(0, i) = std::min(n - i, i) + 1;
            }
            else {
                f(0, i) = MAXV;
            }
        }

        //After
        for (int i = 1; i < m; i++) {
            for (int j = 0; j < n; j++) {
                f(i, j) = MAXV;
                if (key[i] != ring[j])continue;
                for (int k = 0; k < n; k++) {
                    //Last K->Top, Req J->Top
                    int p = (k - j + n) % n;
                    int q = n - p;
                    int minx = std::min(p, q);
                    f(i, j) = std::min(f(i, j), f(i - 1, k) + minx + 1);
                }
            }
        }

        //Ans
        int ans = MAXV;
        for (int i = 0; i < n; i++) {
            ans = std::min(f(m - 1, i), ans);
        }
        return ans;
    }
};

int main() {
    Solution s;
    cout << s.findRotateSteps("godding", "godding") << endl;
    return 0;
}