#include <cstring>
#include <iostream>

class Solution {
public:
    bool DivisorGameOld(int n) {
        bool* f = new bool[n+1];
        memset(f, 0, sizeof(bool) * (n+1));
        
        for (int i = 1; i <= n; i++) {
            f[i] = true;
            for (int j = 1;j<i; j++) {
                if (j * j > i)break;
                if (i % j == 0) {
                    if (f[i-j]) {
                        f[i] = false;
                        break;
                    }
                }
            }
        }
        return !f[n];
    }
    bool DivisorGame(int n) {
        return !(n % 2);
    }
};

int main() {
    using namespace std;
    Solution s;
    int w = 0;
    while (true) {
        int a;
        w++;
        if (s.DivisorGame(w) != s.DivisorGameOld(w)) {
            throw;
        }
        else {
            std::cout << "Pass:" << w << endl;
        }
    }
    return 0;
}