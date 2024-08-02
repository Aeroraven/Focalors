#include <iostream>
#include <vector>
#include <map>
using namespace std;

class Solution {
public:
    int oddEvenJumps(vector<int>& arr) {
        //LessMap: 
        map<int, int> largerMap, smallerMap;
        int n = arr.size();
        vector<int> resOdd(n),resEven(n);
        resOdd[n - 1] = 1;
        resEven[n - 1] = 1;
        largerMap[arr[n - 1]] = n - 1;
        smallerMap[-arr[n - 1]] = n - 1;

        for (int i = arr.size() - 2; i >= 0; i--) {
            //First iter for A[i]<=A[iter], Odd jump
            auto largerIts = largerMap.upper_bound(arr[i] - 1);
            if (largerIts == largerMap.end()) {
                resOdd[i] = 0;
            }
            else {
                resOdd[i] = resEven[largerIts->second];
            }
            //First iter for A[i]>=A[iter], Even jump
            //Equiv to first iter for -A[i]<=-A[iter]
            auto smallerIts = smallerMap.upper_bound(-arr[i] - 1);
            if (smallerIts == smallerMap.end()) {
                resEven[i] = 0;
            }
            else {
                resEven[i] = resOdd[smallerIts->second];
            }
            //Set
            largerMap[arr[i]] = i;
            smallerMap[-arr[i]] = i;
        }
        int cnt = 0;
        for (int i = 0; i < n; i++) {
            cnt += (resOdd[i] == 1);
        }
        return cnt;

    }
};

int main() {
    Solution s;
    vector<int> dx = { 5,1,3,4,2 };
    cout << s.oddEvenJumps(dx) << endl;
    return 0;
}