#include <cmath>
#include <iostream>
class Solution {
public:
    int twoEggDrop(int n) {
        int l = 1, r = std::sqrt(3 * n);
        while (l < r) {
            int mid = (l + r ) >> 1;
            int midv = mid * (mid + 1) / 2;
            if (midv < n) {
                l = mid + 1;
            }
            else {
                r = mid;
            }
        }
        return r;
    }
};

int main() {
    Solution s;
    while (true) {
        using namespace std;
        int x;
        cin >> x;
        cout << s.twoEggDrop(x) << endl;
    }
}