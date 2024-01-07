#include <iostream>
#include <string>
#include <cstring>
using namespace std;

class Solution {
public:
    bool isInterleave(string s1, string s2, string s3) {
        // F[i][j] denotes Substring S3[0...i+j] can be constructed using S1[0...i] and S2[0...j]
        // F[i][j] = (F[i-1][j] & S1[i]) || (F[i][j-1] & S2[j])

        int m1 = s1.length(), m2 = s2.length(), m3 = s3.length();
        if (m1 + m2 != m3)return false;

        bool* vf = new bool[2 * (m2 + 1)];
        memset(vf, 0, sizeof(bool) * 2 * (m2 + 1));
        auto f = [&vf, &m2](int x,int y) -> bool& {
            return vf[(m2 + 1) * ((x + 1) & 1) + (y + 1)];
        };
        f(-1, -1) = true;
        for (auto i = 0; i < m2; i++) {
            if (s3[i] == s2[i]) {
                f(-1, i) = true;
                continue;
            }
            break;
        }
        for (auto i = 0; i < m1; i++) {
            f(i, -1) = f(i-1, -1) && (s1[i] == s3[i]);
            for (auto j = 0; j < m2; j++) {
                f(i, j) = (f(i - 1, j) && (s1[i] == s3[i + j + 1])) || (f(i, j - 1) && (s2[j] == s3[i + j + 1]));
            }

        }
        return f(m1 - 1, m2 - 1);
    }
};


int main() {
    Solution s;
    string a, b, c;
    cin >> a >> b >> c;
    cout << boolalpha << s.isInterleave(a, b, c) << endl;
}