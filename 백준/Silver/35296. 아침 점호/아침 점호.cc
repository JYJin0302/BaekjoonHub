#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using ld = long double;

#define mp make_pair
#define x first
#define y second
#define all(x) x.begin(), x.end()

int n, m;
char G[101][101];

void solve() {
	cin >> n >> m;

	if (n == 1) swap(n, m);

	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) { cin >> G[i][j]; }
	}



	vector<pair<int, int>> ans;
	for (int j = 0; j < m; j++) {
		for (int i = 0; i < n; i++) {
			if (G[i][j] == 'X') {
				int ix = j * n + i + 1;
				if (i != n - 1 && G[i + 1][j] == 'X') {
					ans.push_back(mp(ix, ix + 1));
					i++;
				} else {
					ans.push_back(mp(ix, ix));
				}
			}
		}
	}

	cout << (int)ans.size() << '\n';
	for (auto [a, b] : ans) {
		if (a == b) cout << 1 << ' ' << a << '\n';
		else cout << 2 << ' ' << a << ' ' << b << '\n';
	}
}

int main() {
	std::ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	int t = 1;
	// cin >> t;
	for (int i = 1; i <= t; i++) { solve(); }
	return 0;
}