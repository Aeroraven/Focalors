class Solution {
public:
	string countAndSay(int n) {
		int cnt = 0, th = 0, sz;
		string ex = "1", nw = "";
		for (int i = 2; i <= n; i++) {
			sz = ex.size();
			th = (int)(ex[0] - '0');
			for (int i = 0; i < sz; i++) {
				if (ex[i] == (th + '0')) {
					cnt++;
				}
				else {
					nw += (cnt + '0');
					nw += (th + '0');
					th = (int)(ex[i] - '0');
					cnt = 1;
				}
			}
			nw += (cnt + '0');
			nw += (th + '0');
			cnt = 0;
			th = 0;
			ex = nw;
			nw = "";
		}
		return ex;
	}
};