#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using ld = long double;

#define mp make_pair
#define x first
#define y second
#define all(x) x.begin(), x.end()

int dp[77][77][77];  // i 까지 j번 사용 k -> 최소길이

void solve() {
	string s;
	cin >> s;

	int n = (int)s.size() / 2;
	vector<int> A(n), sA(n);
	int cc = 0;
	for (int i = 0; i < n; i++) {
		if (s[i * 2 + 1] == '(') A[i] = 1, cc++;
		else A[i] = 0;

		sA[i] = A[i];
		if (i) sA[i] += sA[i - 1];
	}

	int k;
	cin >> k;

	memset(dp, -1, sizeof dp);
	dp[0][0][0] = 0;

	for (int i = 0; i < n; i++) {
		for (int j = 0; j <= k; j++) {
			for (int f = 0; f <= cc; f++) {
				if (dp[i][j][f] == -1) continue;

				// cout << "Dp: " << i << ' ' << j << ' ' << f << " : " << dp[i][j][f] << '\n';
				//  try 1
				for (int ti = i; ti < n; ti++) {
					// [i, ti] 수정
					int val = sA[ti] - (i ? sA[i - 1] : 0);
					int len = ti - i + 1;
					val = len - val;

					if (j + val <= k && f + len <= cc) {
						int res = dp[i][j][f] + (len == 1 ? 2 : 2 + to_string(len).size());
						int &ret = dp[ti + 1][j + val][f + len];
						if (ret == -1 || ret > res) ret = res;
					}
				}

				// try 0
				for (int ti = i; ti < n; ti++) {
					// [i, ti] 수정
					int val = sA[ti] - (i ? sA[i - 1] : 0);
					int len = ti - i + 1;

					if (j + val <= k) {
						int res = dp[i][j][f] + (len == 1 ? 2 : 2 + to_string(len).size());
						int &ret = dp[ti + 1][j + val][f];
						if (ret == -1 || ret > res) ret = res;
					}
				}
			}
		}
	}

	int ans = n * 10;
	for (int j = 0; j <= k; j++) {
		int f = cc;
		if (dp[n][j][f] != -1) { ans = min(ans, dp[n][j][f]); }
	}

	cout << ans << '\n';
}

int main() {
	std::ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	int t = 1;
	// cin >> t;
	for (int i = 1; i <= t; i++) { solve(); }
	return 0;
}