#include <iostream>
#include <string>
#include <vector>
using namespace std;

class Solution {
public:
    int vN, vK;
    int* visState = nullptr;
    int* base = nullptr;
    int modf = 0;
    vector<char> ans;
    void dfs(int state) {
        int bf = (state * vK) % modf;
        for (int i = 0; i < vK; i++) {
            int nextState = bf + i;
            if (visState[nextState])continue;
            visState[nextState] = true;
            dfs(nextState);
            ans.push_back((char)((nextState % vK)+'0'));
        }
    }

    string crackSafe(int n, int k) {
        vN = n, vK = k;
        int maxState = 0;
        base = new int[n];
        for (int i = 0; i < n; i++) {
            maxState = maxState * k + (k - 1);
            if (i == 0) {
                base[i] = 1;
            }
            else {
                base[i] = base[i - 1] * k;
            }
        }
        modf = base[n - 1] * k;
        visState = new int[maxState + 1];
        memset(visState, 0, sizeof(int) * (maxState + 1));

        dfs(0);
        for (int i = 0; i < n - 1; i++) {
            ans.push_back('0');
        }
        string ret(ans.begin(), ans.end());
        return ret;
    }
};

int main() {
    
    while (true) {
        Solution s;
        int n, k;
        cin >> n >> k;
        cout << s.crackSafe(n, k) << endl;
    }
    return 0;
}