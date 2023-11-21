class Solution {
public:
	int removeElement(vector<int>& nums, int val) {
		int cur = 0, pos = 0, vecSize = nums.size(), rmCnt = 0;
		for (int i = 0; i < vecSize; i++) {
			if (nums[cur] != val) {
				nums[pos] = nums[cur];
				cur++;
				pos++;
			}
			else {
				cur++;
				rmCnt++;
			}
		}
		return pos;
	}
};