#include <vector>
#include <iostream>
#include <unordered_map>
using namespace std;
class Solution {
public:
    int tallestBillboard(vector<int>& rods) {
        int n = rods.size();
        vector<unordered_map<int, int>> f(20);
        int sum = 0;
        for (int i = 0; i < n; i++) {
            sum += rods[i];
        }
        sum /= 2;
        f[0][0] = 0;
        f[0][rods[0]] = rods[0];
        for (int i = 1; i < n; i++) {
            for (const auto& p : f[i - 1]) {
                int k = p.first;
                f[i][k] = std::max(f[i - 1][k], f[i][k]); //Ignore
                if (k + rods[i] <= sum) {
                    f[i][k + rods[i]] = std::max(f[i - 1][k] + rods[i], f[i][k + rods[i]]); //Add
                }
                if (k - rods[i] >= -sum) {
                    f[i][k - rods[i]] = std::max(f[i][k - rods[i]], f[i - 1][k]);//Reduce
                }
            }
        }
        return f[n - 1][0];
    }
};
int main() {
    Solution s;
    vector<int> a = { 3,4,3,3,2 };
    cout << s.tallestBillboard(a) << endl;
    return 0;
}