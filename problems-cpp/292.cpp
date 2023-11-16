#include <iostream>
using namespace std;


class Solution {
public:
    bool canWinNim(int n) {
        // Status transition:
        // f(0) = Fail
        // for all status x that have transition to all y that f(x-k)=f(y)=Win, f(x) = fail
        // for all status x that have transition to at least one y that f(x-k)=f(y)=fail, f(x)=win
        // f(1)=f(2)=f(3)=win
        // f(4)=fail => f(5),f(6),f(7)=win => f(8)=fail
        return (n % 4);
    }
};

int main() {
    return 0;
}