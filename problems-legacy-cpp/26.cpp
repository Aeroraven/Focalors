class Solution {
public:
	int removeDuplicates(vector<int>& nums) {
		int arraySize = nums.size(), lastElement, pos = 1;
		if (arraySize == 0)return 0;
		lastElement = nums[0];
		for (int i = 1; i < arraySize; i++) {
			if (nums[i] != lastElement) {
				nums[pos++] = nums[i];
				lastElement = nums[i];
			}
		}
		return pos;
	}
};