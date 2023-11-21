class Solution {
public:
	int searchInsert(vector<int>& nums, int target) {
		int sz = nums.size();
		for (int i = 0; i < sz; i++) {
			if (nums[i] == target) {
				return i;
			}
		}
		if (target < nums[0]) {
			return 0;
		}
		if (target > nums[sz - 1]) {
			return sz;
		}
		int l = 0, r = sz - 1, mid;
		while (l < r) {
			mid = (l + r) / 2;
			if (nums[mid]<target && nums[mid + 1]>target) {
				return mid + 1;
			}
			if (nums[mid + 1] < target) {
				l = mid + 1;
			}
			if (nums[mid] > target) {
				r = mid;
			}
		}
		mid = (l + r) / 2;
		return mid + 1;
	}
};