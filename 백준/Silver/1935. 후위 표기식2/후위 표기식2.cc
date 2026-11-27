#include <bits/stdc++.h>
using namespace std;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);

	int n;
	cin >> n;
	string s;
	cin >> s;

	vector<int> A(26);
	for (int i = 0; i < n; i++) {
		cin >> A[i];
	}

	stack<double> st;
	for (char i : s) {
		if (i >= 'A' && i <= 'Z') st.push(A[i - 'A']);
		else {
			double a, b, temp;
			b = st.top(); st.pop();
			a = st.top(); st.pop();
			switch (i) {
			case '*':
				temp = a * b;
				break;
			case '-':
				temp = a - b;
				break;
			case '+':
				temp = a + b;
				break;
			case '/':
				temp = a / b;
				break;
			}
			st.push(temp);
		}
	}
	cout << fixed;
	cout.precision(2);
	cout << st.top();
}