#include <bits/stdc++.h>
using namespace std;
using ll = long long;

void solve() {

	int n;
	cin >> n;

	if (n % 2 == 0) {
		cout << "NO\n";
		return;
	}

	cout << "YES\n";

	vector<int> ans(n);
	int num = 1;
	for (int i = 0; i < n; i += 2) {
		ans[i] = num;
		num++;
	}
	for (int i = 1; i < n; i += 2) {
		ans[i] = num;
		num++;
	}


	int mn = n * 2 - n / 2 + 1;
	for (int i = 0; i < n; i++) {
		cout << ans[i] << ' ' << mn - ans[i] << '\n';
		mn++;
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