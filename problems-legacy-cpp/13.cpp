class Solution {
public:
    int romanToInt(string s) {
        if (s == "")return 0;
        int sz = s.size();
        int ans = 0;
        int tans = 0;
        for (int i = 0; i < sz; i++) {
            if (s[i] == 'I') {
                if (i + 1 < sz && (s[i + 1] == 'X')) {
                    tans = 9;
                    i++;
                }
                else if (i + 1 < sz && (s[i + 1] == 'V')) {
                    tans = 4;
                    i++;
                }
                else {
                    tans = 1;
                }
            }
            else if (s[i] == 'X') {
                if (i + 1 < sz && (s[i + 1] == 'L')) {
                    tans = 40;
                    i++;
                }
                else if (i + 1 < sz && (s[i + 1] == 'C')) {
                    tans = 90;
                    i++;
                }
                else {
                    tans = 10;
                }
            }
            else if (s[i] == 'C') {
                if (i + 1 < sz && (s[i + 1] == 'D')) {
                    tans = 400;
                    i++;
                }
                else if (i + 1 < sz && (s[i + 1] == 'M')) {
                    tans = 900;
                    i++;
                }
                else {
                    tans = 100;
                }
            }
            else if (s[i] == 'V') {
                tans = 5;
            }
            else if (s[i] == 'L') {
                tans = 50;
            }
            else if (s[i] == 'D') {
                tans = 500;
            }
            else if (s[i] == 'M') {
                tans = 1000;
            }
            ans += tans;
        }
        return ans;
    }
};