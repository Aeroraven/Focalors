class Solution {
public:
	int evalRPN(vector<string>& tokens) {
		int sz = tokens.size();
		int ret = 0;
		stack<int> s;
		for (int i = 0; i < sz; i++) {
			if (tokens[i] != "*" && tokens[i] != "/" && tokens[i] != "+" && tokens[i] != "-") {
				s.push(stoi(tokens[i]));
			}
			else {
				int m, n;
				m = s.top(); s.pop();
				n = s.top(); s.pop();
				switch (tokens[i][0]) {
				case '+':
					s.push(m + n);
					break;
				case '-':
					s.push(n - m);
					break;
				case '*':
					s.push(m * n);
					break;
				case '/':
					s.push(n / m);
					break;
				}
			}
		}
		if (s.size()) {
			ret = s.top();
		}
		return ret;
	}
};