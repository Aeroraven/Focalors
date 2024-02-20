#include <iostream>
#include <string>
#include <vector>
using namespace std;

class Solution {
public:
    vector<int> invalidRight;
    vector<int> invalidLeft = vector<int>(25);

    vector<int> invTagRight = vector<int>(25);
    vector<int> invTagLeft = vector<int>(25);
    int stTop = 0;
    char* tAns = new char[26];
    int tAnsCur = 0;
    int curLeftBrackets = 0;
    vector<string> ans;
    void dfs(const string& s,int st,int delRight,int reqRight,int reduced,int delLeft,int reqLeft){
        if (delLeft > reqLeft)return;
        if (st == s.size()) {
            tAns[tAnsCur++] = '\0';
            if (delRight == reqRight && delLeft==reqLeft) {
                
                ans.push_back(tAns);
                
            }
            tAnsCur--;
            return;
        }
        if (s[st] == '(') {
            int accuBrackets = 0;
            int nextSt = 0;
            int nReqLeft = 0;
            for (int i = st; i < s.size(); i++) {
                if (s[i] != '(')break;
                accuBrackets++;
                if (invTagLeft[i])nReqLeft++;
            }
            nextSt = st + accuBrackets;


            for (int i = 0; i < accuBrackets; i++) {
                tAns[tAnsCur++] = '(';
                curLeftBrackets++;
            }
            for (int i = accuBrackets; i >= 1; i--) {
                dfs(s, nextSt, delRight, reqRight, reduced,delLeft+(accuBrackets-i),reqLeft);
                tAnsCur--;
                curLeftBrackets--;
            }
            dfs(s, nextSt, delRight, reqRight, reduced, delLeft + accuBrackets, reqLeft);
        }
        else if (s[st] == ')') {
            int accuBrackets = 0;
            int nextSt = 0;
            int nReq = 0;
            for (int i = st; i < s.size(); i++) {
                if (s[i] != ')')break;
                accuBrackets++;
                if (invTagRight[i])nReq++;
            }
            nextSt = accuBrackets + st;
            //Remove
            int necessaryNum = std::max(0, reduced + nReq - delRight);
            int upperBound = reqRight - delRight;
            if (necessaryNum > upperBound)return;

            int minRemain = std::max(accuBrackets - upperBound,0), maxRemain = accuBrackets - necessaryNum;
            int bex = tAnsCur;
            for (int i = 1; i <= maxRemain; i++) {
                tAns[tAnsCur++] = ')';
                curLeftBrackets--;
            }
            for (int i = maxRemain ; i >= std::max(1,minRemain); i--) {
                if (curLeftBrackets >= 0) {
                    dfs(s, nextSt, delRight + (accuBrackets - i), reqRight, reduced + nReq, delLeft, reqLeft);
                }
                tAnsCur--;
                curLeftBrackets++;
                
            }
            for (int i = minRemain - 1; i >= 1; i--) {
                tAnsCur--;
                curLeftBrackets++;
            }
            if (bex != tAnsCur) {
                cout << bex << "," << tAnsCur << "/"<<minRemain<<","<<maxRemain<< endl;
                throw;
            }
            if (minRemain == 0) {
                dfs(s, nextSt, delRight + accuBrackets, reqRight, reduced + nReq,delLeft,reqLeft);
            }
        }
        else {
            tAns[tAnsCur++] = s[st];
            dfs(s, st + 1, delRight, reqRight, reduced, delLeft, reqLeft);
            tAnsCur--;
        }
    }
    vector<string> removeInvalidParentheses(string s) {
        for (int i = 0; i < s.size(); i++) {
            if (s[i] == '(') {
                invalidLeft[stTop++] = i;
            }
            else if (s[i] == ')') {
                if (stTop > 0)stTop--;
                else {
                    invalidRight.push_back(i);
                    invTagRight[i] = 1;
                }
            }
        }
        for (int i = 0; i < stTop; i++) {
            invTagLeft[invalidLeft[i]] = 1;

        }
        dfs(s, 0, 0, invalidRight.size(), 0,0,stTop);
        for (auto& p : ans) {
            cout << p << endl;
        }
        return ans;
    }
};

int main() {
    while (true) {
        Solution s;
        string x;
        cin >> x;
        s.removeInvalidParentheses(x);
    }
    return 0;
}