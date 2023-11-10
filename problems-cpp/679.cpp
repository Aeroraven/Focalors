#include <algorithm>
#include <vector>
using namespace std;

class Solution {
public:
    bool legality(int len, double* buf) {
        if (len == 1) {
            return abs(buf[0] - 24.0) < 1e-3;
        }
        else {
            double tmpBuf[4];
            for (int i = 0; i < len - 1; i++) {
                for (int j = 0; j < i; j++) tmpBuf[j] = buf[j];
                for (int j = i + 2; j < len; j++) tmpBuf[j - 1] = buf[j];
                tmpBuf[i] = buf[i] + buf[i + 1];
                if (legality(len - 1, tmpBuf))return true;
                tmpBuf[i] = buf[i] - buf[i + 1];
                if (legality(len - 1, tmpBuf))return true;
                tmpBuf[i] = buf[i] * buf[i + 1];
                if (legality(len - 1, tmpBuf))return true;
                tmpBuf[i] = buf[i] / buf[i + 1];
                if (legality(len - 1, tmpBuf))return true;
            }
            return false;
        }
    }

    bool judgePoint24(vector<int>& cards) {
        std::vector<double> p = { cards[0] * 1.0,cards[1] * 1.0,cards[2] * 1.0,cards[3] * 1.0 };
        std::sort(p.begin(), p.end());
        while (std::next_permutation(p.begin(), p.end())) {
            if (legality(4, p.data())) {
                return true;
            }
        }
        return false;
    }
};

int main() {
    Solution x;
    for (int a = 1; a <= 9; a++) {
        for (int b = 1; b <= 9; b++) {
            for (int c = 1; c <= 9; c++) {
                for (int d = 1; d <= 9; d++) {
                    std::vector<int> p = { a,b,c,d };
                    cout << a << "," << b << "," << c << "," << d << ":" << std::boolalpha << x.judgePoint24(p) << endl;
                }
            }
        }
    }
}