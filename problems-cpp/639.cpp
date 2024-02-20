#include <iostream>
#include <string>
using namespace std;

class Solution {
public:
    int numDecodings(string s) {
        int n = s.size();
        int* vf = new int[n + 1];
        auto f = [&](int x)->int& {
            return vf[x + 1];
        };
        constexpr static const int modf = 1000000007;
        memset(vf, 0, sizeof(int) * (n + 1));
        f(-1) = 1;

        for (int i = 0; i < n; i++) {
            // Use one digit
            if (s[i] == '*') {
                f(i) += (f(i - 1) * 9ll) % modf;
                f(i) %= modf;
            }
            else if (s[i] >= '1' && s[i] <= '9') {
                f(i) += f(i - 1);
                f(i) %= modf;
            }

            // Use two digits
            if (i == 0)continue;
            if (s[i - 1] == '0'|| s[i - 1] >= '3')continue;
            if (s[i - 1] == '2' && (s[i] <= '6' && s[i] >= '0')) {
                f(i) += f(i - 2);
                f(i) %= modf;
            }
            else if (s[i - 1] == '2' && s[i]=='*') {
                f(i) += (f(i - 2) * 6ll) % modf;
                f(i) %= modf;
            }
            else if (s[i - 1] == '1' && s[i] == '*') {
                f(i) += (f(i - 2) * 9ll) % modf;
                f(i) %= modf;
            }
            else if (s[i - 1] == '1' && (s[i] >= '0' && s[i] <= '9')) {
                f(i) += f(i - 2);
                f(i) %= modf;
            }
            else if (s[i - 1] == '*') {
                if (s[i] == '*') {
                    f(i) += (f(i - 2) * 15ll) % modf;
                    f(i) %= modf;
                }
                else if (s[i] > '6') {
                    f(i) += f(i - 2);
                    f(i) %= modf;
                }
                else {
                    f(i) += (f(i - 2) * 2ll) % modf;
                    f(i) %= modf;
                }
            }
        }
        return f(n - 1);
    }
};

int main() {
    Solution s;
    while (true) {
        string x;
        cin >> x;
        cout << s.numDecodings(x) << endl;
    }
    return 0;
}