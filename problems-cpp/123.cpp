#include <iostream>
#include <vector>
#include <cstring>
#include <cstdlib>
#include <algorithm>
using namespace std;


int calcMax(vector<int>& p) {
	int pL = static_cast<int>(p.size());
	int* f = new int[pL];
	int* g = new int[pL];
	int* minv = new int[pL];
	int* maxv = new int[pL];
	int* s = new int[pL];

	int ans = 0;
	f[0] = 0;
	for (int i = 0; i < pL; i++) {
		minv[i] = p[i];
		if (i > 0) {
			minv[i] = min(minv[i - 1], minv[i]);
			f[i] = max(0, p[i] - minv[i - 1]);
			ans = max(ans, f[i]);
		}
	}

	//G[i] = max{ p[i] - p[j] + f[k] } subject to
	//I. j<i
	//II. k<j
	for (int i = 0; i < pL; i++) {
		maxv[i] = f[i];
		if (i - 1 >= 0) {
			maxv[i] = max(maxv[i], maxv[i - 1]);
		}
	}
	for (int i = 0; i < pL; i++) {
		minv[i] = -p[i];
		
		if (i - 1 >= 0) {
			minv[i] += maxv[i - 1];
			g[i] = max(0,p[i] + s[i - 1]);
			ans = max(ans, g[i]);
		}
		s[i] = minv[i];
		if (i - 1 >= 0) {
			s[i] = max(s[i - 1], s[i]);
		}
	}
	delete[] f;
	delete[] g;
	delete[] s;
	delete[] minv;
	delete[] maxv;
	return ans;
}

int main() {
	int n;
	int r;
	while (true) {
		cin >> n;
		vector<int> w;
		for (int i = 0; i < n; i++) {
			cin >> r;
			w.push_back(r);
		}
		cout << calcMax(w) << endl;
	}
	return 0;
}