class Solution {
public:
	vector<int> plusOne(vector<int>& digits) {
		vector<int> rev;
		vector<int> ret;
		int sz = digits.size();
		for (int i = sz - 1; i >= 0; i--) {
			rev.push_back(digits[i]);
		}
		int ca = 0;
		rev[0]++;
		for (int i = 0; i < sz; i++) {
			rev[i] = rev[i] + ca;
			if (rev[i] >= 10) {
				rev[i] -= 10;
				ca = 1;
			}
			else {
				ca = 0;
			}
		}
		if (ca)rev.push_back(ca);
		sz = rev.size();
		for (int i = sz - 1; i >= 0; i--) {
			ret.push_back(rev[i]);
		}
		return ret;
	}
};