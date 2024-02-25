#include <vector>
#include <sstream>
#include <algorithm>
#include <iostream>
using namespace std;

class Solution {
public:
    int compare(int n, int k) {
        vector<string> w;
        for (int i = 1; i <= n; i++) {
            stringstream ss;
            ss << i;
            w.push_back(ss.str());
        }
        sort(w.begin(), w.end());
        int x = stoi(w[k-1]);
        return x;
    }
    int findKthNumber(int n, int k) {
        constexpr static const int base[] = {1,10,100,1000,10000,100000,1000000,10000000,100000000,1000000000};
        vector<int> dg;
        vector<int> remainder;

        int nv = n;
        while (nv) {
            dg.push_back(nv % 10);
            nv /= 10;
        }
        int p = 0;
        for (int i = 0; i < dg.size(); i++) {
            remainder.push_back(n % base[i] + 1);
        }

        int ans = 0;
        int d = dg.size();
        int cd = d-1; //current digit
        int vk = k;
        int limHigh = 1;
        while (cd>=0) {
            int accuRb = 0;
            int flag = 1;
            for (int i = ((cd == d - 1) ? 1 : 0); i <= 9;i++){
                //Calculate the right bound
                int rb = 0;
                for (int j = 0; j < cd; j++) {
                    rb += base[j];
                }
                //At highest digit
                if (dg[cd] == i && limHigh == 1) {
                    rb += remainder[cd];
                }
                else if (dg[cd] > i || limHigh!=1) {
                    rb += base[cd];
                }
                
                if (accuRb+rb < vk) {
                    //Continue
                    accuRb += rb;
                    continue;
                }
                else if (accuRb + 1 == vk) {
                    ans = ans * 10 + i;
                    return ans;
                }
                else {
                    //Proceed to next digit
                    if (limHigh == 1 && i > dg[cd]) {
                        limHigh = 2;
                        cd--;
                    }
                    else if (limHigh == 1 && i < dg[cd]) {
                        limHigh = 0;
                    }

                    vk -= accuRb;
                    vk --;
                    ans = ans * 10 + i;
                    cd--;
                    flag = 0;
                    
                    break;
                }
            }
            if (flag)throw;
        }
        return ans;
    }
};

int main() {
    Solution s;
    while (true) {
        int n, k;
        //cin >> n >> k;
        
        for (int n = 1; n <= 3000; n++) {
            cout <<"TEST:"<< n << endl;
            for (int k = 1; k <= 5; k++) {
                int v = rand() % n + 1;
                int a = s.findKthNumber(n, v);
                int b = s.compare(n, v);
                if (a != b) {
                    cout << n << "," << v << "," << a << "-" << b << endl;
                }
            }
        }
        break;
        cout << "STD=" << s.compare(n, k) << endl;
        cout << "ANS=" << s.findKthNumber(n, k) << endl;
    }
    return 0;
}