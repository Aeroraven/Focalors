#include <vector>
#include <cstring>
#include <iostream>

class Solution {
public:
    
    int minSwapsCouples(std::vector<int>& row) {
        int n = row.size();
        int nh = n / 2;
        int* f = new int[nh];
        int* pos = new int[n];
        for (int i = 0; i < nh; i++)f[i] = i;
        auto setFind = [&](int a) {
            while (a != f[a]) {
                a = f[a];
            }
            return a;
        };
        for (int i = 0; i < n; i++) {
            pos[row[i]] = i;
        }
        for (int i = 0; i < n; i++) {
            if (row[i] & 1) {
                int cur = i / 2;
                int dest = pos[row[i] - 1] / 2;
                int fcur = setFind(cur);
                int fdest = setFind(dest);
                f[fcur] = fdest;
            }
        }
        int ansx = nh;
        for (int i = 0; i < nh ; i++) {
            if (f[i] == i) {
                ansx--;
            }
        }
        return ansx;
    }
};

int main() {
    Solution s;
    std::vector<int> a = { 3,2,0,1 }; //10-> 5
    std::cout << s.minSwapsCouples(a) << std::endl;
    return 0;
}