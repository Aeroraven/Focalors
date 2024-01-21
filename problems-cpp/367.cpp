#include <algorithm>
#include <iostream>
class Solution {
public:
    bool isPerfectSquare(int num) {
        int l = 1, r = std::min(num, 46340);
        while (l <= r) {
            int mid = (l + r) >> 1;
            int prod = mid * mid;
            if (prod > num) {
                r = mid - 1;
            }
            else if (prod < num) {
                l = mid + 1;
            }
            else {
                return true;
            }
        }
        return false;
    }
};

int main() {
    using namespace std;

    while (true) {
        int w;
        cin >> w;
        Solution s;
        cout << s.isPerfectSquare(w) << endl;
    }
    return 0;
}