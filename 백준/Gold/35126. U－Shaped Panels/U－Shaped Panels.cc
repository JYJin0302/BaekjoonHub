#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using ld = long double;

#define mp make_pair
#define x first
#define y second
#define all(x) x.begin(), x.end()

int n, m, k;
char G[1010][1010];
bool vis[1010][1010];

bool check() {
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			if (G[i][j] == '#' && !vis[i][j]) {
				//cout << "Check: " << i << ' ' << j << '\n';
				if (i + k - 1 >= n || j + k - 1 >= m) return 0;

				if (G[i + k - 1][j] == '.' || vis[i + k - 1][j]) return 0;
				if (G[i][j + k - 1] == '.' || vis[i][j + k - 1]) return 0;
				if (G[i + k - 1][j + k - 1] == '.' || vis[i + k - 1][j + k - 1]) return 0;
				vis[i][j] = 1;
				vis[i + k - 1][j] = 1;
				vis[i][j + k - 1] = 1;
				vis[i + k - 1][j + k - 1] = 1;

				//cout << "phase 1\n";
				array<bool, 4> test;
				test[0] = test[1] = test[2] = test[3] = 0;

				// U
				for (int f = 1; f < k - 1; f++) {
					if (vis[i][j + f] || G[i][j + f] == '.') {
						test[0] = 1;
						break;
					}
				}
				// L
				for (int f = 1; f < k - 1; f++) {
					if (vis[i + f][j] || G[i + f][j] == '.') {
						test[1] = 1;
						break;
					}
				}
				// R
				for (int f = 1; f < k - 1; f++) {
					if (vis[i + f][j + k - 1] || G[i + f][j + k - 1] == '.') {
						test[2] = 1;
						break;
					}
				}
				// D
				for (int f = 1; f < k - 1; f++) {
					if (vis[i + k - 1][j + f] || G[i + k - 1][j + f] == '.') {
						test[3] = 1;
						break;
					}
				}

				int cnt = 0;
				for (int f = 0; f < 4; f++) {
					if (test[f]) cnt++;
				}

				if (cnt != 1) return 0;
				//cout << "phase 2\n";

				if (!test[0]) {
					for (int f = 1; f < k - 1; f++) { vis[i][j + f] = 1; }
				}
				if (!test[1]) {
					for (int f = 1; f < k - 1; f++) { vis[i + f][j] = 1; }
				}
				if (!test[2]) {
					for (int f = 1; f < k - 1; f++) { vis[i + f][j + k - 1] = 1; }
				}
				if (!test[3]) {
					for (int f = 1; f < k - 1; f++) { vis[i + k - 1][j + f] = 1; }
				}
			}
		}
	}
	return 1;
}

void solve() {
	cin >> n >> m >> k;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			cin >> G[i][j];
			vis[i][j] = 0;
		}
	}

	if (check()) cout << "yes\n";
	else cout << "no\n";
}

int main() {
	std::ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	int t = 1;
	cin >> t;
	for (int i = 1; i <= t; i++) {
		// cout << "Case #" << i << ": ";
		solve();
	}
	return 0;
}