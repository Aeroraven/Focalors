class Solution {
public:
	int reverse(int x) {
		bool flag = (x < 0);
		if (x == -2147483648)return 0;
		x = flag ? -x : x;
		int ret = 0;
		while (1) {
			if (ret != 0) {
				if (2147483647 / ret < 10)return 0;
			}
			ret *= 10;
			if (2147483647 - ret < x % 10)return 0;
			ret += x % 10;
			x /= 10;
			if (x == 0) break;
		}
		return flag ? -ret : ret;
	}
};