class Solution {
public:
	bool isPalindrome(int x) {
		if (x < 0)return false;
		string w;
		int a, b;
		while (x) {
			a = x % 10;
			x /= 10;
			w += (a + '0');
		}
		b = w.size();
		for (int i = 0; i < b; i++) {
			if (w[i] != w[b - i - 1])return false;
		}
		return true;
	}
};