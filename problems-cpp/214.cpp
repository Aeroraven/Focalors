#include <iostream>
using namespace std;

// First time of MLE, 
// Just because of  STRING concat
// I think I should learn STL.
// TAT

template<typename T>
T exgcd(T a, T b, T& x, T& y) {
	// exgcd solves equation: ax+by=gcd(a,b)
	// gcd(a,b) = gcd(b,a%b). if the argument b in one function call is 0, then gcd(a,b)=a
	// That is, gcd(a,b) = gcd(b1,a1%b1) = a0*1+b0*0;
	// By backtracking, we have: gcd(a[k],b[k]) = gcd(b[k],a[k]%b[k]) = gcd(a[k-1],b[k-1]) 
	// 
	// Therefore, p[k]*a[k] + q[k]*b[k] = p[k-1]*a[k-1] + q[k-1]*b[k-1] = gcd(a[n],b[n])
	// Subject to
	// I. a[k-1] = b[k]
	// II.b[k-1] = (a[k]%b[k]) = (a[k]-int(a[k]/b[k])*b[k])
	// => p[k]*a[k] + q[k]*b[k] = p[k-1]*b[k] + q[k-1]*a[k] - q[k-1]*int(a[k]/b[k])*b[k]
	// => p[k]*a[k] + q[k]*b[k] = q[k-1]*a[k] + (p[k-1]-q[k-1]*int(a[k]/b[k]))*b[k]
	// 
	// Finally. p[k] = q[k-1], q[k] = p[k-1]-q[k-1]*int(a[k]/b[k])
	// Subject to the initial condition, p[k]=1, q[k]=0

	if (b == 0) {
		x = 1, y = 0;
		return a;
	}
	T xl, yl;
	T gcd = exgcd(b, a % b, xl, yl);
	x = yl;
	y = xl - yl * (a / b);
	return gcd;
}
template<typename T>
T getInverse(T a, T n) {
	// solve b, subject to ab=1(mod n), 
	// Using exgcd, => ax+ny=gcd(a,n)=1 solved
	// Thus ax+ny=1 (mod n) => ax=1 (mod n)
	T x, y;
	int gcd = exgcd(a, n, x, y);
	x = (x + n) % n;
	return x;
}

using Int = long long;
constexpr static Int MOD_FACTOR = 23143;
constexpr static Int BASE = 31;


void calculateBasePowers(Int* basePower, int n) {
	basePower[0] = 1;
	for (int i = 1; i < n; i++) {
		basePower[i] = (basePower[i - 1] * BASE) % MOD_FACTOR;
	}
}


class RollingMapping {
public:
	// Build a hash map that:
	// H(s) = (a[0]*b^0+a[1]*b^1+...+a[p]*b^p)%m
	// 
	// To remove the last character in sequence, follow operation can be performed
	// H(s[:-1]) = (H(s)-a[p]*b^p%m+m)%m;
	//
	// To perform the shift operation, follow operation can be performed
	// H(s[0]+shift(s)) = H(s) 
	// H(PLACEHOLDER+shift(s)) = H(s)-a[0]*b^0
	// H(shift(s)) = (H(s)-a[0]*b^0)*b^(-1) (mod m)


	Int currentValue = 0;
	Int inverseMod = 0;
	Int* basePower = nullptr;
	int n = 0;

	RollingMapping(Int* basePower) {
		inverseMod = 14931; //getInverse(BASE, MOD_FACTOR);
		this->basePower = basePower;
	}
	void removeRightmostChar(char x) {
		currentValue = (currentValue - (static_cast<Int>(x - 'a' + 1) * basePower[n-1])% MOD_FACTOR + MOD_FACTOR) % MOD_FACTOR;
		n = n - 1;
	}
	void addToRightmostPosition(char x) {
		n = n + 1;
		currentValue = (currentValue + (static_cast<Int>(x - 'a' + 1) * basePower[n-1])%MOD_FACTOR + MOD_FACTOR) % MOD_FACTOR;
	}
	void shiftOperation(char leftmost) {
		currentValue = (currentValue - static_cast<Int>(leftmost - 'a' + 1) + MOD_FACTOR) % MOD_FACTOR;
		currentValue = (currentValue * inverseMod) % MOD_FACTOR;
		n = n - 1;
	}
	Int getCurrentMapping() {
		return currentValue;
	}
};

string getReversedString(string s,int l,int r) {
	string ret = "";
	for (int i = r; i >= l; i--) {
		ret += s[i];
	}
	return ret;
}

class Solution {
public:
	string shortestPalindrome(string s) {
		if (s.size() == 0) {
			return "";
		}
		Int* basePower = nullptr;

		basePower = new Int[s.size()];
		calculateBasePowers(basePower,s.size());
		int sL = s.size();
		RollingMapping leftPart(basePower), mirroredPart(basePower);
		int mirrorL = sL - 1, mirrorR = sL - 1, leftL = 0, leftR = 0;
		// Initialize the hash mapping
		for (; leftR < mirrorL; leftR++,mirrorL--) {
			leftPart.addToRightmostPosition(s[leftR]);
			mirroredPart.addToRightmostPosition(s[mirrorL]);
		}
		leftR--, mirrorL++;
		// Shift the hash mapping to get the optimal answer
		int divPointOrg = sL;
		for (; divPointOrg > 1; divPointOrg--) {
			// First, compare two hash values
			if (leftPart.getCurrentMapping() == mirroredPart.getCurrentMapping()) {
				bool flag = true;
				for (int i = leftL, j = mirrorR; i <= leftR && j >= mirrorL; i++, j--) {
					if (s[i] != s[j]) {
						flag = false;
						break;
					}
				}
				if (flag) {
					break;
				}
			}
			// Update the hash mapping for the next division point
			if (divPointOrg % 2 == 0) {
				// When the index is even, 
				// First, remove the rightmost character in the left part
				leftPart.removeRightmostChar(s[leftR]);
				leftR--;

				// Second, perform a shift operation in the mirrored part
				mirroredPart.shiftOperation(s[mirrorR]);
				mirrorR--;
				
			}
			else {
				// When the index is odd
				// Left part should left unchanged
				// And for the right part, first add a new character to the rightmost position
				mirrorL--;
				mirroredPart.addToRightmostPosition(s[mirrorL]);
				
				// Second, perform a shift operation in the mirrored part
				mirroredPart.shiftOperation(s[mirrorR]);
				mirrorR--;
			}
		}
		// Construct the answer using the optimal `mirrorR` found
		string answer = s.substr(mirrorR + 1, sL - (mirrorR + 1) + 1);
		reverse(answer.begin(), answer.end());
		delete[] basePower;
		return answer+s;
	}
};



int main() {
	cout << (31ll * getInverse(31ll, MOD_FACTOR)) % MOD_FACTOR << endl;
	cout << getInverse(31ll, MOD_FACTOR) << endl;
	Solution s;
	string w;
	cin >> w;
	cout << s.shortestPalindrome(w) << endl;
	while(true){}
	return 0;
}

// aaaaaababaaaaaaaaabababababacccabababa

// abababaccc   ababababab  aaaaaaaaababaaaaaababaaaaaaaaa  bababababa   cccabababa

// abababaccc   ababababab      aaaaaaaaab a baaaaaaaaa     bababababa    cccabababa


//baaaaaaaaabababababacccabababa

//abababacccabababababaaaaaaaaababaaaaaaaaabababababacccabababa
//abababacccabababababaaaaaaaaababaaaaaaaaabababababacccabababa