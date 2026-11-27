#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using ld = long double;

#define mp make_pair
#define x first
#define y second
#define all(x) x.begin(), x.end()

void solve() {
	int n;
	cin >> n;

	vector<int> num = {1};
	int tot = 1;
	for (int i = 1;; i++) {
		tot += i * 6 - (i * 2 - 1);
		num.push_back(tot);
		if (tot >= n) break;
	}

	if (n > 146858) {
		// try 1
		map<int, bool> chk;
		for (auto f : num) chk[f] = 1;

		if (chk[n]) {
			cout << 1 << '\n';
			return;
		}

		for (auto f : num) {
			if (chk[n - f]) {
				cout << 2 << '\n';
				return;
			}
		}
		cout << 3 << '\n';
		return;
	}

	vector<int> dp(n + 1, n + 10);
	dp[0] = 0;
	for (auto f : num) {
		for (int j = f; j <= n; j++) { dp[j] = min(dp[j], dp[j - f] + 1); }
	}
	cout << dp[n] << '\n';
}

int main() {
	std::ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	int t = 1;
	// cin >> t;
	while (t--) { solve(); }
	return 0;
}