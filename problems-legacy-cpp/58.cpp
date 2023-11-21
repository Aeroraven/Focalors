class Solution {
public:
	int lengthOfLastWord(string s) {
		int sz = s.size(), cnt = 0;
		if (!sz || s.empty()) {
			return 0;
		}
		for (int i = sz - 1; i >= 0; i--) {
			if (s[i] != ' ') {
				cnt++;
			}
			if (s[i] == ' ' && cnt != 0) {
				return cnt;
			}

		}
		return cnt;
	}
};