#include <string>
#include <iostream>
using namespace std;
class Solution {
public:
    string subStrHash(string s, int power, int modulo, int k, int hashValue) {
        long long curHash = 0;
        long long highestBase = 1;
        int n = s.size();
        int cur = s.size();
        int ansp = 0;
        //Init
        for (int i = 0; i < k; i++) {
            cur--;
            curHash = curHash * power + (s[cur] - 'a' + 1);
            curHash %= modulo;
            if (i != 0) {
                highestBase *= power;
                highestBase %= modulo;
            }
        }
        if (curHash == hashValue) {
            ansp = cur;
        }
        //Trans
        while (cur != 0) {
            cur--;
            curHash = curHash - highestBase * (s[cur + k] - 'a' + 1);
            curHash %= modulo;
            curHash = (curHash + modulo) % modulo;
            curHash = curHash * power + (s[cur] - 'a' + 1);
            curHash %= modulo;
            if (curHash == hashValue) {
                ansp = cur;
            }
        }
        return s.substr(ansp, k);
    }
};

int main() {
    Solution s;
    cout << (-15) % 7 << endl;
    cout << s.subStrHash("leetcode", 7, 20, 2, 0);
    return 0;
}