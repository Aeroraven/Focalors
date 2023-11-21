class Solution {
public:
	string convert(string s, int numRows) {
		if (numRows == 0) return s;
		if (numRows == 1)return s;
		string* w = new string[numRows];
		string ret;
		int slen = s.length(), pos;
		for (int i = 0, j = 0; i < slen; i++) {
			pos = (j < numRows) ? j : (2 * numRows - j - 2);
			w[pos] += s[i];
			if (j == 2 * numRows - 2) j = 0;
			j++;
		}
		for (int i = 0; i < numRows; i++) {
			ret += w[i];
		}
		delete[] w;
		return ret;
	}
};