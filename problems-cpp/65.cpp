#include <iostream>
#include <vector>
#include <cctype>
using namespace std;

enum ParsedTokenTp {
    SIGN,
    NUMERIC_PART,
    DECIMAL_POINT,
    EXP_MARK,
    UNDEFINED_TOKEN
};

class Solution {
public:
    bool isNumber(string s) {
        std::vector<ParsedTokenTp> tokens;
        auto tokenParser = [&](const string& p) {
            bool prevNumeric = false;
            for (auto& w : p) {
                if (prevNumeric && !isdigit(w)) {
                    tokens.push_back(NUMERIC_PART);
                    prevNumeric = false;
                }
                if (isdigit(w)) {
                    prevNumeric = true;
                }
                else if (w == '-' || w == '+') {
                    tokens.push_back(SIGN);
                }
                else if (w == 'e' || w == 'E') {
                    tokens.push_back(EXP_MARK);
                }
                else if (w == '.') {
                    tokens.push_back(DECIMAL_POINT);
                }
                else {
                    tokens.push_back(UNDEFINED_TOKEN);
                }
            }
            if (prevNumeric) {
                tokens.push_back(NUMERIC_PART);
            }
        };
        //DECIMAL -> SIGN,NUM,DEC_PT
        //DECIMAL -> SIGN,NUM,DEC_PT,NUM
        //DECIMAL -> SIGN,DEC_PT,NUM 
        //DECIMAL -> NUM,DEC_PT
        //DECIMAL -> NUM,DEC_PT,NUM
        //DECIMAL -> DEC_PT,NUM
        //INTEGER -> SIGN,NUM
        //INTEGER -> NUM

        std::vector<std::vector<ParsedTokenTp>> decimalRule = {
            {SIGN,NUMERIC_PART,DECIMAL_POINT},
            {SIGN,NUMERIC_PART,DECIMAL_POINT,NUMERIC_PART},
            {SIGN,DECIMAL_POINT,NUMERIC_PART},
            {NUMERIC_PART,DECIMAL_POINT},
            {NUMERIC_PART,DECIMAL_POINT,NUMERIC_PART},
            {DECIMAL_POINT,NUMERIC_PART},
        };
        std::vector<std::vector<ParsedTokenTp>> integerRule = {
            {SIGN,NUMERIC_PART},
            {NUMERIC_PART},
        };
        auto testRuleSet = [&](const std::vector<std::vector<ParsedTokenTp>>& ruleset, std::vector<ParsedTokenTp>::const_iterator begin, std::vector<ParsedTokenTp>::const_iterator end) {
            auto length = static_cast<int>(end - begin);
            for (const auto& rule : ruleset) {
                if (length != rule.size()) {
                    continue;
                }
                bool flag = true;
                for (int i = 0; i < length; i++) {
                    if (*(begin + i) != rule[i]) {
                        flag = false;
                        break;
                    }
                }
                if (flag) {
                    return true;
                }
            }
            return false;
        };


        auto ruleMatcher = [&](const std::vector<ParsedTokenTp>& p) {
            auto expV = std::find(p.begin(), p.end(), EXP_MARK);
            if (expV == p.end()) {
                //Exp sign not present
                auto decimalMatch = testRuleSet(decimalRule, p.begin(), p.end());
                auto integerMatch = testRuleSet(integerRule, p.begin(), p.end());
                if (decimalMatch || integerMatch) {
                    return true;
                }
                return false;
            }
            else {
                auto firstPartDecimal = testRuleSet(decimalRule, p.begin(), expV);
                auto firstPartInteger = testRuleSet(integerRule, p.begin(), expV);
                auto secondPartInteger = testRuleSet(integerRule, expV+1, p.end());
                if ((firstPartDecimal||firstPartInteger) && secondPartInteger) {
                    return true;
                }
                return false;
            }
        };
        tokenParser(s);
        return ruleMatcher(tokens);
    }
};

int main() {
    std::string s;
    while (true) {
        cin >> s;
        Solution sol;
        cout << std::boolalpha << sol.isNumber(s) << endl;
    }
    return 0;
}