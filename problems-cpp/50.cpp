#include <iostream>
using namespace std;


class Solution {
public:
    double myPow(double x, int n) {
        bool neg = (n < 0);
        long long n2 = n;
        if (neg)n2 = -n2;
        // x^n = x^sum(a[k]*2^k)

        long long p = n2;
        double b = x;
        double ret = 1.0;
        while (p) {
            if (p & 1) {
                ret *= b;
            }
            p >>= 1;
            b *= b;
            if (p < 0) {
                throw;
            }
        }
        if (neg)return 1.0 / ret;
        return ret;
    }
};

int main() {
    Solution x;
    while (true) {
        double a;
        int b;
        cin >> a >> b;
        cout << x.myPow(a, b) << endl;
    }

    return 0;
}