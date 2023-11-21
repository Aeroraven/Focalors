class Solution {
public:
	vector<int> twoSum(vector<int>& nums, int target) {
		map<int, int> x;
		set<int> y;
		vector<int> ret;
		int l = nums.size();
		for (int i = 0; i < l; i++) {
			if (y.count(target - nums[i])) {
				ret.push_back(x[target - nums[i]]);
				ret.push_back(i);
				return ret;
			}
			y.insert(nums[i]);
			x[nums[i]] = i;
		}
		return ret;
	}
};