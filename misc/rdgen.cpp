#include<iostream>
#include<vector>
#include<algorithm>
#include<cstdlib>
#include<ctime>
#include<map>
#include<set>
using namespace std;

int main() {
	/*
	map<int,int> w;
	for (int i = 0; i < 15; i++) {
		w.insert(abs(7 - i)*12,i);
	}
	for (auto [i,j] : w) {
		cout << i << "-" << j << ",";
	}
	cout << endl;
	auto a1 = w.lower_bound(0);
	cout << (*a1). << endl;
	auto a2 = w.upper_bound(0);
	cout << *a2 << endl;*/

	cout << 2 + (2 & (-2)) << endl;
	int n = 1000;
	while (true) {
		cin >> n;
		vector<int> a;
		srand(time(NULL));
		for (int i = 0; i < n; i++) {
			a.push_back(rand() % 2);
		}
		int c = 0;
		for (int k = 0; k < n; k++) {
			int w = 0x7fffffff - rand() % 5;
			w = rand()%8000+1;
			if (rand() % 16 == 0) {
				w = w;
			}
			//cout << w;
			
			cout << "[" << rand() % (w * 2) + 1 << "," << rand()%(w*2) + 1 << "]";
			c += w;
			if (k != n - 1) {
				cout << ",";
			}
		}
		/*
		for (int k = 0; k < n; k++) {
			cout << rand() % 150 + 1 << ",";
		}
		cout << endl;*/
		continue;
		//std::sort(a.begin(), a.end());
		for (int k = 0; k < n; k++) {
			cout << "[";
			for (int i = 0; i < n; i++) {
				int w = rand() % 16;
				if (rand()%2 == 0) {
					w = w;
				}
				cout << "" << w << "";
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
