#include <bits/stdc++.h>
using namespace std;
using ll = long long;

const ll mod = 1e9 + 7;

ll fastPow(ll b, ll ex, ll m) {
	ll res = 1;
	while (ex) {
		if (ex & 1) res = res * b % m;
		b = b * b % m;
		ex >>= 1;
	}
	return res;
}

ll f[2000001];
vector<int> seg;
vector<int> idx[1000001];


void init(int l, int r, int n) {
	if (l == r) return;
	int m = (l + r) / 2;
	init(l, m, n * 2);
	init(m + 1, r, n * 2 + 1);
	seg[n] = min(seg[n * 2], seg[n * 2 + 1]);
}

int minv(int  l, int r, int n, int sl, int sr) {
	if (l > sr || r < sl) return mod;
	if (l >= sl && r <= sr) return seg[n];

	int m = (l + r) / 2;
	return min(minv(l, m, n * 2, sl, sr), minv(m + 1, r, n * 2 + 1, sl, sr));
}

int n, sn;
ll ans = 1;
void solve(int l, int r) {

	if (l > r) return;

	int mv = minv(0, sn - 1, 1, l, r);

	int mx = lower_bound(idx[mv].begin(), idx[mv].end(), l) - idx[mv].begin();
	int Mx = lower_bound(idx[mv].begin(), idx[mv].end(), r+1) - idx[mv].begin() - 1;
	ll tval = Mx - mx + 1;

	ll tans = f[tval * 2];
	tans = tans * fastPow(f[tval], mod - 2, mod) % mod;
	tans = tans * fastPow(f[tval + 1], mod - 2, mod) % mod;
	ans = ans * tans % mod;

	solve(l, idx[mv][mx] - 1);
	for (int i = mx; i < Mx; i++) {
		solve(idx[mv][i] + 1, idx[mv][i + 1] - 1);
	}
	solve(idx[mv][Mx] + 1, r);

}

int main() {

	ios::sync_with_stdio(false);
	cin.tie(0);

	f[0] = 1;
	for (int i = 1; i <= 2000000; i++) f[i] = f[i - 1] * i % mod;

	cin >> n;

	sn = 1;
	while (sn < n) sn *= 2;

	seg = vector<int>(sn * 2, mod);
	for (int i = 0; i < n; i++) {
		cin >> seg[sn + i];
		idx[seg[sn + i]].push_back(i);
	}
	init(0, sn - 1, 1);

	solve(0, n - 1);

	cout << ans;
}