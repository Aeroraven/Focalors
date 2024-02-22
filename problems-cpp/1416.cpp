#include <iostream>
#include <string>
#include <cstring>
using namespace std;

#define f(x) vf[(x)+1]

class Solution {
public:
    int numberOfArrays(string s, int k) {
        int n = s.size();
        int* vf = new int[n + 1];
        constexpr static const int modf = 1000000007;
        memset(vf, 0, sizeof(int) * (n + 1));
        f(-1) = 1;
        for (int i = 0; i < n; i++) {
            long long accu = 0;
            long long base = 1;
            for (int j = 1;j<=11; j++) {
                accu += base* (s[i - j + 1] - '0');
                base *= 10;
                if (accu > k) break;
                if (accu == 0 || s[i - j + 1] == '0')continue;
                f(i) += f(i - j);
                f(i) %= modf;

                if (i - j == -1)break;
            }
        }
        return f(n - 1);
    }
};
int main() {
    Solution s;
    cout << s.numberOfArrays("1234567890", 90) << endl;
    return 0;
}