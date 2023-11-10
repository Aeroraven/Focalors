#include <iostream>
#include <vector>
#include <cstdlib>
#include <cmath>
#include <map>
#include <unordered_map>
#include <cstring>

using namespace std;
int maxCost(const vector<int>& data) {
    auto sz = data.size();
    unordered_map<int, int> m;
    for (auto i = 0; i < sz; i++) {
        m[data[i]] = i;
    }
    auto fc = new int[sz * sz];
    auto f = [&](int i, int j) {
        return &fc[i * sz + j];
        };
    memset(fc, 0, sizeof(int) * sz * sz);
    if (data[0] == 0 && data[1] == 1) {
        *f(0, 1) = 1;
    }
    auto ans = 0;
    for (int i = 0; i < sz; i++) {
        for (int j = 0; j < i; j++) { //j->i
            if (*f(j, i)) {
                auto k = data[i] - data[j];
                auto nk = data[i] + k;
                if (m.count(nk + 1)) {
                    *f(i, m[nk + 1]) = 1;
                }
                if (m.count(nk)) {
                    *f(i, m[nk]) = 1;
                }
                if (m.count(nk - 1)) {
                    *f(i, m[nk - 1]) = 1;
                }
            }
        }
    }
    for (int i = 0; i < sz - 1; i++) {
        ans |= *f(i, sz - 1);
    }
    return ans;
}

int main() {
    vector<int> test = { 0,1,2,3,4,8,9,11 };//{0,1,3,5,6,8,12,17};
    cout << maxCost(test) << endl;
    return 0;
}