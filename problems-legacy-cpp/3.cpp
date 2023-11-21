class Solution {
public:
	int lengthOfLongestSubstring(string s) {
		int cnt[1000], seqStart = 0, seqEnd = 0, slen = s.length();
		int recStart = 0, recEnd = 0, recLen = 0;
		for (int i = 0; i < 1000; i++) cnt[i] = 0;
		for (; seqEnd < slen; seqEnd++) {
			cnt[s[seqEnd]]++;
			if (cnt[s[seqEnd]] >= 2) {
				while (1) {
					cnt[s[seqStart]]--;
					seqStart++;
					if (cnt[s[seqEnd]] < 2) {
						break;
					}
				}
			}
			if (seqEnd - seqStart + 1 > recLen) {
				recLen = seqEnd - seqStart + 1;
				recStart = seqStart;
				recEnd = seqEnd;
			}
		}
		return recLen;
	}
};