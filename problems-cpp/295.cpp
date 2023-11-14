#include <iostream>
#include <algorithm>
#include <vector>
#include <string>
#include <queue>
using namespace std; 

class GreaterComparer {
public:
    inline bool operator()(const int& a, const int& b) {
        return a > b;
    }
};
class MedianFinder {
public:
    priority_queue<int> lesserHeap;
    priority_queue<int, vector<int>, GreaterComparer> greaterHeap;
    int n = 0;

    MedianFinder() {

    }

    void addNum(int num) {
        n++;
        if (n == 1) {
            lesserHeap.push(num);
            return;
        }
        if (n == 2) {
            greaterHeap.push(num);
        }
        else {
            if (num > greaterHeap.top()) {
                greaterHeap.push(num);
            }
            else {
                lesserHeap.push(num);
            }
            
        }
        // Restabilize the heap, ensure that top of lesser heap is larger than the top of 
        // greater heap.
        
        // If the top of greater heap is smaller, pop it out and insert it into the lesser heap
        while (!greaterHeap.empty() ) {
            auto gt = greaterHeap.top();
            auto lt = lesserHeap.top();
            if (gt >= lt)break;
            greaterHeap.pop();
            lesserHeap.push(gt);
        }

        // If lesser heap has too many elements, pop them out and add them into the greater heap
        while (lesserHeap.size() > (n + 1) / 2) {
            auto tp = lesserHeap.top();
            lesserHeap.pop();
            greaterHeap.push(tp);
        }

        while (greaterHeap.size() > (n) / 2) {
            auto tp = greaterHeap.top();
            greaterHeap.pop();
            lesserHeap.push(tp);
        }
    }

    double findMedian() {
        if (n % 2 == 0) {
            int left = lesserHeap.top();
            int right = greaterHeap.top();
            //cout << "Left,Right=" << left << "," << right << endl;
            return (left + right) * 0.5;
        }
        else {
            //cout << "Left=" << lesserHeap.top() << endl;
            return lesserHeap.top();
        }
    }
};

int main() {
    MedianFinder s;
    string w;
    while (true) {
        cin >> w;
        if (w[0] == 'A') {
            int a;
            cin >> a;
            s.addNum(a);
            cout << s.findMedian() << endl;
        }
        else {
            cout << s.findMedian() << endl;
        }
    }
    return 0;
}