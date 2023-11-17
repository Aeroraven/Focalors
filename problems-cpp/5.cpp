#include <iostream>
#include <string>
using namespace std;



string manacher(const string& p) {
	// Rearrange string p that s[2*i+1] = p[i], s[2*i] = PLACEHOLDER
	// Let d[i] denotes palindrome range at center i. Record the palindrome (l,r) that has the rightmost boundary
	// Consider i < r
	// Then the mirrored position of i will be (j+i)=(l+r) => j = l+r-i
	// The initial value of d[i] should be in range of palindrome (l,r), so i+(d[i]-1)<=r = > d[i] <= r+1-i
	// Thus init d[i] = min(d[l+r-i],r-i+1)
	// Then extend d[i] by checking s[i+d[i]-1] and s[i-d[i]+1]

	int l = 0, r = -1;
	int sL = static_cast<int>(p.size());
	int* d = new int[2 * sL + 1];
	int bestPos = 0, bestLen = -1;
	for (int i = 0; i < 2 * sL + 1; i++) {
		int& k = d[i];
		
		k = (i > r) ? 1 : min(d[l + r - i], r - i + 1);
		while (true) {
			if (i - k >= 0 && i + k < 2 * sL + 1) {
				auto lc = (i - k) % 2 == 0 ? '\0' : p[(i - k - 1) / 2];
				auto rc = (i + k) % 2 == 0 ? '\0' : p[(i + k - 1) / 2];
				cout << "i=" << i << ",k=" << k << " comp:" << lc << "," << rc << endl;
				if (lc == rc) {
					k++;
					continue;
				}
			}
			break;
		}
		if (i + k - 1 > r) {
			l = i - (k - 1);
			r = i + (k - 1);
		}
		// For d[x] where x is odd, then the real palindrome length f[x] : f[x] = 1 + (range-1)*2 ; d[x] = range * 2
		// => f[x] = d[x] - 1
		// For d[x] where x is even, then the real palindrome length f[x] : f[x] = (range-1)*2; d[x] = 1 + (range-1)*2
		// => f[x] = d[x] - 1

		cout << "Pos" << i << " d=" << k << "Len=" << k - 1 << endl;
		if (k - 1 > bestLen) {
			bestPos = i;
			bestLen = k - 1;
			
		}

	}
	if (bestPos % 2 == 1) {
		int pos = (bestPos - 1) / 2;
		int rad = (d[bestPos] - 1) / 2;
		l = pos - rad;
		r = pos + rad;
		return p.substr(l, (r - l + 1));
	}
	else {
		// #a#b#b#a#
		int posr = bestPos / 2;
		int rad = (d[bestPos] - 1) / 2;
		r = posr + rad - 1;
		l = posr - rad;
		return p.substr(l, (r - l + 1));
	}
};


class Solution {
public:
	string longestPalindrome(string s) {
		return manacher(s);
	}
};

int main() {
	Solution x;
	while (true) {
		string w;
		cin >> w;
		cout << x.longestPalindrome(w) << endl;
	}
	return 1;
}