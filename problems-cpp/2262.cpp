#include <string>
#include <iostream>
#include <cstring>
using namespace std;
class Solution {
public:
    long long appealSum(string s) {
        long long prev[26], consec = 0;
        memset(prev, 0xff, sizeof(prev));
        long long ans = 0;
        for (int i = 0; i < s.size(); i++) {
            int idx = s[i] - 'a';
            consec += i - prev[idx];
            prev[idx] = i;
            ans += consec;
        }
        return ans;
    }
};

int main() {
    Solution s;
    while (true) {
        string v;
        cin >> v;
        cout << s.appealSum(v) << endl;
    }
    return 0;
}