#include <iostream>
#include <vector>
using namespace std;
class Solution {
public:
    int firstDayBeenInAllRooms(vector<int>& nextVisit) {
        int n = nextVisit.size();
        vector<int> first(n);
        vector<int> second(n);
        first[0] = 0;
        second[0] = 1;
        const int mod = 1000000007;
        for (int i = 1; i < n; i++) {
            first[i] = second[i - 1] + 1;
            first[i] = (first[i]) % mod;
            if (nextVisit[i] == i) {
                second[i] = first[i] + 1;
                second[i] %= mod;
            }
            else {
                second[i] = first[i] + second[i - 1] + 2 - first[nextVisit[i]];
                second[i] %= mod;
                second[i] = (second[i] + mod) % mod;
            }
        }
        return first[n - 1];
    }
};

int main() {
    vector<int> a = { 0 };
    Solution s;
    cout << s.firstDayBeenInAllRooms(a) << endl;
    return 0;
}