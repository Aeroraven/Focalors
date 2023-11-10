#include <iostream>
#include <vector>
#include <cstdlib>
#include <cmath>
#include <cstring>

using namespace std;
int maxCost(const vector<int>& ball) {
    auto size = ball.size();
    auto fc = new int[size * size];
    memset(fc, 0, sizeof(int) * size * size);
    auto f = [&](int i, int j) {
        return &fc[i * size + j];
        };
    for (int l = 0; l < size; l++) {
        for (int i = 0; i < size; i++) {
            int j = i + l;
            if (j >= size) break;
            int leftValue = (i == 0) ? 1 : ball[i - 1];
            int rightValue = (j == (size - 1)) ? 1 : ball[j + 1];
            for (int k = i; k <= j; k++) {
                int leftCost = (i == k) ? 0 : *f(i, k - 1);
                int rightCost = (j == k) ? 0 : *f(k + 1, j);
                *f(i, j) = max(*f(i, j), leftCost + rightCost + ball[k] * leftValue * rightValue);
            }
        }
    }
    return *f(0, size - 1);
}

int main() {
    vector<int> test = { 3,1,5,8 };
    cout << maxCost(test) << endl;
    return 0;
}