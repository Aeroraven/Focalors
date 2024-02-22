#include <string>
#include <iostream>
using namespace std;

class Solution {
public:
    string longestPrefix(string s) {
        int n = s.size();
        int* f = new int[n];
        f[0] = 0;
        for (int i = 0; i < n - 1; i++) {
            int j = f[i];
            while (j > 0 && s[j] != s[i + 1]) {
                j = f[j - 1];
            }
            if (s[j] == s[i + 1]) {
                j++;
            }
            f[i + 1] = j;
        }
        cout << f[n - 1] << endl;
        return s.substr(0, f[n - 1]);
    }
};

int main() {
    Solution s;
    while (true) {
        string x;
        cin >> x;
        cout << s.longestPrefix(x) << endl;
    }
    return 0;
}