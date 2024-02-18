#include <vector>
#include <iostream>
#include <string>
#include <stack>
using namespace std;
class Solution {
public:
    vector<int> st = vector<int>(30);
    vector<string> finalAns;
    int stackTop = 0;
    void dfs(string a, int start, int target, long long answer, long long multiRes, int lastSign,int operands ) {
        if (start == a.size()) {
            //Complete
            long long totalRes = answer + lastSign * multiRes;
            if (totalRes==target) {
                char* res = new char[a.size() + operands + 1];
                int cur = 0, clast = -1;
                for (int i = 0; i < stackTop; i++) {
                    if (st[i] <= 10) {
                        for (int j = clast + 1; j <= st[i]; j++) {
                            res[cur++] = a[j];
                        }
                        clast = st[i];
                    }
                    else if (st[i] == 101) {
                        res[cur++] = '+';
                    }
                    else if (st[i] == 102) {
                        res[cur++] = '-';
                    }
                    else if (st[i] == 103) {
                        res[cur++] = '*';
                    }
                }
                res[a.size() + operands] = '\0';
                finalAns.push_back(res);
            }

            return;
        }
        if (start == 0) {
            long long number = 0;
            for (int i = 0; i < a.size(); i++) {
                number = number * 10 + (a[i]-'0');
                st[stackTop++] = i;
                dfs(a, i+1, target, answer, number, 1,0);
                stackTop--;
                if (i == 0 && a[i] == '0')break;
            }
        }
        else {
            for (int op = 0; op <= 2; op++) {
                long long number = 0;
                for (int i = start; i < a.size(); i++) {
                    number = number * 10 + (a[i]-'0');
                    if (op == 0) { //Plus Sign
                        answer += lastSign * multiRes;
                        st[stackTop++] = 101;
                        st[stackTop++] = i;
                        dfs(a, i + 1, target, answer, number, 1 , operands+1);
                        stackTop--;
                        stackTop--;
                        answer -= lastSign * multiRes;
                    }
                    else if (op == 1) { //Minus Sign
                        answer += lastSign * multiRes;
                        st[stackTop++] = 102;
                        st[stackTop++] = i;
                        dfs(a, i + 1, target, answer, number, -1, operands + 1);
                        stackTop--;
                        stackTop--;
                        answer -= lastSign * multiRes;
                    }
                    else { //Multiply
                        st[stackTop++] = 103;
                        st[stackTop++] = i;
                        dfs(a, i + 1, target, answer, multiRes*number, lastSign, operands + 1);
                        stackTop--;
                        stackTop--;
                    }
                    if (i == start && a[i] == '0')break;
                }
            }
        }
    }
    vector<string> addOperators(string num, int target) {
        dfs(num, 0, target, 0, 0, 1, 0);
        return finalAns;
    }
};

int main() {
    Solution s;
    auto p = s.addOperators("10", 10);
    for (auto& v : p) {
        cout << v << endl;
    }
    return 0;
}