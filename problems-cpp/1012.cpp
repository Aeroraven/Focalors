#include<iostream>
#include<cstring>
#include<vector>
#include<set>
using namespace std;

class Solution {
public:
    int compareOne(int x) {
        vector<int> a;
        set<int> b;
        while (x) {
            a.push_back(x % 10);
            b.insert(x % 10);
            x /= 10;
        }
        return a.size() != b.size();
    }
    int compare(int n) {
        int ans = 0;
        for (int i = 1; i <= n; i++) {
            ans += compareOne(i);
        }
        return ans;
    }
    int numDupDigitsAtMostN(int n) {
        if (n <= 9)return 0;
        vector<int> dg;
        set<int> dgx;
        int n2 = n;
        while (n2) {
            dg.push_back(n2 % 10);
            dgx.insert(n2 % 10);
            n2 /= 10;
        }
        int m = dg.size();
        
        using Rec = int[10][1024]; 
        Rec* f = new Rec[m];
        memset(f, 0, sizeof(Rec) * m);
        int ans = (dg.size() == dgx.size()) - 1;
        for (int i = 0; i <= 9;i++) {
            f[0][i][1 << i] = 1;
            ans += 1;
        }

        
        for (int d = 1; d < m ; d++) {
            for (int i = 0; i <= 1023; i++) {
                for (int cd = 0; cd <= 9; cd++) {
                    for (int j = 0; j <= 9; j++) {
                        int curMask = (1 << cd);
                        if (i & curMask)continue;
                        f[d][cd][i | curMask] += f[d - 1][j][i];
                        if (d < m - 1 && cd!=0) {
                            ans += f[d - 1][j][i];
                        }
                    }
                }
            }
        }

        int banMask = 0;
        set<int> tr;
        for (int i = m - 1; i >= 0; i--) {
            
            int curd = dg[i];
            for (int j = ((i==m-1)?1:0); j < curd; j++) {
                for (int k = 0; k <= 1023; k++) {
                    if (banMask & k)continue;
                    if (f[i][j][k] == 0)continue;
                    ans += f[i][j][k];

                }
            }
            banMask |= (1 << curd);

            tr.insert(dg[i]);
            if ((m - 1) - i + 1 != tr.size())break;
        }

        return n - ans;
    }
};

int main() {
    Solution s;
    for (int i = 1; i <= 100; i++) {
        int ans = s.numDupDigitsAtMostN(i);
        int stx = s.compare(i);
        cout << "T=" << i << " ANS=" << ans << " STD=" << stx << endl;
        if (ans != stx) {
            cout << "F=" << i << " ANS=" << ans << " STD=" << stx << endl;
            break;
        }
    }
    return 0;
}