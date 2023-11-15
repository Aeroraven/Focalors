#include <iostream>
#include <vector>
#include <memory>
using namespace std;

#define lb(x) ((x)&(-(x)))

// Just use Binary Indexed Trees, nothing further can be explained 

vector<int> findAnswer(vector<int>& nums){
	int nL = static_cast<int>(nums.size());
	int minval = INT_MAX, maxval = ~INT_MAX;
	for (int i = 0; i < nL; i++) {
		minval = min(nums[i], minval);
		maxval = max(nums[i], maxval);
	}
	minval -= 1;
	int its = 0, mx = (maxval - minval), last = 0;
	while (mx) {
		last = mx;
		mx -= lb(mx);
		its++;
	}
	int maxNode = (last << (its > 1));

	unique_ptr<int[]> a = make_unique<int[]>(maxNode + 1);
	vector<int> ret(nL);
	for (int i = nL-1; i >= 0; i--) {
		int v = nums[i] - minval ;
		while (v <= maxNode) {
			a[v] += 1;
			v += lb(v);
		}

		v = nums[i] - 1 - minval;
		int ans = 0;
		while (v) {
			ans += a[v];
			v -= lb(v);
		}
		ret[i] = ans;
	}
	
	return ret;	
}

int main() {
	vector<int> ls;
	int n;
	cin >> n;
	for (int i = 0; i < n; i++) {
		int x;
		cin >> x;
		ls.push_back(x);
	}
	auto w = findAnswer(ls);
	for (const auto& p : w) {
		cout << p << ",";
	}
	cout << endl;
	return 0;
}