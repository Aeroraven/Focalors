class Solution {
public:
	int maxSubArray(vector<int>& nums) {
		int x = 0, sz = nums.size();
		int ans = nums[0], pre = nums[0], cur = 0;
		for (int i = 1; i < sz; i++) {
			if (pre > 0) {
				cur = pre + nums[i];
			}
			else {
				cur = nums[i];
			}
			if (cur > ans)ans = cur;
			pre = cur;
		}
		return ans;
	}
};