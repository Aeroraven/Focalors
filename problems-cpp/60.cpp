#include <vector>
#include <string>
#include <iostream>
using namespace std;

class Solution {
public:
    string getPermutation(int n, int k) {
        k -= 1;
        int* fact = new int[n + 1];
        int* ord = new int[n + 1];
        fact[0] = 1;
        for (int i = 1; i <= n; i++) fact[i] = fact[i - 1] * i;
        int rem = k;
        for (int i = n; i >= 1; i--) {
            ord[i] = rem / fact[i - 1];
            rem %= fact[i - 1];
        }
        vector<int> bsperm = {};
        string ans = "";
        for (int i = 1; i <= n; i++) bsperm.push_back(i);
        for (int i = n; i >= 1; i--) {
            ans += (bsperm[ord[i]] + '0');
            bsperm.erase(bsperm.begin() + ord[i]);
        }
        delete[] fact;
        delete[] ord;
        return ans;
    }
};

int main() {
    Solution sol;
    int n, k;
    cin >> n >> k;
    cout << sol.getPermutation(n, k) << endl;
    return 0;
}