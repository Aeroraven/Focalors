#include <iostream>
#include <vector>
#include <cstring>
#include <cstring>
class Solution {
public:
    long long fastPower(long long base, long long power, long long mod) {
        long long ans = 1;
        while (power) {
            if (power & 1) {
                ans = ans * base;
                ans %= mod;
            }
            base = base * base;
            base %= mod;
            power >>= 1;
        }
        return ans;
    }
    int numberOfGoodSubsets(std::vector<int>& nums) {
        // f[i][s] is the number of subsets obtained using first i numbers and s primes
        // f[i][s] = f[i-1][s] + f[i-1][t] where (prime[i]&t==0 and prime[i]&t==s)

        constexpr static int prime[] = {2,3,5,7,11,13,17,19,23,29};
        constexpr static int nPrimes = (sizeof(prime) / sizeof(int));
        constexpr static int nState = ((1 << nPrimes));
        constexpr static int modf = 1000000000 + 7;
        int n = nums.size();
        int mask[31];
        int count[31];
        int* f = new int[2* nState];
        memset(f, 0, (2 * nState * sizeof(int)));
        memset(mask, 0, sizeof(mask));
        memset(count, 0, sizeof(count));
        
        for (int i = 1; i <= 30; i++) {
            int cMask = 0;
            int cur = 0;
            int curCand = i;
            while (cur < nPrimes) {
                if (curCand % prime[cur] == 0) {
                    curCand /= prime[cur];
                    if ((cMask & (1 << cur)) == 0) {
                        cMask |= (1 << cur);
                        continue;
                    }
                    else {
                        mask[i] = -1;
                        break;
                    }
                }
                cur++;
            }
            if (mask[i] != -1) {
                mask[i] = cMask;
            }
        }
        for (int i = 0; i < n; i++) {
            count[nums[i]]++;
        }

        f[nState] = 1;
        int j = 0;
        for (int i = 2; i <= 30; i++) {
            if (count[i] == 0 || mask[i]==-1)continue;
            int bf = (j % 2) * nState;
            int nbf = ((j + 1) % 2) * nState;
            for (int k = 0; k < nState; k++) {
                f[bf + k] = f[nbf + k];
                if ((k & mask[i]) == mask[i]) {
                    f[bf + k] += ((long long)count[i] * (long long)f[nbf + (k & (~mask[i]))])%modf;
                    f[bf + k] %= modf;
                }
            }
            j++;
        }
        int ans = 0;
        for (int i = 1; i < nState; i++) {
            ans += f[((j+1) % 2) * nState + i];
            ans %= modf;
        }
        if (count[1] && ans) {
            ans = (int)(((long long)ans * fastPower(2,count[1],modf)) % modf);
        }

        return ans;
    }
};

int main() {
    Solution s;
    std::vector<int> p = { 4,2,3,15 };
    std::cout<<s.numberOfGoodSubsets(p);
    return 0;
}