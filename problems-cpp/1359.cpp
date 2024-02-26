class Solution {
public:
    int countOrders(int n) {
        constexpr static const int modf = 1000000007;
        long long res = 1;
        for (int i = 1; i <= n; i++) {
            res *= (2 * i - 1);
            res %= modf;
            res *= i;
            res %= modf;
        }
        return res;
    }
};