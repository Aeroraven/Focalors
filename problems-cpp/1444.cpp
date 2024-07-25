#include <iostream>
#include <vector>
#include <string>
using namespace std;

class Solution {
public:
    int ways(vector<string>& pizza, int k) {
        int rows = pizza.size();
        int cols = pizza[0].size();
        int* fsum = new int[rows * cols];
        int* vf = new int[rows * cols * k];
#define s(x,y) fsum[(x)*cols+(y)]
#define f(x,y,z) vf[((x)*cols+(y))*k+(z)]
#define p(x,y) pizza[rows-1-(x)][cols-1-(y)]
#define modn 1000000007
        s(0, 0) = (p(0,0) == 'A');
        for (int i = 1; i < cols; i++) {
            s(0, i) = s(0, i - 1) + (p(0,i) == 'A');
        }
        for (int i = 1; i < rows; i++) {
            s(i, 0) = s(i - 1, 0) + (p(i, 0) == 'A');
        }
        for (int i = 1; i < rows; i++) {
            for (int j = 1; j < cols; j++) {
                s(i, j) = s(i - 1, j) + s(i, j - 1) - s(i - 1, j - 1) + (p(i,j) == 'A');
            }
        }
        //Slice
        for (int i = 0; i < rows; i++) {
            for (int j = 0; j < cols; j++) {
                if (s(i, j) > 0) {
                    f(i, j, 0) = 1;
                }
                else {
                    f(i, j, 0) = 0;
                }
            }
        }
        for (int d = 1; d < k; d++) {
            for (int i = 0; i < rows; i++) {
                for (int j = 0; j < cols; j++) {
                    f(i, j, d) = 0;
                    // Horz
                    for (int v = 1; v <= i; v++) {
                        auto out = s(i, j) - s(v - 1, j);
                        if (out > 0) {
                            f(i, j, d) += f(v - 1, j, d - 1);
                            f(i, j, d) %= modn;
                        }

                    }
                    // Vert
                    for (int v = 1; v <= j; v++) {
                        auto out = s(i, j) - s(i, v - 1);
                        if (out > 0) {
                            f(i, j, d) += f(i, v - 1, d - 1);
                            f(i, j, d) %= modn;
                        }
                    }
                }
            }
        }
        return f(rows - 1, cols - 1, k - 1);
    }
};

int main() {
    vector<string> a = { "AAAAA","AAAAA","AAAAA","AAAAA","AAAAA" };
    Solution s;
    cout << s.ways(a, 3) << endl;
    return 0;
}