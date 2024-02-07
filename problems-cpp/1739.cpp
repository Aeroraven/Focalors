#include <iostream>
#define CALC3(n) static_cast<int>(((long long)n * (n + 1) * (n + 2)) / 6)
#define CALC2(n) (n*(n+1)/2)

class Solution {
public:
    int minimumBoxes(int n) {
        int l = 1, r = 1800;
        int ans = 0;
        while (l < r) {
            int mid = (l + r + 1) >> 1;
            int midv = CALC3(mid);
            if (midv > n) {
                r = mid - 1;
            }
            else {
                l = mid;
                if (midv == n)break;
            }
        }
        int base = CALC2(l);
        int rem = n - CALC3(l);
        r = l + 1; l = 0;
        while (l < r) {
            int mid = (l + r) >> 1;
            int midv = CALC2(mid);
            if (midv < rem) {
                l = mid + 1;
            }
            else {
                r = mid;
                if (midv == rem)break;
            }

        }
        ans = base + r;
        return ans;
    }
};

int main() {
    using namespace std;

    Solution s;
    while (true) {
        int a;
        std::cin >> a;
        std::cout << s.minimumBoxes(a) << std::endl;
    }
    return 0;
}