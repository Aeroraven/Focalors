#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    int numberOfOne(int x) {
        int ans = 0;
        while (x) {
            x -= x & (-x);
            ans++;
        }
        return ans;
    }
    int maxStudents(vector<vector<char>>& seats) {
        int f[8][256];
        int r = seats.size(), c = seats[0].size();
        int totlState = (1 << c);
        int* seatMask = new int[r];
        seatMask[r - 1] = 0;
        for (int i = 0; i < c; i++) {
            
            if (seats[r - 1][i] == '.') {
                seatMask[r-1] |= (1 << i);
            }
        }
        auto validState = [&](int sta,int mask)->bool {
            
            if ((mask | sta) != mask)return false;
            int adj = false;
            for (int j = 1; j < c; j++) {
                int curDigit = (1 << j);
                int prevDigit = (1 << (j - 1));
                if ((sta & curDigit) && (sta & prevDigit)) {
                    adj = true;
                }
            }
            if (adj)return false;
            return true;
        };
        for (int i = 0; i < totlState; i++) {
            if (validState(i, seatMask[r - 1])) {
                f[r - 1][i] = numberOfOne(i);
                cout << "F(" << r - 1 << "," << i << ")" << f[r - 1][i] << "#"<<seatMask[r-1]<<  endl;
            }
            else {
                f[r - 1][i] = INT_MIN;
            }
        }

        for (int i = r - 2; i >= 0; i--) {
            seatMask[i] = 0;
            for (int j = 0; j < c; j++) {
                if (seats[i][j] == '.') {
                    seatMask[i] |= (1 << j);
                }
            }
            for (int j = 0; j < totlState; j++) {
                f[i][j] = INT_MIN;
                if (!validState(j, seatMask[i])) {
                    f[i][j] = INT_MIN;
                    continue;
                }
                int gain = numberOfOne(j);
                int forbidMask = 0;
                for (int k = 0; k < c; k++) {
                    if (j & (1 << k)) {
                        if (k != 0)forbidMask |= (1 << (k - 1));
                        if (k != c - 1)forbidMask |= (1 << (k + 1));
                    }
                }
                
                for (int k = 0; k < totlState; k++) {
                    if (f[i + 1][k] == INT_MIN)continue;
                    if (k & forbidMask)continue;
                    f[i][j] = std::max(f[i][j], f[i + 1][k] + gain);
                }
                cout << "F(" << i << "," << j << ")" << f[i][j] << endl;
            }
        }
        int ans = 0;
        for (int i = 0; i < totlState; i++) {
            if (f[0][i] != INT_MIN) {
                ans = std::max(ans, f[0][i]);
            }
        }
        return ans;
    }
};

int main() {
    vector<vector<char>> p = { {'#','.','#','#','.','#'},
              {'.','#','#','#','#','.'},
              {'#','.','#','#','.','#'} 
              };
    Solution s;
    cout << s.maxStudents(p) << endl;
    return 0;
}