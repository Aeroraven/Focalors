using namespace std;
class Solution {
public:
	int mySqrt(int x) {
		long long l = 1, r = x, mid = 0;
		while (l < r) {
			mid = (l + r) / 2;
			if (mid * mid == x)return mid;
			if (mid * mid<x && (mid + 1) * (mid + 1)>x) {
				return mid;
			}
			else if (mid * mid > x) {
				r = mid - 1;
			}
			else {
				l = mid + 1;
			}
		}
		mid = (l + r) / 2;
		return mid;
	}
};