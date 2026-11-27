#include <bits/stdc++.h>
using namespace std;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);

	string s;
	cin >> s;

	char t = '?';
	string ans = "";
	stack<char> st;
	for (char i : s) {
		if (i >= 'A' && i <= 'Z') {
			ans += i;
		}
		else {
			if (!st.empty()) {
				if (i == '+' || i == '-') {
					while (!st.empty() && st.top() != '(') {
						t = st.top();
						st.pop();
						ans += t;
					}
				}
				else if (i == '*' || i == '/') {
					while (!st.empty() && st.top() != '(') {
						t = st.top();
						st.pop();
						if (t == '+' || t == '-') {
							st.push(t);  break;
						}
						ans += t;
					}
				}
				else if (i == ')') {
					while (!st.empty() && st.top() != '(') {
						t = st.top();
						st.pop();
						ans += t;
					}
					if (!st.empty() && st.top() == '(') st.pop();
				}
				
			}
			if (i != ')') st.push(i);
		}
	}
	while (!st.empty()) {
		if (st.top() != ')' && st.top() != '(')
		ans += st.top();
		st.pop();
	}

	cout << ans;
}