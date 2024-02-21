#include <cstring>
#include <iostream>
class Solution {
public:
    int checkRecord(int n) {
        int f[2][2][3];
        constexpr static int modf = 1000000007;
        memset(f, 0, sizeof(f));
        
        //Init 
        f[1][0][0] = 1; //Present
        f[1][1][0] = 1; //Absent
        f[1][0][1] = 1; //Late

        for (int i = 2; i <= n; i++) {
            //Present
            for (int j = 0; j < 2; j++) {
                f[i % 2][j][0] = 0;
                for (int k = 0; k < 3; k++) {
                    f[i % 2][j][0] += f[(i + 1) % 2][j][k];
                    f[i % 2][j][0] %= modf;
                }
            }
            
            //Absent
            for (int k = 0; k < 3; k++) {
                f[i % 2][1][0] += f[(i + 1) % 2][0][k];
                f[i % 2][1][0] %= modf;
            }

            //Late
            for (int j = 0; j < 2; j++) {
                for (int k = 1; k < 3; k++) {
                    f[i % 2][j][k] = f[(i + 1) % 2][j][k - 1];
                }
            }
        }

        int ans = 0;
        for (int j = 0; j < 2; j++) {
            for (int k = 0; k < 3; k++) {
                ans += f[n % 2][j][k];
                ans %= modf;
            }
        }
        return ans;
    }
};

int main() {
    using namespace std;
    Solution s;
    while (true) {
        int v;
        cin >> v;
        cout << s.checkRecord(v) << endl;
    }
    return 0;
}