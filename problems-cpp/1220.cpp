#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    enum Vowel {
        A,E,I,O,U
    };
    int countVowelPermutation(int n) {
        vector<vector<int>> p = {
            {E},
            {A,I},
            {A,E,O,U},
            {I,U},
            {A}
        };
        int f[2][5];
        for (int i = 0; i < 5; i++) {
            f[1][i] = 1;
        }
        for (int i =2; i <=n ; i++) {
            for (int j = 0; j < 5; j++) {
                f[i % 2][j] = 0;
                for (auto k : p[j]) {
                    f[i % 2][j] += f[(i + 1) % 2][k];
                    f[i % 2][j] %= 1000000007;
                }
            }
        }
        int ans = 0;
        for (int i = 0; i < 5; i++) {
            ans += f[n % 2][i];
            ans %= 1000000007;
        }
        return ans;
    }
};

int main() {
    Solution s;
    while (true) {
        int v;
        cin >> v;
        cout << s.countVowelPermutation(v) << endl;
    }
    return 0;
}