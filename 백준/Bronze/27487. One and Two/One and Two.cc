#include <bits/stdc++.h>
using namespace std;

void solve() {

	int n;
	cin >> n;

	vector<int> A(n);
	for (auto& i : A) cin >> i;
	int cnt = 0;
	for (auto i : A) cnt += (i == 2);

	if (cnt % 2 == 1) {
		cout << "-1\n";
		return;
	}

	int tt = 0;
	for (int i = 0; i < n; i++) {
		tt += (A[i] == 2);
		if (tt == cnt / 2) {
			cout << i + 1 << '\n';
			return;
		}
	}

}

int main() {

	ios::sync_with_stdio(false);
	cin.tie(0);

	int t = 1;
	cin >> t;
	while (t--) {
		solve();
	}
}