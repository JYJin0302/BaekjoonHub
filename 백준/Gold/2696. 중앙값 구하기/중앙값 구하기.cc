#include <bits/stdc++.h>
using namespace std;

int main() {
ios::sync_with_stdio(false);
cin.tie(nullptr);	
	int t;
	cin >> t;
	while (t--) {

		int n;
		cin >> n;

		vector<int>A(n);
		for (auto& i : A) cin >> i;

		int size = (n + 1) / 2;
		cout << size << '\n';

		vector<int> ans(size);
		ans[0] = A[0];

		priority_queue<int> L;
		priority_queue<int, vector<int>, greater<int>> R;
		for (int i = 1; i < size; i++) {

			int a = min(A[i * 2 - 1], A[i * 2]);
			int b = max(A[i * 2 - 1], A[i * 2]);
			
			if (ans[i - 1] <= a && ans[i - 1] <= b) {
				L.push(ans[i - 1]);
				R.push(a);
				R.push(b);
				ans[i] = R.top();
				R.pop();
			}
			else if (ans[i - 1] > a && ans[i-1] <= b) {

				ans[i] = ans[i - 1];
				L.push(a);
				R.push(b);
			}
			else {
				R.push(ans[i - 1]);
				L.push(a);
				L.push(b);
				ans[i] = L.top();
				L.pop();
			}
		}

		for (int i = 0; i < size; i++) {
			cout << ans[i] << ' ';
			if (i % 10 == 9 && i != size - 1) cout << '\n';
		}
		cout << '\n';
	}
}