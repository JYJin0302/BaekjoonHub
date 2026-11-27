#include <bits/stdc++.h>
using namespace std;


int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);

	int n;
	cin >> n;

	vector<int> A(n);
	for (auto& i : A) cin >> i;

	stack<int> st;  // 인덱스 저장

	for (int i = 0; i < n; i++) {
		if (st.empty()) {
			st.push(i);
			cout << "0 ";
		}
		else if (A[st.top()] < A[i]) {
			while (!st.empty() && A[st.top()] < A[i]) st.pop();
			
			if (st.empty()) cout << "0 ";
			else cout << st.top()+1 << ' ';
			st.push(i);
		}
		else {
			cout << st.top()+1 << ' ';
			st.push(i);
		}
	}
}