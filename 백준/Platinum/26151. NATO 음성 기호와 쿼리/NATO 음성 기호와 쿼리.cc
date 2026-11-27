#include <bits/stdc++.h>
using ll = long long;
using namespace std;

const string NATO[26] = { "ALFA", "BRAVO", "CHARLIE", "DELTA", "ECHO", "FOXTROT", "GOLF", "HOTEL", "INDIA", "JULIETT", "KILO", "LIMA", "MIKE", "NOVEMBER", "OSCAR", "PAPA", "QUEBEC", "ROMEO", "SIERRA", "TANGO", "UNIFORM", "VICTOR", "WHISKEY", "XRAY", "YANKEE", "ZULU" };
const ll maxN = 1e18;

vector<ll> len[26];
int sz[26];
char ans;

void init() {

	for (int i = 0; i < 26; i++) {
		len[i].push_back(1);
	}
	int curr = 1;
	int fin = 0;
	while (fin < 26) {
		
		for (int i = 0; i < 26; i++) {
			if (len[i].back() < maxN) {
				ll val = 0;

				for (auto c : NATO[i]) {
					val += len[c - 'A'][curr-1];
				}
				len[i].push_back(val);
				if (val >= maxN) fin++;
			}
		}
		curr++;
	}
}

void solve(int cx, int cnt, ll ix) {

	if (cnt == 0) {
		ans = char('A' + cx);
		return;
	}
	string tmp = NATO[cx];
	cnt--;

	int tx = 0;
	ll val = 0, pv = -1;
	for (; tx < tmp.size(); tx++) {
		pv = val;
		val += len[tmp[tx] - 'A'][cnt];
		if (val >= ix) break;
	}


	solve(tmp[tx] - 'A', cnt, ix - pv);
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);

	string s;
	int q;
	cin >> s >> q;

	init();

	int maxSz = 0;
	for (int i = 0; i < 26; i++) {
		maxSz = max(maxSz, (int)len[i].size());
	}
	for (int i = 0; i < 26; i++) {
		if (len[i].size() != maxSz) len[i].push_back((ll)1e18);
	}


	vector<vector<ll>> dp(maxSz+1, vector<ll>(s.size()));
	// dp[i][j] : j번까지 문자열을 i번 operation 돌렷을때 길이
	for (int i = 0; i < maxSz; i++) {
		for (int j = 0; j < s.size(); j++) {
			dp[i][j] = len[s[j] - 'A'][i];

			if (j > 0) dp[i][j] += dp[i][j - 1];
			dp[i][j] = min(dp[i][j], (ll)1e18);
		}
	}

	string res;
	int totX = 0;
	while (q--) {

		ll t, x;
		cin >> t >> x;

		if (t == 1) {
			// 변환 x회
			if (x >= maxSz) totX = maxSz-1;
			else totX += x;
			totX = min(totX, maxSz-1);
		}
		else {

			ans = '?';

			int ai = -1;
			int l = 0, r = s.size() - 1;
			while (l <= r) {

				int m = (l + r) / 2;

				if (dp[totX][m] >= x) {
					r = m-1;
					ai = m;
				}
				else {
					l = m + 1;
				}
			}

			if (ai > 0) x -= dp[totX][ai-1];
			solve(s[ai] - 'A', totX, x);

			res += ans;
		}
	}
	cout << res;
}