#include <bits/stdc++.h>
using namespace std;
using ll = long long;


void solve() {

	int m, q, n;
	cin >> m >> n >> q;

	vector<int> A(n), ans(n);
	for (auto& i : A) cin >> i;


	for (int i = 0; i < m; i++) {
		cout << "? " << i + 1 << ' ' << i + 1 << endl;
		int x;
		cin >> x;

		ans[i] = x % A[i] + 1;
	}
	for (int i = m; i < n; i++) ans[i] = A[i];

	cout << "! ";
	for (auto i : ans) cout << i << ' ';
	cout << endl;
}

int main() {

	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.flush();

	int t = 1;
	//cin >> t;
	while (t--) {
		solve();
	}

}