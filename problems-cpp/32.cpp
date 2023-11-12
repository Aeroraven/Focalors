#include <iostream>
#include <stack>
#include <memory>
using namespace std;

class Solution {
public:
    int longestValidParentheses(string s) {
        int sL = static_cast<int>(s.size());
        unique_ptr<int[]> f = make_unique<int[]>(sL);
        memset(f.get(), 0, sizeof(int) * sL);
        
        //f[i] = length of longest parentheses seq, end with character i
        //f[i] = i-stackTop+1 + f[stackTop-1]
        
        //Solve the problem using stack
        stack<int> leftParaIndex;
        int ans = 0;
        for (int i = 0; i < sL; i++) {
            if (s[i] == '(') {
                leftParaIndex.push(i);
            }
            else {
                if (!leftParaIndex.empty()) {
                    auto last = leftParaIndex.top();
                    leftParaIndex.pop();
                    f[i] = i - last + 1;
                    if (last - 1 >= 0) {
                        f[i] += f[last - 1];
                    }
                    ans = max(ans, f[i]);
                }
            }
        }
        return ans;
    }
};

int main() {
    string s;
    Solution sol;
    while (true) {
        cin >> s;
        cout << boolalpha << sol.longestValidParentheses(s) << endl;
    }
    
    return 0;
}