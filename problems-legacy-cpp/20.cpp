class Solution {
public:
	bool isValid(string s) {
		stack<int> bracketStack;
		int strLength = s.length();
		for (int i = 0; i < strLength; i++) {
			if (s[i] == '(') {
				bracketStack.push(1);
			}
			if (s[i] == '{') {
				bracketStack.push(2);
			}
			if (s[i] == '[') {
				bracketStack.push(3);
			}
			if (s[i] == ')' && bracketStack.empty()) {
				return false;
			}
			if (s[i] == ']' && bracketStack.empty()) {
				return false;
			}
			if (s[i] == '}' && bracketStack.empty()) {
				return false;
			}
			if (s[i] == ')' && bracketStack.top() != 1) {
				return false;
			}
			if (s[i] == ')' && bracketStack.top() == 1) {
				bracketStack.pop();
			}
			if (s[i] == '}' && bracketStack.top() != 2) {
				return false;
			}
			if (s[i] == '}' && bracketStack.top() == 2) {
				bracketStack.pop();
			}
			if (s[i] == ']' && bracketStack.top() != 3) {
				return false;
			}
			if (s[i] == ']' && bracketStack.top() == 3) {
				bracketStack.pop();
			}
		}
		if (bracketStack.empty()) {
			return true;
		}
		else {
			return false;
		}

	}
};