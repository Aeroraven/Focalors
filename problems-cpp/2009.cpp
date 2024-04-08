#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

class Solution {
public:
	int minOperations(vector<int>& a) {
		sort(a.begin(), a.end());
		int n = a.size();
		int ans = n;
		int r = 0;
		int duplicates = 0;
		for (int i = 0; i < n; i++) {
			int limit = a[i] + n - 1;
			while (r < n && a[r] <= limit) {
				if (r != 0 && a[r] == a[r - 1])duplicates++;
				r++;
			}
			ans = min(ans, n - (r - i) + duplicates);
			if (i != 0 && a[i] == a[i - 1])duplicates--;
		}
		return ans;
	}
};
int main() {
	Solution s;
	vector<int> a = { 8,5,9,9,8,4 };
	cout << s.minOperations(a);
	return 0;
}