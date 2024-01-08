class Solution {
public:
	int maxProfit(vector<int>& prices) {
		if (prices.size() == 0)return 0;
		int sz = prices.size();
		int* f = new int[sz];
		int ans = 0, minVal = 0, hasMinVal = 0;
		for (int i = 0; i < sz; i++) {
			if (hasMinVal == 0) {
				hasMinVal = 1;
				minVal = prices[i];
			}
			else {
				minVal = (minVal > prices[i]) ? prices[i] : minVal;
				ans = ((prices[i] - minVal) > ans) ? (prices[i] - minVal) : ans;
			}
		}
		return ans;
	}
};