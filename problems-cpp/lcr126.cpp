#include <iostream>
#include <algorithm>
#include <vector>
#include <deque>
#include <cmath>
#include <cstdlib>

using namespace std;

using Integer = int;
template<Integer Index>
constexpr Integer adds();

template<Integer Index>
struct F {
    constexpr static Integer v = adds<Index>();
};
template<Integer Index>
constexpr Integer adds() {
    return (F<Index - 1>::v + F<Index - 2>::v) % (1000000007);
}
template<>
struct F<0> {
    constexpr static Integer v = 0;
};
template<>
struct F<1> {
    constexpr static Integer v = 1;
};
#define FIB_CASE(x) case x: \
    return F<x>::v;

#define FIB_REC_1(x) \
    FIB_CASE(x##0) \
    FIB_CASE(x##1) \
    FIB_CASE(x##2) \
    FIB_CASE(x##3) \
    FIB_CASE(x##4) \
    FIB_CASE(x##5) \
    FIB_CASE(x##6) \
    FIB_CASE(x##7) \
    FIB_CASE(x##8) \
    FIB_CASE(x##9) \

#define FIB_REC_2() \
    FIB_REC_1() \
    FIB_REC_1(1) \
    FIB_REC_1(2) \
    FIB_REC_1(3) \
    FIB_REC_1(4) \
    FIB_REC_1(5) \
    FIB_REC_1(6) \
    FIB_REC_1(7) \
    FIB_REC_1(8) \
    FIB_REC_1(9) \

#define FIB(x) switch(x) {\
    FIB_REC_2() \
    FIB_CASE(100) \
    default: \
        return -1; \
}\

int fib(int n) {
    FIB(n);
}

int main() {
    int n;
    cin >> n;
    cout << fib(n) << endl;
    return 0;
}