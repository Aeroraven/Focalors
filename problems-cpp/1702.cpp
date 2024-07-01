#include <iostream>
#include <string>
#include <cstring>
using namespace std;

class Solution {
public:
    string maximumBinaryString(string binary) {
        int fz = 0;
        int n = binary.size();
        char* p = new char[n + 1];
        memset(p, '1', n + 1);
        p[n] = 0;
        while (fz < n && binary[fz] == '1')fz++;
        if (fz == n)return string(p);
        int n1 = 0;
        for (auto i = fz + 1; i < n; i++) {
            if (binary[i] == '1')n1++;
        }
        p[n - 1 - n1] = '0';
        return string(p);
    }
};