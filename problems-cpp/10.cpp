#include <iostream>
#include <memory>
#include <vector>
using namespace std;

class Solution {
public:
    bool isMatch(string s, string p) {
        int sL = static_cast<int>(s.size());
        int pL = static_cast<int>(p.size());

        vector<char> pattern;
        vector<bool> asterisk;
        for (int i = 0; i < pL; i++) {
            if (p[i] != '*') {
                pattern.push_back(p[i]);
                asterisk.push_back(false);
            }
            else {
                asterisk.back() = true;
            }
        }

        pL = static_cast<int>(pattern.size());

        unique_ptr<bool[]> vf(new bool[(sL + 1) * (pL + 1)]());
        auto f = [&](int ls, int lp)->bool& {
            return vf.get()[ls * (pL+1) + lp];
        };

        // f(i,j) -> Validity to match s[:i] with pattern p[:j].
        // Initialization f[0,0] = true
        // Answer = f[eS,eP]
        memset(vf.get(), 0, sizeof(bool) * (sL + 1) * (pL + 1));
        f(0, 0) = true;
        for (int i = 0; i < pL; i++) {
            if (asterisk.at(i)) {
                f(0, i+1) = true;
            }
            else {
                break;
            }
        }

        for (int i = 1; i <= sL; i++) {
            for (int j = 1; j <= pL; j++) {
                //Updating f(i,j), subject to character s[i-1] and pattern p[j-1]
                
                //I. if p[j-1] is not asterisk-marked.
                if (!asterisk.at(j - 1)) {
                    if (pattern.at(j - 1) == '.' || (pattern.at(j - 1) == s.at(i - 1))) {
                        f(i, j) = f(i - 1, j - 1);
                    }
                }
                //II. if p[j-1] is asterisk-marked.
                else {
                    //II-a. the pattern is defined as the wild card (.*)
                    if (pattern.at(j - 1) == '.') {
                        f(i, j) = f(i, j) || f(i, j - 1);
                        for (int k = 0; k < i; k++) {
                            f(i, j) = f(i, j) || f(k, j - 1);
                        }
                    }
                    //II-b. the pattern is defined as (#*)
                    else {
                        f(i, j) = f(i, j) || f(i, j - 1);
                        for (int k = i - 1; k >= 0; k--) {
                            if (pattern.at(j - 1) == s.at(k)) {
                                f(i, j) = f(i, j) || f(k, j - 1);
                            }
                            else {
                                break;
                            }
                        }
                    }
                }
            }
        }
        return f(sL, pL);

    }
};

int main() {
    std::string a, b;
    cin >> a >> b;
    Solution sol;
    cout << std::boolalpha << sol.isMatch(a, b);
    return 0;
}