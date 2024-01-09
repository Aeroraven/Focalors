#include <vector>
#include <cstring>
#include <iostream>

class Solution {
public:
    int singleNumber(std::vector<int>& nums) {
        std::vector<unsigned int> pw;
        unsigned int base = 1;
        for (int i = 0; i <= 20; i++) {
            pw.push_back(base);
            if(i!=20)base *= 3;
        }
        std::reverse(pw.begin(), pw.end());

        int p[21];
        memset(p, 0, sizeof(p));
        for (auto& x : nums) {
            unsigned int v = (unsigned int)(x);
            for (int i = 0; i <= 20; i++) {
                p[i] += v / pw[i];
                v %= pw[i];
            }
        }

        unsigned int ansx = 0;
        for (int i = 0; i <= 20; i++) {
            ansx += pw[i] * (p[i] % 3);
        }
        return (int)(ansx);
    }
};

int main() {
    Solution s;
    std::vector<int> a = { -1,-1,-1,-2,-2,-2,-3,-3,-3,-4,-4,-4,-5,-5,-5,-99,6,6,6,7,7,7 };
    std::cout << s.singleNumber(a);
    return 0;
}