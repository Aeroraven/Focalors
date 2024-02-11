#include <iostream>
#include <vector>
#include <unordered_map>
#include <algorithm>
#include <unordered_set>

struct Interval {
    int y, left, right, dir;
    bool operator <(const Interval& p) const {
        return y < p.y;
    }
};

class SegmentTree {
public:
    int* coverage = nullptr;
    int* coverageSum = nullptr;
    int* change = nullptr;
    std::vector<int>* landmarks = nullptr;

    SegmentTree(std::vector<int>* ld) {
        this->landmarks = ld;
        int w = ld->size() * 4 + 4;
        this->coverage = new int[w];
        this->coverageSum = new int[w];
        this->change = new int[w];
        memset(this->coverage, 0, w * sizeof(int));
        memset(this->change, 0, w * sizeof(int));
    }
    void insertInterval(int insL, int insR, int val) {
        return insertIntervalImpl(0, this->landmarks->size()-1, insL, insR, 1, val);
    }
    void pushUp(int id, int l, int r) {

        if (this->change[id]) {
            this->coverage[id] = (*landmarks)[r+1] - (*landmarks)[l];
        }
        else {
            if (l == r) {
                this->coverage[id] = 0;
            }
            else {
                this->coverage[id] = this->coverage[id * 2] + this->coverage[id * 2 + 1];
            }
        }
        //std::cout << "COVERAGE[" << l << "," << r << "|"<<id<<"]=" << coverage[id] << std::endl;
    }
    void insertIntervalImpl(int l, int r, int insL, int insR, int id,int val) {
        if (l > r)return ;
        if (l > insR || r < insL)return ;

        if (l == insL && r == insR) {
            change[id] += val;
            pushUp(id, l, r);
        }
        else {
            int mid = (long long) (l + r) >> 1;
            insertIntervalImpl(l, mid, insL, std::min(insR,mid), id * 2, val);
            insertIntervalImpl(mid + 1, r, std::max(insL,mid+1), insR, id * 2 + 1, val);
            pushUp(id, l, r);
            
        }
    }
};

class Solution {
public:
    int rectangleArea(std::vector<std::vector<int>>& rectangles) {
        constexpr static int modf = 1000000007;
        // Discretization
        std::unordered_map<int,int> landmarkRemap;
        std::vector<int> landmarks;
        std::vector<Interval> intervals;
        int cur = 0;
        for (int i = 0; i < rectangles.size(); i++) {
            for (int j = 0; j < 3; j += 2) {
                if (!landmarkRemap.count(rectangles[i][j])) {
                    landmarks.push_back(rectangles[i][j]);
                    landmarkRemap[rectangles[i][j]] = 1;
                }
            }
            intervals.push_back({ rectangles[i][1],rectangles[i][0],rectangles[i][2],1 });
            intervals.push_back({ rectangles[i][3],rectangles[i][0],rectangles[i][2],-1 });
        }
        std::sort(landmarks.begin(), landmarks.end());
        for (int i = 0; i < landmarks.size(); i++) {
            landmarkRemap[landmarks[i]] = i;
        }

        // Sort
        std::sort(intervals.begin(), intervals.end());

        // Line Sweeping
        SegmentTree tree(&landmarks);
        int lastY = intervals[0].y;
        long long ans = 0;
        for (int i = 0; i < intervals.size(); i++) {
            ans += (long long)tree.coverage[1] * (intervals[i].y - lastY );
            ans %= modf;
            tree.insertInterval(landmarkRemap[intervals[i].left], landmarkRemap[intervals[i].right]-1,intervals[i].dir);
            lastY = intervals[i].y;
            
        }
        return (int)(ans % modf);

    }
};

int main() {
    Solution s;
    std::vector<std::vector<int>> x = { {22,12,54,31},{16,13,39,94} };
    std::cout << s.rectangleArea(x);
    return 0;
}