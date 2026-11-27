#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using ld = long double;

#define mp make_pair
#define x first
#define y second
#define all(x) x.begin(), x.end()

int dp[5005][5005];
string s1, s2;

int getDp(int l, int r) {
	if (dp[l][r] != -1) return dp[l][r];
	if (l == 0 || r == 0) return dp[l][r] = l + r;

	int ret = 1e9;
	if (s1[l - 1] == s2[r - 1]) {
		ret = min(ret, getDp(l - 1, r - 1));
	} else ret = min(ret, getDp(l - 1, r - 1) + 1);
	ret = min(ret, getDp(l - 1, r) + 1);
	ret = min(ret, getDp(l, r - 1) + 1);
	return dp[l][r] = ret;
}
void solve() {
	int n, m;
	cin >> n >> m;

	cin >> s1 >> s2;
	if (abs(n - m) > 2) {
		cout << 0 << '\n';
		return;
	}

	if (n < m) {
		swap(n, m);
		swap(s1, s2);
	}

	memset(dp, -1, sizeof dp);

	int len = getDp(n, m);
	if (len > 2) {
		cout << 0 << '\n';
		return;
	}

	int cx = n, cy = m;
	vector<pair<int, int>> M, E;  // modify, erase
	while (cx || cy) {
		if (cx == 0) {
			cy--;
			E.push_back(mp(2, cy));
		} else if (cy == 0) {
			cx--;
			E.push_back(mp(1, cx));
		} else {
			if (dp[cx - 1][cy] + 1 == dp[cx][cy]) E.push_back(mp(1, --cx));
			else if (dp[cx][cy - 1] + 1 == dp[cx][cy]) E.push_back(mp(2, --cy));
			else if (dp[cx - 1][cy - 1] + 1 == dp[cx][cy]) M.push_back(mp(--cx, --cy));
			else { cx--, cy--; }
		}
	}

	// for (auto [a, b] : M) cout << a << ' ' << b << " | ";
	// cout << '\n';
	// for (auto [a, b] : E) cout << a << ' ' << b << " | ";
	// cout << '\n';

	cout << 1 << '\n';
	if (len == 0) {
		cout << s1 << 'A' << '\n';
	} else if (len == 1) {
		if (!M.empty()) {
			auto [i1, i2] = M[0];
			string ans = s1;
			char c1 = s1[i1], c2 = s2[i2];
			while (ans[i1] == c1 || ans[i1] == c2) {
				if (ans[i1] == 'Z') ans[i1] = 'A';
				else ans[i1]++;
			}
			cout << ans << '\n';
		} else {
			auto [i1, i2] = E[0];
			string ans;
			if (i1 == 1) {
				ans = s1;
				if (ans[i2] == 'Z') ans[i2] = 'A';
				else ans[i2]++;
			} else {
				ans = s2;
				if (ans[i2] == 'Z') ans[i2] = 'A';
				else ans[i2]++;
			}
			cout << ans << '\n';
		}
	} else {
		// len == 2
		if (!M.empty()) {
			auto [i1, i2] = M[0];
			string ans = s1;
			ans[i1] = s2[i2];

			cout << ans << '\n';
		} else {
			auto [i1, i2] = E[0];
			string ans;
			if (i1 == 1) {
				for(int j =0 ;j < n; j++){
					if (j != i2) ans += s1[j];
				}
			} else {
				for (int j = 0; j < m; j++) {
					if (j != i2) ans += s2[j];
				}
			}
			cout << ans << '\n';
		}
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