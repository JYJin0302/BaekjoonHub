#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using ld = long double;

#define mp make_pair
#define x first
#define y second
#define all(x) x.begin(), x.end()

int G[2020][2020];

void solve() {
	int n, k;
	cin >> n >> k;

	for (int i = 0; i < n; i++) {
		for (int j = 0; j < k; j++) { cin >> G[i][j]; }
	}

	vector<bool> ans(n);
	for (int j = 0; j < k; j++) {
		int mx = -1, cnt = 0, ix = -1;
		for (int i = 0; i < n; i++) {
			if (mx < G[i][j]) {
				mx = G[i][j];
				cnt = 1;
				ix = i;
			} else if (mx == G[i][j]) cnt++;
		}

		if (cnt == 1) { ans[ix] = 1; }
	}

	int res = 0;
	for (int i = 0; i < n; i++) res += ans[i];
	cout << res << '\n';
}

int main() {
	std::ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	int t = 1;
	// cin >> t;
	for (int i = 1; i <= t; i++) { solve(); }
	return 0;
}