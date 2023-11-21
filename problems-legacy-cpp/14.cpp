class Solution {
public:
	string longestCommonPrefix(vector<string>& strs) {
		int minSize = 0, vectorSize = strs.size(), curSize;
		if (vectorSize == 0) {
			string nullRet = "";
			return nullRet;
		}
		minSize = strs[0].size();
		for (int i = 1; i < vectorSize; i++) {
			curSize = strs[i].size();
			if (minSize > curSize) {
				minSize = curSize;
			}
		}
		int lcpLen = 0, validFlag = 1;
		for (int i = 0; i < minSize; i++) {
			for (int j = 1; j < vectorSize; j++) {
				if (strs[j][i] != strs[0][i]) {
					validFlag = 0;
				}
			}
			if (validFlag == 1) {
				lcpLen++;
			}
			else {
				break;
			}
		}
		string ret = "";
		for (int i = 0; i < lcpLen; i++) {
			ret += strs[0][i];
		}
		return ret;
	}
};