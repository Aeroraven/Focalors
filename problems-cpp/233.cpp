#include <iostream>
#include <cstring>
using namespace std;



int getSolution(int n) {
    int exp10[10];
    exp10[0] = 1;
    for (int i = 1; i <= 9; i++) {
        exp10[i] = exp10[i - 1] * 10;
    }
    int p[10][10];
    int v[10][10];
    for (int i = 0; i <= 9; i++) {
        p[0][i] = (i >= 1);
        v[0][i] = (i >= 1);
    }
    for (int i = 1; i <= 8; i++) {
        for (int j = 0; j <= 9; j++) {
            if (j == 1) {
                p[i][j] = p[i][j - 1] + (exp10[i]) + p[i - 1][9];
            }
            else if (j == 0) {
                p[i][j] = p[i - 1][9];
            }
            else {
                p[i][j] = p[i][j - 1] + p[i - 1][9];
            }
        }
        v[i][0] = 0;
        for (int j = 1; j <= 9; j++) {
            v[i][j] = p[i][j - 1];
            if (j == 1) {
                v[i][j] += 1;
            }
        }
    }
    p[9][0] = p[8][9];
    v[9][0] = 0;
    v[9][1] = p[9][0] + 1;

    int t = n;
    int digit[10];
    int mod[10];
    for (int i = 0; i <= 9; i++) {
        digit[i] = t % 10;
        mod[i] = n % exp10[i];
        t /= 10;
    }

    int res = 0;
    for (int i = 9; i >= 0; i--) {
        res += v[i][digit[i]];
        if (digit[i] == 1 && i > 0) {
            res += mod[i];
        }
    }
    return res;
}
int reference(int n) {
    auto countx = [](int s) {
        int r = 0;
        while (s) {
            r += (s % 10 == 1);
            s /= 10;
        }
        return r;
        };
    int rx = 0;
    for (int i = 0; i <= n; i++) {
        rx += countx(i);
    }
    return rx;
}


int main() {
    int n;
    cin >> n;
    cout << getSolution(n) << endl;
    cout << reference(n) << endl;
    return 0;
}