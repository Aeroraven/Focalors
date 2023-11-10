#include <iostream>
#include <algorithm>

template<unsigned int N> struct StairCnts {
    enum {
        value = StairCnts<N - 1>::value + StairCnts<N - 2>::value
    };
};

template<> struct StairCnts<2> {
    enum {
        value = 2
    };
};

template<> struct StairCnts<1> {
    enum {
        value = 1
    };
};

template<> struct StairCnts<0> {
    enum {
        value = 1
    };
};


class Solution {
public:
    int climbStairs(int n) {
        switch (n) {
        case 1:
            return StairCnts<1>::value;
        case 2:
            return StairCnts<2>::value;
        case 3:
            return StairCnts<3>::value;
        case 4:
            return StairCnts<4>::value;
        case 5:
            return StairCnts<5>::value;
        case 6:
            return StairCnts<6>::value;
        case 7:
            return StairCnts<7>::value;
        case 8:
            return StairCnts<8>::value;
        case 9:
            return StairCnts<9>::value;
        case 10:
            return StairCnts<10>::value;
        case 11:
            return StairCnts<11>::value;
        case 12:
            return StairCnts<12>::value;
        case 13:
            return StairCnts<13>::value;
        case 14:
            return StairCnts<14>::value;
        case 15:
            return StairCnts<15>::value;
        case 16:
            return StairCnts<16>::value;
        case 17:
            return StairCnts<17>::value;
        case 18:
            return StairCnts<18>::value;
        case 19:
            return StairCnts<19>::value;
        case 20:
            return StairCnts<20>::value;
        case 21:
            return StairCnts<21>::value;
        case 22:
            return StairCnts<22>::value;
        case 23:
            return StairCnts<23>::value;
        case 24:
            return StairCnts<24>::value;
        case 25:
            return StairCnts<25>::value;
        case 26:
            return StairCnts<26>::value;
        case 27:
            return StairCnts<27>::value;
        case 28:
            return StairCnts<28>::value;
        case 29:
            return StairCnts<29>::value;
        case 30:
            return StairCnts<30>::value;
        case 31:
            return StairCnts<31>::value;
        case 32:
            return StairCnts<32>::value;
        case 33:
            return StairCnts<33>::value;
        case 34:
            return StairCnts<34>::value;
        case 35:
            return StairCnts<35>::value;
        case 36:
            return StairCnts<36>::value;
        case 37:
            return StairCnts<37>::value;
        case 38:
            return StairCnts<38>::value;
        case 39:
            return StairCnts<39>::value;
        case 40:
            return StairCnts<40>::value;
        case 41:
            return StairCnts<41>::value;
        case 42:
            return StairCnts<42>::value;
        case 43:
            return StairCnts<43>::value;
        case 44:
            return StairCnts<44>::value;
        case 45:
            return StairCnts<45>::value;

        }
    }
};

int main() {
    Solution a;
    std::cout << a.climbStairs(24) << std::endl;
    return 0;
}