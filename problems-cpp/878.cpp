#include <iostream>
#include <set>
#include <algorithm>
#include <vector>
using namespace std;

class Solution {
public:
    inline int getLcm(int a, int b) {
        int p = a, q = b;
        for (int t = a; b; t = a, a = b, b = t % b);
        return p * q / a;
    }
    int compareAlgo(int n, int a, int b) {
        set<int> p;
        for (int i = 0; i < n + 12; i++) {
            p.insert(i * a);
            p.insert(i * b);
        }
        vector<int> s;
        for (auto x : p) {
            s.push_back(x);
        }
        std::sort(s.begin(), s.end());
        return s[n];
    }
    int nthMagicalNumber(int n, int a, int b) {
        constexpr static int modf = 1000000007;
        int lcm = getLcm(a, b), l = 0, r = 0, mid = 0, midv = 0;
        int fa = lcm / a, fb = lcm / b;
        int period = fa + fb - 1;
        int fct = n / period, rem = n % period;
        int remsol = -1, remp[] = { a,b };
        if (rem != 0) {
            for (int i = 0; i < 2; i++) {
                l = 0; r = rem;
                while (l <= r) {
                    mid = (l + r) / 2;
                    int tmp = remp[i] * mid;
                    midv = (tmp) / a + (tmp) / b - (tmp) / lcm;
                    if (midv < rem) {
                        l = mid + 1;
                    }
                    else if (midv > rem) {
                        r = mid - 1;
                    }
                    else {
                        remsol = tmp;
                        break;
                    }
                }
                if (remsol != -1)break;
            }
        }
        else {
            remsol = 0;
        }
        return static_cast<int>(((long long)(fct) * (long long)(lcm) % modf + remsol) % modf);
    }
};

int main() {
    int n, a, b;
    Solution x;
    cin >> n >> a >> b;
    cout << "Ans:" << x.nthMagicalNumber(n, a, b) << endl;
    cout << "Std:" << x.compareAlgo(n, a, b) << endl;
    return 0;
}