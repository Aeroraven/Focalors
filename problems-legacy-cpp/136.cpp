class Solution {
public:
	int singleNumber(vector<int>& nums) {
		int r = 0, sz = nums.size();
		for (int i = 0; i < sz; i++) {
			r ^= nums[i];
		}
		return r;
	}
};