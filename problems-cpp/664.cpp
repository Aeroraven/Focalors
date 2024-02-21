#include <string>
#include <iostream>
using namespace std;

class Solution {
public:
    int strangePrinter(string s) {
        string a;
        for (int i = 0; i < s.size(); i++) {
            if (i == 0 || s[i] != s[i - 1]) {
                a.push_back(s[i]);
            }
        }
        int n = a.size();
        int* vf = new int[n * n];
        int* prev = new int[n];
        int* nexv = new int[n];
        int* prevx = new int[26];
        auto f = [&](int l, int r)->int& {
            return vf[l * n + r];
        };
        memset(nexv, 0x7f, sizeof(int) * n);
        memset(vf, 0x7f, sizeof(int) * n * n);
        memset(prevx, -1, sizeof(int) * 26);

        for (int i = 0; i < n; i++) {
            prev[i] = prevx[a[i]-'a'];
            prevx[a[i] - 'a'] = i;
            if(prev[i]!=-1)nexv[prev[i]] = i;
        }

        //Init
        for (int i = 0; i < n; i++) {
            f(i, i) = 1;
        }
        cout << a << endl;
        //bababaddcbcaabdb
        //Remain
        for (int l = 2; l <= n; l++) {
            for (int left = 0; left < n; left++) {

                int right = left + l - 1;
                if (right >= n)break;
                if (a[left] == a[right]) {
                    f(left, right) = f(left, right - 1);
                    continue;
                }
                // Right
                int curv = right;
                int accu = 0;
                f(left, right) = f(left, right - 1) + 1;
                while (curv >= left) {
                    int lp = (curv-1>=left)? f(left, curv - 1):0;
                    f(left, right) = std::min(f(left, right), lp + f(curv, right - 1));

                    int nextCur = prev[curv];
                    if (nextCur < left)break;
                    curv = nextCur;
                }

            }
        }
        return f(0, n - 1);
    }
};

int main() {
    Solution s;
    while (true) {
        string x;
        cin >> x;
        cout << s.strangePrinter(x) << endl;
    }
    return 0;
}