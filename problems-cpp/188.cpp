#include <iostream>
#include <vector>
#include <cstring>

using namespace std;


int calcMax(vector<int>& p, int m) {
	constexpr static int NINF = -20000000;
	int pL = static_cast<int>(p.size());
	int* vf = new int[2 * pL];
	int* t = new int[pL];
	int* s = new int[pL];
	int* ms = new int[pL];
	auto f = [&](int x, int y)->int& {
		return vf[((x + 1) & 1) * pL + y];
	};
	memset(vf, 0, sizeof(int) * pL * 2);
	//f(i,j) = max{p[j]-p[s]+f(i-1,t)} subject to 
	//I. s<j
	//II. t<s

	int ans = 0;
	for (int i = 0; i < m; i++) {
		for (int j = 0; j < pL; j++) {
			f(i, j) = NINF;
			t[j] = f(i - 1, j);
			s[j] = -p[j];
			if (j - 1 >= 0) {
				t[j] = max(t[j - 1], f(i - 1, j));
				s[j] += t[j - 1];
			}
			ms[j] = s[j];
			if (j - 1 >= 0) {
				ms[j] = max(ms[j], ms[j - 1]);
			}
			if (j - 1 >= 0) {
				f(i, j) = p[j] + ms[j - 1];
			}
			ans = max(ans,f(i, j));
		}
	}
	return ans;
}

int main() {
	int n, m;
	int r;
	while (true) {
		cin >> n >> m;
		vector<int> w;
		for (int i = 0; i < n; i++) {
			cin >> r;
			w.push_back(r);
		}
		cout << calcMax(w, m) << endl;
	}
	return 0;
}
