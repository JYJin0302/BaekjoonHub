#include <bits/stdc++.h>
using namespace std;

int main() {
	int n, k;
	cin >> n >> k;

	string s;
	cin >> s;

	stack<char> st;

	int cnt = 0;
	for (char i : s) {
		if (st.empty() || st.top() >= i || cnt == k) {
			st.push(i);
		}
		else {
			while (!st.empty() && st.top() < i && cnt < k) {
				cnt++;
				st.pop();
			}
			st.push(i);
		}
	}
	while (cnt < k) {
		cnt++;
		st.pop();
	}

	vector<char> ans;
	while (!st.empty()) {
		ans.push_back(st.top());
		st.pop();
	}
	for (auto it = ans.rbegin(); it != ans.rend(); it++) {
		cout << *it;
	}

}