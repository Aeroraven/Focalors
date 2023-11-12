#include <iostream>
using namespace std;

class Solution {
public:
    string minWindow(string s, string t) {
        // Assume the answer is s[l,r]
        int l = 0, r = -1;
        int bestL = 0, bestR = 0;
        int sL = static_cast<int>(s.size());
        int tL = static_cast<int>(t.size());
        int countReq[256], countCur[256];
        memset(countReq, 0, sizeof(countReq));
        memset(countCur, 0, sizeof(countCur));

        // Initialize the requirement using string T
        for (int i = 0; i < tL; i++) {
            countReq[t[i]] += 1;
        }

        int satisfiedConds = 0;
        for (int i = 0; i < 256; i++) {
            if (countReq[i] == 0) {
                satisfiedConds += 1;
            }
        }
        // Initialize the sliding window with a valid (but not optimal) answer
        while (satisfiedConds < 256 ) {
            r += 1;
            if (r >= sL)break;
            if (countCur[s[r]] == countReq[s[r]] - 1) {
                satisfiedConds += 1;
            }
            countCur[s[r]] += 1;

            // Narrow left bound
            while (countCur[s[l]] > countReq[s[l]]) {
                countCur[s[l]]--;
                l++;
            }
        }
        bestL = l;
        bestR = r;

        // If the initial answer cannot be found
        if (satisfiedConds != 256) {
            return "";
        }

        // Use the sliding window to get the optimal answer
        while (true) {
            // Insert next character
            r += 1;
            if (r >= sL)break;
            countCur[s[r]]++;
            
            // Pop the left character if able
            while (countCur[s[l]] > countReq[s[l]]) {
                countCur[s[l]]--;
                l++;
            }
            //cout << "l=" << l << ", r=" << r << " Lv=" << countCur[s[l]]<< endl;
            // Update the result if the better answer is found
            if (r - l < bestR - bestL) {
                bestR = r;
                bestL = l;
            }
        }

        // Return the substring
        return s.substr(bestL, bestR - bestL + 1);
    }
};


int main() {
    string s, t;
    Solution sol;
    while (true) {
        cin >> s >> t;
        cout << sol.minWindow(s, t) << endl;
    }
	return 0;
}