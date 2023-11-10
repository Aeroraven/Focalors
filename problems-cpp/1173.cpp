#include <iostream>
#include <algorithm>
#include <vector>
#include <deque>
#include <cmath>
#include <cstdlib>

using namespace std;

using IntTp = int;
template<IntTp Index>
struct Tribonacci {
    constexpr static IntTp v = Tribonacci<Index - 1>::v + Tribonacci<Index - 2>::v + Tribonacci<Index - 3>::v;
};

#define PARTIAL_TRIBONACCI_SPEC(x,y) template<>\
    struct Tribonacci<x>{ \
        constexpr static IntTp v = y; \
    }; \


#define TRIBONACCI_AERORAVEN_FLAG

#define TRIBONACCI_GENERATE_SINGLE_CASE(x) case x:\
    return Tribonacci<x>::v;

#define TRIBONACCI_GENERATE_CASE_SINGLULAR_SERIAL(x) \
    TRIBONACCI_GENERATE_SINGLE_CASE(x##0) \
    TRIBONACCI_GENERATE_SINGLE_CASE(x##1) \
    TRIBONACCI_GENERATE_SINGLE_CASE(x##2) \
    TRIBONACCI_GENERATE_SINGLE_CASE(x##3) \
    TRIBONACCI_GENERATE_SINGLE_CASE(x##4) \
    TRIBONACCI_GENERATE_SINGLE_CASE(x##5) \
    TRIBONACCI_GENERATE_SINGLE_CASE(x##6) \
    TRIBONACCI_GENERATE_SINGLE_CASE(x##7) \
    TRIBONACCI_GENERATE_SINGLE_CASE(x##8) \
    TRIBONACCI_GENERATE_SINGLE_CASE(x##9) \

#define TRIBONACCI_GENERATE_CASE_SINGLULAR_SERIAL_LAST(x) \
    TRIBONACCI_GENERATE_SINGLE_CASE(x##0) \
    TRIBONACCI_GENERATE_SINGLE_CASE(x##1) \
    TRIBONACCI_GENERATE_SINGLE_CASE(x##2) \
    TRIBONACCI_GENERATE_SINGLE_CASE(x##3) \
    TRIBONACCI_GENERATE_SINGLE_CASE(x##4) \
    TRIBONACCI_GENERATE_SINGLE_CASE(x##5) \
    TRIBONACCI_GENERATE_SINGLE_CASE(x##6) \
    TRIBONACCI_GENERATE_SINGLE_CASE(x##7) \

#define TRIBONACCI_GENERATE_ALL_CASES() \
    TRIBONACCI_GENERATE_CASE_SINGLULAR_SERIAL()  \
    TRIBONACCI_GENERATE_CASE_SINGLULAR_SERIAL(1) \
    TRIBONACCI_GENERATE_CASE_SINGLULAR_SERIAL(2) \
    TRIBONACCI_GENERATE_CASE_SINGLULAR_SERIAL_LAST(3) \

#define TRIBONACCI_SWITCH(x) switch(x){ \
    TRIBONACCI_GENERATE_ALL_CASES() \
    default:\
        return -1;\
}\


PARTIAL_TRIBONACCI_SPEC(0, 0);
PARTIAL_TRIBONACCI_SPEC(1, 1);
PARTIAL_TRIBONACCI_SPEC(2, 1);

class Solution {
public:
    int tribonacci(int n) {
        TRIBONACCI_SWITCH(n);
    }
};

int main() {
    Solution s;
    int n;
    cin >> n;
    cout << s.tribonacci(n) << endl;
    return 0;
}