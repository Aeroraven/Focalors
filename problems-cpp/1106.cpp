#include <stack>
#include <iostream>
#include <string>

class Solution {
public:
    bool parseBoolExpr(std::string expression) {
        std::stack<char> s;
        for (auto& ch : expression) {
            if (ch == '&' || ch == '|' || ch == '!' || ch == 'f' || ch == 't')s.push(ch);
            if (ch == '(' || ch == ',')continue;
            if (ch == ')') {
                bool andRes = true, orRes = false, notRes = true;
                while (true) {
                    if (s.top() == 't') {
                        orRes = true;
                        notRes = false;
                        s.pop();
                    }else if(s.top() == 'f'){
                        andRes = false;
                        notRes = true;
                        s.pop();
                    }
                    else if (s.top() == '&') {
                        s.pop();
                        if (andRes)s.push('t');
                        else s.push('f');
                        break;
                    }
                    else if (s.top() == '|') {
                        s.pop();
                        if (orRes) s.push('t');
                        else s.push('f');
                        break;
                    }
                    else if (s.top() == '!') {
                        s.pop();
                        if (notRes) s.push('t');
                        else s.push('f');
                        break;
                    }
                }
            }
        }
        if (s.top() == 't')return true;
        return false;
    }
};

int main() {
    Solution s;
    std::string x;
    while (true) {
        std::cin >> x;
        std::cout << std::boolalpha << s.parseBoolExpr(x) << std::endl;
    }
    return 0;
}