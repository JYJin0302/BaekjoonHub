#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using ld = long double;

#define mp make_pair
#define x first
#define y second
#define all(x) x.begin(), x.end()

char G[1010][1010];

void solve() {
	int n, m;
	cin >> n >> m;

	memset(G, '.', sizeof G);
	if (n == 2 || m == 2 || (n + m) & 1) {
		cout << -1 << '\n';
		return;
	}

	cout << max(n, m) << '\n';

	int tn = min(n, m);
	for (int j = 0; j < tn - 3; j++) {
		G[j][j] = 'G';
		G[j][j + 1] = 'g';
	}
	G[tn - 1][tn - 2] = 'G';
	G[tn - 1][tn - 1] = 'g';
	G[tn - 2][tn - 3] = 'G';
	G[tn - 1][tn - 3] = 'g';
	G[tn - 3][tn - 1] = 'G';
	G[tn - 2][tn - 1] = 'g';

	if (n > m) {
		for (int j = m; j < n; j++) {
			G[j][0] = 'G';
			G[j][1] = 'g';
		}
	} else if (n < m) {
		for (int j = n; j < m; j++) {
			G[0][j] = 'G';
			G[1][j] = 'g';
		}
	}

	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) { cout << G[i][j]; }
		cout << '\n';
	}
}

int main() {
	std::ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	int t = 1;
	// cin >> t;
	while (t--) { solve(); }
	return 0;
}