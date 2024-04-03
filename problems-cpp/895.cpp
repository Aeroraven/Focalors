#include <unordered_map>
#include <vector>
#include <queue>
using namespace std;

struct Elem {
    int v, ord, freq;
    bool operator < (const Elem& p) const {
        if (freq == p.freq) return ord < p.ord;
        return freq < p.freq;
    }
};

class FreqStack {
public:
    unordered_map<int, int> hs;
    priority_queue<Elem> q;
    int cOrd = 0;

    FreqStack() {
        
    }

    void push(int val) {
        cOrd++;
        int freq = hs[val] + 1;
        hs[val] = freq;
        q.push({ val,cOrd,freq });
    }

    int pop() {
        auto x = q.top();
        q.pop();
        hs[x.v]--;
        return x.v;
    }
};