#include<bits/stdc++.h>
using namespace std;
using ll = long long;

ll mod = 1e9 + 7;
vector<ll> seg_cnt, seg_sum;

void update(int l, int r, int n, int u, ll v) {
	if (l > u || r < u) return;
	if (l == u && r == u) {
		seg_cnt[n]++;
		seg_sum[n] += v;
		seg_sum[n] %= mod;
		return;
	}

	int mid = (l + r) / 2;
	update(l, mid, n * 2, u, v);
	update(mid + 1, r, n * 2 + 1, u, v);
	seg_cnt[n] = seg_cnt[n * 2] + seg_cnt[n * 2 + 1];
	seg_sum[n] = (seg_sum[n * 2] + seg_sum[n * 2 + 1]) % mod;
}

ll cnt(int l, int r, int n, int sl, int sr) {

	if (l > sr || r < sl) return 0;
	if (l >= sl && r <= sr) return seg_cnt[n];

	int mid = (l + r) / 2;
	return cnt(l, mid, n * 2, sl, sr) + cnt(mid + 1, r, n * 2 + 1, sl, sr);
}

ll ssum(int l, int r, int n, int sl, int sr) {

	if (l > sr || r < sl) return 0;
	if (l >= sl && r <= sr)	return seg_sum[n];

	int mid = (l + r) / 2;
	return ssum(l, mid, n * 2, sl, sr) + ssum(mid + 1, r, n * 2 + 1, sl, sr);
}

int main() {

	int n;
	cin >> n;

	int size = 1;
	while (size < 200000) size *= 2;
	
	seg_cnt = vector<ll>(size * 2);
	seg_sum = vector<ll>(size * 2);

	ll ans = 1;
	for (int i = 0; i < n; i++) {
		ll x;
		cin >> x;

		ll tans = 0;
		ll ss = ssum(size, size * 2 - 1, 1, size, size + x);
		ll cc = cnt(size, size * 2 - 1, 1, size, size + x);

		tans += x * cc - ss;
		tans %= mod;

		ss = ssum(size, size * 2 - 1, 1, size + x, size * 2 - 1);
		cc = cnt(size, size * 2 - 1, 1, size + x, size * 2 - 1);

		tans += ss - x * cc;
		tans %= mod;
        tans = (tans + mod) % mod;
        
		update(size, size * 2 - 1, 1, size + x, x);

		if (i != 0) ans *= tans;
		ans %= mod;
	}

	cout << ans;
}