#include <iostream>
#include <string>
using namespace std;

class Solution {
public:
    bool isScramble(string a, string b) {
        // Let f[i,j,k] denote substring a[i...(i+k-1)] and b[j...(j+k-1)] is a pair of scrambled string.
        // The state f[i,j,k] is subject to
        // I, f[i,j,1] = (a[i]==b[j])
        // II-a. f[i,j,k] |= f[i,j,p] & f[i+p,j+p,k-p] (Without scrambling operation)
        // II-b. f[i,j,k] |= f[i,j+k-p,p] & f[i+p,j,k-p] (With scrambling operation)
        //
        // Then the final answer will be f[0,0,length]. This algorithm takes O(n^4) time.


        int sL = static_cast<int>(a.length());
        bool* vf = new bool[sL * sL * (sL + 1)];
        auto f = [sL, &vf](int i, int j, int k)->bool* {
            return &vf[i * (sL * (sL + 1)) + j * (sL + 1) + k];
        };

        // Initialize using (I)
        for (int i = 0; i < sL; i++) {
            for (int j = 0; j < sL; j++) {
                if (a[i] == b[j]) {
                    *f(i, j, 1) = true;
                }
                else {
                    *f(i, j, 1) = false;
                }
            }
        }

        // Update State using (II)
        for (int k = 2; k <= sL; k++) {
            for (int i = 0; i < sL + 1 - k; i++) {
                for (int j = 0; j < sL + 1 - k; j++) {
                    *f(i, j, k) = false;
                    for (int p = 1; p < k; p++) {
                        *f(i, j, k) |= (*f(i, j, p) & *f(i + p, j + p, k - p));
                        *f(i, j, k) |= (*f(i, j + k - p, p) & *f(i + p, j, k - p));
                    }
                    if (*f(i, j, k)) {
                        continue;
                    }
                }
            }
        }

        return *f(0, 0, sL);

    }
};

int main() {
    Solution s;
    while (true) {
        string a, b;
        cin >> a >> b;
        cout << boolalpha << s.isScramble(a, b) << endl;
    }
	return 0;
}