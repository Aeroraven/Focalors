#include <iostream>
using namespace std;

//TODO: Can still be optimized

class Solution {
public:
    bool isMatch(string s, string p) {
        int sL = static_cast<int>(s.size());
        int pL = static_cast<int>(p.size());

        unique_ptr<bool[]> vf(new bool[(sL + 1) * (pL + 1)]());
        auto f = [&](int ls, int lp)->bool& {
            return vf.get()[ls * (pL + 1) + lp];
        };

        memset(vf.get(), 0, sizeof(bool) * (sL + 1) * (pL + 1));
        f(0, 0) = true;

        // f(i,j) means "able to match substring s[:i], using given pattern p[:j]"
        
        // Initialize (asterisk wildcard)
        for (int i = 0; i < pL; i++) {
            if (p[i] == '*') {
                f(0, i + 1) = true;
            }
            else {
                break;
            }
        }

        // Solve
        for (int i = 1; i <= sL; i++) {
            for (int j = 1; j <= pL; j++) {
                if (p[j - 1] == '*') {
                    //* wildcard
                    for (int k = 0; k <= i; k++) {
                        f(i, j) = f(i, j) || f(k, j - 1);
                    }
                }
                else if (p[j - 1] == '?') {
                    //? wildcard
                    f(i, j) = f(i, j) || f(i - 1, j - 1);
                }
                else {
                    //single character
                    if (p[j - 1] == s[i - 1]) {
                        f(i, j) = f(i, j) || f(i - 1, j - 1);
                    }
                }
            }
        }
        return f(sL, pL);

    }
};

int main() {
    Solution sol;
    string s, p;
    while (true) {
        cin >> s >> p;
        cout << boolalpha << sol.isMatch(s, p) << endl;
    }
	return 0;
}