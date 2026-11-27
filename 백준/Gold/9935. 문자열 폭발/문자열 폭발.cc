#include <bits/stdc++.h>
using namespace std;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);

	string a, ex;
	cin >> a >> ex;
	reverse(ex.begin(), ex.end());

	int exSize = ex.size();

	stack<char> st;

	for (char i : a) {
		st.push(i);
		if (st.size() < exSize) continue;
		
		string temp = "";
		for (int i = 0; i < exSize; i++) {
			temp += st.top();
			st.pop();
		}
		if (temp != ex) {
			for (int i = 0; i < exSize; i++) {
				st.push(temp[exSize - 1 - i]);
			}
		}
	}

	string ans = "";
	while (!st.empty()) {
		ans += st.top();
		st.pop();
	}

	reverse(ans.begin(), ans.end());
	if (ans.size() == 0) cout << "FRULA";
	else cout << ans;
}