#include <string>
#include <iostream>
#include <deque>
#include <vector>
using namespace std;

class Solution {
public:
    string finalString(string s) {
        int c = 0;
        deque<char> q;
        for (auto& x : s) {
            if (x == 'i') {
                c++;
                continue;
            }
            if (c % 2)q.push_front(x);
            else q.push_back(x);
        }
        if (c == 0)return s;
        int qs = q.size();
        if (c % 2 == 0) {
            char* ret = new char[qs +1];
            ret[qs] = '\0';
            for (int i = 0; i < qs; i++) {
                ret[i] = q.front();
                q.pop_front();
            }

            return string(ret);
        }
        else {
            char* ret = new char[qs + 1];
            ret[qs] = '\0';
            for (int i = 0; i < qs; i++) {
                ret[i] = q.back();
                q.pop_back();
            }
            return string(ret);
        }
        return s;
    }
};

int main() {
    Solution s;
    while (true) {
        string a;
        cin >> a;
        cout << s.finalString(a) << endl;
    }
}