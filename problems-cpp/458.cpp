#include <cmath>
#include <iostream>
using namespace std;

// So hard TAT
class Solution {
public:
    int poorPigs(int buckets, int minutesToDie, int minutesToTest) {
        int t = minutesToTest / minutesToDie;
        //k*log2(t+1)>log2(bucket)
        //(t+1)^k>bucket
        double w = std::log2(1.0*buckets) / std::log2(1.0*t + 1.0);
        double r = std::floor(w);
        if (w - r > 1e-6) {
            return r + 1;
        }
        else {
            return r;
        }
    }
};

int main() {
    Solution s;
    while (true) {
        int n, t;
        cin >> n >> t;
        cout << s.poorPigs(n, 1, t) << endl;
    }
}