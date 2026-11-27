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

	map<string, array<int, 10>> dp;
	map<string, int> cnt;

	int mxCnt = 0;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < 10; j++) {
			string s;
			cin >> s;

			dp[s][j]++;
			cnt[s]++;
			mxCnt = max(mxCnt, cnt[s]);
		}
	}

	vector<string> res;
	for (auto [a, b] : cnt) {
		if (b == mxCnt) res.push_back(a);
	}

	if ((int)res.size() == 1) {
		cout << res[0] << '\n';
		return;
	}

	string ans = res[0];
	int ansi = 0;
	int tieCnt = 0;
	for (int i = 1; i < (int)res.size(); i++) {
		int rr = 0;
		string s1 = res[ansi];
		string s2 = res[i];
		for (int j = 0; j < 10; j++) {
			if (dp[s1][j] != dp[s2][j]) {
				if (dp[s1][j] > dp[s2][j]) {
					rr = -1;
				} else rr = 1;
				break;
			}
		}

		//cout << i << ' '<<ansi << " => " << rr << '\n';

		if(rr == 0) tieCnt++;
		else if (rr == 1){
			ansi = i;
			tieCnt = 0;
			ans = res[i];
		}
	}

	if (tieCnt) cout << "tie\n";
	else cout << ans << '\n';
}

int main() {
	std::ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	int t = 1;
	//cin >> t;
	for (int i = 1; i <= t; i++) {
		// cout << "Case #" << i << ": ";
		solve();
	}
	return 0;
}