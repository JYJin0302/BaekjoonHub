#include <bits/stdc++.h>
using namespace std;
using ll = long long;


vector<ll> iton;
map<ll, ll> ntoi;

vector<ll> seg;

void update(int l, int r, int n, int u, ll v) {
	if (l == u && r == u) {
		seg[n] = v;
		return;
	}
	if (l > u || r < u) return;

	int m = (l + r) / 2;
	update(l, m, n * 2, u, v);
	update(m + 1, r, n * 2 + 1, u, v);
	seg[n] = max(seg[n * 2], seg[n * 2 + 1]);
}
ll ssum(int l, int r, int n, int sl, int sr) {
	if (l > sr || r < sl) return -1e16;
	if (l >= sl && r <= sr) return seg[n];

	int m = (l + r) / 2;
	return max(ssum(l, m, n * 2, sl, sr), ssum(m + 1, r, n * 2 + 1, sl, sr));
}

void solve() {

	int n;
	cin >> n;

	vector<ll> A(n + 1), sA(n + 1);
	for (int i = 1; i <= n; i++) cin >> A[i];
	for (int i = 1; i <= n; i++) sA[i] = sA[i - 1] + A[i];

	for (auto i : sA) iton.push_back(i);
	sort(iton.begin(), iton.end());
	iton.erase(unique(iton.begin(), iton.end()), iton.end());

	int sn = iton.size();
	for (int i = 0; i < sn; i++) ntoi[iton[i]] = i;

	int tn = 1;
	while (tn < sn) tn *= 2;

	seg = vector<ll>(tn * 2, -1e16);

	vector<ll> dp(n + 1);

	int tx = ntoi[0];
	update(0, tn - 1, 1, tx, 0);

	for (int i = 1; i <= n; i++) {
		int ix = ntoi[sA[i]];

		ll val = ssum(0, tn - 1, 1, 0, ix);
		dp[i] = max(dp[i-1], val + i);

		update(0, tn - 1, 1, ix, dp[i] - i);
	}

	cout << dp[n];

}

int main() {

	ios::sync_with_stdio(false);
	cin.tie(0);

	int t = 1;
	//cin >> t;
	while (t--) {
		solve();
	}
}