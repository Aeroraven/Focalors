#include <vector>
#include <iostream>
using namespace std;

class Solution {
public:
    double findMedianSortedArrays(vector<int>& num1, vector<int>& num2) {
        // Smaller: a[0]...a[s], b[0]...b[t]
        // Larger: a[s+1]...a[n], b[t+1]...b[m]
        // Subject to: 
        // I. s+t+2 = k/2-1 => t=k/2-s-2
        // II. a[s]<=b[t+1]
        // III. b[t]<=a[s+1]

        constexpr int NEGATIVE_INF = -20000000;
        constexpr int POSITIVE_INF = 20000000;

        vector<int>* p1, * p2;
        if (num1.size() >= num2.size()) {
            p1 = &num1;
            p2 = &num2;
        }
        else {
            p1 = &num2;
            p2 = &num1;
        }

        // Ensure that division point is undoubtedly located in sequence A
        vector<int>& a = *p1, & b = *p2;
        auto aL = static_cast<int>(a.size()), bL = static_cast<int>(b.size());
        if (aL == 0) {
            if (bL & 1) {
                return b[bL >> 1];
            }
            else {
                return (b[bL >> 1] + b[(bL >> 1) - 1]) * 0.5;
            }
        }
        if (bL == 0) {
            if (aL & 1) {
                return a[aL >> 1];
            }
            else {
                return (a[aL >> 1] + a[(aL >> 1) - 1]) * 0.5;
            }
        }
        if (aL == bL) {
            if (a[0] > b[bL - 1]) {
                return (a[0] + b[bL - 1]) * 0.5;
            }
        }

        
        // The division point is now mainly located in sequence A. Assume the answer is A[p] or B[t]
        // Then find p using binary search
        int l = 0, r = aL, mid = 0, target = (aL + bL) >> 1;
        int leftReqEls = (aL + bL + 1) >> 1;
        bool foundFlag = false;
        bool locatedInA = false;
        int optAIndex = -1, optBIndex = -1;
        while (l <= r) {
            mid = (l + r) >> 1;
            int t = (leftReqEls - mid - 2);
            t = std::max(-1, t);

            int aLeftUb = a[mid];
            int bLeftUb = (t >= 0) ? ((t < bL) ? b[t] : POSITIVE_INF) : NEGATIVE_INF;
            int aRightLb = (mid < aL - 1) ? a[mid + 1] : POSITIVE_INF;
            int bRightLb = (t < bL - 1) ? b[t + 1] : POSITIVE_INF;

            int leftPartElements = mid + 1 + (t + 1);

            /*
            cout << "----" << endl;
            cout << "Left:" << aLeftUb << "," << bLeftUb << " Tot=" << leftPartElements << " Des=" << leftReqEls << endl;
            cout << "DivPoint:" << mid << "," << t << ", tot=" << leftReqEls << endl;
            cout << "Right:" << aRightLb << "," << bRightLb << endl;
            */

            //If the number of left-part elements exceeds k/2, p should be shrunken
            if (leftPartElements > leftReqEls) {
                r = mid - 1;
                continue;
            }

            //Otherwise, narrow the left bound; 
            if (leftPartElements < leftReqEls) {
                l = mid + 1;
                continue;
            }

            //A[p] is larger than B[t+1], p should be shrunken
            if (aLeftUb > bRightLb) {
                r = mid - 1;
                continue;
            }

            //B[t] is larger than A[p+1], p should be increased
            if (bLeftUb > aRightLb) {
                l = mid + 1;
                continue;
            }

            //Answer is located in A[p] or B[t], the larger one should be the answer
            foundFlag = true;
            optAIndex = mid;
            optBIndex = t;
            if (a[mid] > bLeftUb) {
                locatedInA = true;
            }
            else {
                locatedInA = false;
            }
            break;
        }

        if (foundFlag == false) {
            //cout << "Abnormal flag: not found" << endl;
            return 0.0;
        }

        // If the total seq length is odd, answer is found
        if ((aL + bL) & 1) {
            if (locatedInA) {
                return a[optAIndex];
            }
            else {
                return b[optBIndex];
            }
        }
        else {
            //Otherwise, find the next answer
            int smaller = (locatedInA) ? a[optAIndex] : b[optBIndex];
            int larger = 0;
            if (optAIndex == aL - 1 && optBIndex == bL - 1) {
                cout << "Abnormal2" << endl;
            }
            else if (optAIndex == aL - 1) {
                larger = b[optBIndex + 1];
            }
            else if (optBIndex == bL - 1) {
                larger = a[optAIndex + 1];
            }
            else {
                larger = std::min(a[optAIndex + 1], b[optBIndex + 1]);
            }
            return (smaller + larger) * 0.5;
        }

        return 0.0;
    }
};

int main() {
    int n, m;
    cin >> n >> m;
    std::vector<int> a, b;
    int s;
    for (int i = 0; i < n; i++) {
        cin >> s;
        a.push_back(s);
    }
    for (int i = 0; i < m; i++) {
        cin >> s;
        b.push_back(s);
    }

    Solution x;
    cout << x.findMedianSortedArrays(a, b);
    return 0;

}