#include <iostream>
#include <cstring>
using Grid = int[3][3][3];
using Rule = int[3][2];

class Solution {
public:
    int numOfWays(int n) {
        Grid* f = new Grid[2];
        Rule r = { {1,2},{0,2},{0,1} };
        constexpr static int modf = 1000000000 + 7;
        memset(f, 0, sizeof(Grid) * 2);
        for (int a = 0; a < 3; a++) {
            for (int b = 0; b < 3; b++) {
                for (int c = 0; c < 3; c++) {
                    if (a == b || b == c) {
                        f[1][a][b][c] = 0;
                    }
                    else {
                        f[1][a][b][c] = 1;
                    }
                }
            }
        }
        for (int i = 2; i <= n; i++) {
            int p = i % 2;
            for (int a1 = 0; a1 < 3; a1++) {
                for (int b1 = 0; b1 < 3; b1++) {
                    for (int c1 = 0; c1 < 3; c1++) {
                        f[p][a1][b1][c1] = 0;
                        if (a1 == b1 || b1 == c1) {
                            continue;
                        }
                        else {
                            for (auto a2 : r[a1]) {
                                for (auto b2 : r[b1]) {
                                    for (auto c2 : r[c1]) {
                                        if (a2 == b2 || b2 == c2)continue;
                                        f[p][a1][b1][c1] += f[1 - p][a2][b2][c2];
                                        f[p][a1][b1][c1] %= modf;
                                    }
                                }
                            }
                        }
                    }
                }
            }
        }
        int ans = 0;
        for (int i = 0; i < 3; i++) {
            for (int j = 0; j < 3; j++) {
                for (int k = 0; k < 3; k++) {
                    ans += f[n % 2][i][j][k];
                    ans %= modf;
                }
            }
        }
        return ans;
    }
};

int main() {
    Solution s;
    while (true) {
        int a;
        std::cin >> a;
        std::cout << s.numOfWays(a) << std::endl;
    }
    return 0;
}