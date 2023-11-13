#include<iostream>
#include<vector>
#include<algorithm>
#include<cstdlib>
#include<ctime>
using namespace std;

int main() {
	cout << (~0x7fffffff) << endl;
	int p = 0;
	cin >> p;
	while (p) {
		cout << (p & (p - 1)) << endl;
		p = (p & (p - 1));
	}
	return 0;

	int n = 1000;
	while (true) {
		cin >> n;
		vector<int> a;
		srand(time(NULL));
		for (int i = 0; i < n; i++) {
			a.push_back(rand() % 2);
		}
		//std::sort(a.begin(), a.end());
		for (int k = 0; k < n; k++) {
			cout << "[";
			for (int i = 0; i < n; i++) {
				int w = rand() % 2;
				if (w == 0) {
					w = rand() % 2;
				}
				cout << "\"" << w << "\"";
				if (i != n - 1) {
					cout << ",";
				}
			}
			cout << "]";
			if (k != n - 1) {
				cout << ",";
			}
		}
	}
	
	return 0;
}
