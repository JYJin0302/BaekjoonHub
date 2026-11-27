#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using ld = long double;

#define mp make_pair
#define x first
#define y second
#define all(x) x.begin(), x.end()

bool dp[101][444];
int from[101][444];

void solve() {
	int n, h, w;
	cin >> n >> h >> w;

	int tot = 0;
	vector<array<int, 3>> A;
	for (int i = 0; i < n; i++) {
		int a, b;
		cin >> a >> b;
		A.push_back({a, b, i});
		tot += b;
	}
	sort(all(A));

	dp[0][0] = 1;
	for (int i = 0; i < n; i++) {
		int a = A[i][0];
		int b = A[i][1];
		int ix = A[i][2];

		for (int j = b; j <= 400; j++) {
			if (dp[i][j - b]) dp[i + 1][j] = 1, from[i + 1][j] = b;
		}

		if (a <= h) {
			for (int j = 0; j <= 400; j++) dp[i + 1][j] |= dp[i][j];
		} else {
		}
	}

	for (int t = n; t >= 1; t--) {
		for (int j = 1; j <= min(tot - 1, h); j++) {
			if (dp[t][j] && tot - j + A[t - 1][0] <= w && from[t][j] != 0) {
				vector<int> ans1, ans2;
				for(int f = t + 1; f <= n; f++){
					ans1.push_back(A[f-1][2]);
				}
				int curx = t;
				int cury = j;
				while (curx) {
					int ix = A[curx - 1][2];
					if (from[curx][cury] == 0) {
						ans1.push_back(ix);
					} else {
						ans2.push_back(ix);
						cury -= A[curx - 1][1];
					}
					curx--;
				}

				assert(!ans1.empty() && !ans2.empty() && (int)ans1.size() + (int)ans2.size() == n);
				cout << "upright ";
				for (auto f : ans1) cout << f + 1 << ' ';
				cout << '\n';
				cout << "stacked ";
				for (auto f : ans2) cout << f + 1 << ' ';
				cout << '\n';
				return;
			}
		}

		if (A[n - 1][0] > h) break;
	}
	cout << "impossible\n";
}

int main() {
	std::ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	int t = 1;
	// cin >> t;
	for (int i = 1; i <= t; i++) {
		// cout << "Case #" << i << ": ";
		solve();
	}
	return 0;
}