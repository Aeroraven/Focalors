#include <iostream>
#include <cstring>
#include <vector>
#include <queue>
using namespace std;

int longestIncreasingPath(vector<vector<int>> a) {
	int rL = static_cast<int>(a.size());
	int cL = static_cast<int>(a[0].size());
	int* vd = new int[rL * cL];
	int* vf = new int[rL * cL];
	memset(vd, 0, sizeof(int) * rL * cL);
	auto deg = [cL, &vd](int x, int y) {
		return &vd[x * cL + y];
		};
	queue<int> plist;
	int ans = -1;
	for (int i = 0; i < rL; i++) {
		for (int j = 0; j < cL; j++) {
			if (i > 0 && a[i][j] > a[i - 1][j]) (*deg(i, j))++;
			if (i < rL - 1 && a[i][j] > a[i + 1][j]) (*deg(i, j))++;
			if (j > 0 && a[i][j] > a[i][j - 1]) (*deg(i, j))++;
			if (j<cL - 1 && a[i][j]>a[i][j + 1]) (*deg(i, j))++;
			if ((*deg(i, j)) == 0) {
				plist.push(i * cL + j);
			}
		}
	}
	while (!plist.empty()) {
		int front = plist.front();
		plist.pop();
		int c = front % cL, r = front / cL;
		int dx[4] = { r - 1,r + 1,r,r };
		int dy[4] = { c,c,c - 1,c + 1 };
		vf[front] = 0;
		for (int i = 0; i < 4; i++) {
			if (dx[i] >= 0 && dx[i] < rL && dy[i] >= 0 && dy[i] < cL) {
				if (a[r][c] > a[dx[i]][dy[i]]) {
					vf[front] = max(vf[front], vf[dx[i] * cL + dy[i]]);
				}
				if (a[dx[i]][dy[i]] > a[r][c]) {
					auto& d = *deg(dx[i], dy[i]);
					d--;
					if (d == 0) {
						plist.push(dx[i] * cL + dy[i]);
					}
				}
			}
		}
		vf[front]++;
		ans = max(ans, vf[front]);
	}
	delete[] vf;
	delete[] vd;
	return ans;
}

int main() {
	vector<vector<int>> p = { {1} };
	cout << longestIncreasingPath(p) << endl;
	return 0;
}