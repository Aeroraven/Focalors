#include<iostream>
#include<vector>
#include<algorithm>
#include<cstdlib>
#include<ctime>
using namespace std;

int main() {
	int n = 1000;
	while (true) {
		cin >> n;
		vector<int> a;
		srand(time(NULL));
		for (int i = 0; i < n; i++) {
			a.push_back(rand() % 20000);
		}
		std::sort(a.begin(), a.end());
		for (int i = 0; i < n; i++) {
			cout << a[i];
			if (i != n - 1) {
				cout << ",";
			}
		}
	}
	
	return 0;
}
