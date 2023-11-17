#include <iostream>
#include <string>
using namespace std;

void calculatePrefixFunction(const string& s,int* arr) {
	// Let A[i]=k denote the longest prefix that s[0...(k-1)] = s[i-(k-1)...i] => pre(0,k)=suf(i,k)
	// Initial condition s[0]=0;
	// For A[i+1]:
	// -> If s[A[i]]=s[i+1], then A[i+1]=A[i]+1
	// -> Otherwise, find the second longest prefix that s[0...(p-1)] = s[i-(p-1)...i] => pre(0,p)=suf(i,p)
	// -> -> Longest: s[0...(A[i]-1)] == s[i-(A[i]-1)...i]
	// -> -> Target: s[0...(j-1)] == s[i-(j-1)...i] , subject to j < A[i]
	// -> -> The left part of target equals to the prefix of substring s[0...(A[i]-1)], 
	// -> -> The right part of the target equals to the suffix of substring s[i-(A[i]-1)...i] => the suffix of s[0...(A[i]-1)]
	// -> The second longest candidate should be j=A[A[i]-1] => compare s[j]=s[i+1]; If true, A[i+1]=j+1

	arr[0] = 0;
	int sL = static_cast<int>(s.size());
	for (int i = 0; i < sL-1; i++) {
		int j = arr[i];
		while (j > 0 && s[j] != s[i + 1]) {
			j = arr[j - 1];
		}
		if (s[j] == s[i + 1]) {
			j++;
		}
		arr[i + 1] = j;
	}
	return;
}


int main() {
	int arr[1000];
	string s;
	while (true) {
		cin >> s;
		calculatePrefixFunction(s, arr);
		for (int i = 0; i < s.length(); i++) {
			cout << arr[i] << ",";
		}
		cout << endl;
	}
	return 0;
}