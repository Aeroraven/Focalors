#include <string>
#include <iostream>
#include <cstring>
using namespace std;

class Solution {
public:
    int uniqueLetterString(string s) {
        int n = s.size();
        int lsChar[26];
        int prChar[26];
        int consec = 0;
        int ans = 0;
        memset(lsChar, -1, sizeof(lsChar));
        memset(prChar, -1, sizeof(prChar));
        for (int i = 0; i < n; i++) {
            consec -= (prChar[s[i] - 'A'] - lsChar[s[i] - 'A']);
            lsChar[s[i] - 'A'] = prChar[s[i] - 'A'];
            prChar[s[i] - 'A'] = i;
            consec += (prChar[s[i] - 'A'] - lsChar[s[i] - 'A']);
            ans += consec;
        }
        return ans;
    }
};

int main() {
    Solution s;
    cout << s.uniqueLetterString("ABC");
    return 0;
}