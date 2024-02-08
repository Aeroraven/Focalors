#include <iostream>
#include <unordered_set>
#include <set>
using namespace std;

struct Point {
	int x1, y1;
	bool operator == (const Point& p) const {
		return (x1 == p.x1) && (y1 == p.y1);
	}
	bool operator < (const Point& p) const {
		return (x1 < p.x1) || (x1 == p.x1 && y1 < p.y1);
	}
	size_t operator()(const Point& p) const {
		constexpr static int mod = 1000000000 + 7;
		return ((97 * x1) % mod + (23 * y1) % mod) % mod;
	}
};

class Solution {
public:
	bool isRectangleCover(vector<vector<int>>& rectangles) {
		std::set<Point> st;
		long long totalAreas = 0;
		for (auto& p : rectangles) {
			std::vector<Point> candidates = { {p[0],p[1]},{p[0],p[3]},{p[2],p[1]},{p[2],p[3]} };
			for (auto& x : candidates) {
				if (st.contains(x)) {
					st.erase(x);
				}
				else {
					st.insert(x);
				}
			}
			totalAreas += ((long long)std::abs(p[2] - p[0])) * std::abs(p[3] - p[1]);
		}
		if (st.size() != 4)return false;
		long long xMin = 1000000, xMax = -1000000, yMin = 1000000, yMax = -1000000;
		for (auto& p : st) {
			xMin = std::min((long long)p.x1, xMin);
			xMax = std::max((long long)p.x1, xMax);
			yMin = std::min((long long)p.y1, yMin);
			yMax = std::max((long long)p.y1, yMax);
		}
		long long desiredArea = (yMax - yMin) * (xMax - xMin);
		return desiredArea == totalAreas;
	}
};


int main() {
	Solution s;
	std::vector<std::vector<int>> x = {};
	std::cout << s.isRectangleCover(x) << std::endl;
	return 0;
}
