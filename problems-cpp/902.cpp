#include <iostream>
#include <string>
#include <vector>
using namespace std;

class Solution {
public:
    int atMostNGivenDigitSet(vector<string>& digits, int n) {
        int lower[10] = {};
        int equ[10] = {};
        int m = digits.size();
        for (int i = 0, j = 0; i <= 9; i++) {
            while (j<m && i>digits[j][0]-'0') {
                j++;
            }
            lower[i] = j;
        }
        for (int i = 0; i < m; i++) {
            equ[digits[i][0] - '0'] = 1;
        }
        vector<int> dx;
        int n2 = n;
        int ans = 1;
        while (n2) {
            dx.push_back(n2 % 10);
            if (!equ[n2 % 10])ans = 0;
            n2 /= 10;
        }

        vector<int> base = { 1 };
        for (int i = 1; i <= dx.size(); i++) {
            base.push_back(base[i - 1] * m);
            if (i != dx.size() ) {
                ans += base.back();
            }
        }
        for (int i = dx.size() - 1; i >= 0; i--) {
            int curDigit = dx[i];
            ans += lower[curDigit] * base[i];
            if (!equ[curDigit])break;
        }

        return ans;
    }
};

int main() {
    Solution s;
    vector<string> x = { "5","6"};
    cout << s.atMostNGivenDigitSet(x, 19);
    return 0;
}