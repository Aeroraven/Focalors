class Solution {
public:
	string addBinary(string a, string b) {
		string ar = "", br = "", ret = "", ans = "";
		int al = a.size();
		int bl = b.size();
		for (int i = al - 1; i >= 0; i--) {
			ar += a[i];
		}
		for (int i = bl - 1; i >= 0; i--) {
			br += b[i];
		}
		int msz = (al > bl) ? al : bl;
		int at = 0, bt = 0, tt = 0, ca = 0;
		for (int i = 0; i <= msz; i++) {
			if (i < al) {
				at = (int)(ar[i] - '0');
			}
			else {
				at = 0;
			}
			if (i < bl) {
				bt = (int)(br[i] - '0');
			}
			else {
				bt = 0;
			}
			tt = at + bt + ca;
			if (tt >= 2) {
				tt -= 2;
				ca = 1;
			}
			else {
				ca = 0;
			}
			ret += (tt + '0');
		}
		int bg = 0;
		for (int i = msz; i >= 0; i--) {
			if (ret[i] != '0' || i == 0)bg = 1;
			if (bg) {
				ans += ret[i];
			}
		}
		return ans;
	}
};