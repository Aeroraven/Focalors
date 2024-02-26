#include <string>
#include <iostream>
using namespace std;

class Solution {
public:
    int minimumDistance(string word) {
        const int MAXV = 100000;
        int n = word.size();
        using Rec = int[27][27];
        Rec* vf = new Rec[n+1];
#define f(p,x,y) (vf[(p+1)][(x)][(y)])
#define col(c) ((c-'A')%6)
#define row(c) ((c-'A')/6)

        for (int i = 0; i < 27; i++) {
            for (int j = 0; j < 27; j++) {
                f(-1, i, j) = MAXV;
            }
        }
        f(-1, 0, 0) = 0;
        for (int k = 0; k < n; k++) {
            //Update f(k,word[k],p) or f(k,q,word[k])
            for (int i = 0; i < 27; i++) {
                for (int j = 0; j < 27; j++) {
                    f(k, i, j) = MAXV;
                }
            }
            for (int i = 0; i < 27; i++) {
                f(k, word[k] - 'A' + 1, i) = MAXV;
                f(k, i, word[k] - 'A' + 1) = MAXV;
                int curx = row(word[k]);
                int cury = col(word[k]);
                for (int j = 0; j < 27; j++) {
                    int cost = 0;
                    if (j != 0) {
                        int lastx = row(j - 1 + 'A');
                        int lasty = col(j - 1 + 'A');
                        cost = abs(curx - lastx) + abs(cury - lasty);
                    }
                    f(k, word[k] - 'A' + 1, i) = std::min(f(k, word[k] - 'A' + 1, i), f(k - 1, j, i) + cost);
                    f(k, i, word[k] - 'A' + 1) = std::min(f(k, i, word[k] - 'A' + 1), f(k - 1, i, j) + cost);
                }
            }
        }
        int ans = MAXV;
        for (int i = 0; i < 27; i++) {
            for (int j = 0; j < 27; j++) {
                ans = std::min(f(n - 1, i, j), ans);
            }
        }
        return ans;
    }
};
int main() {
    Solution s;
    while (true) {
        string w;
        cin >> w;
        cout << s.minimumDistance(w) << endl;
    }
    return 0;
}