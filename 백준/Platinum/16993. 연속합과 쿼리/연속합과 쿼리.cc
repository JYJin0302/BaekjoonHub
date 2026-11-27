#include <bits/stdc++.h>
using namespace std;
using ll = long long;

vector<vector<ll>> seg;
// 0 : left, 1 : right, 2 : all, 3 : sub

void update(int l, int r, int n, int u, ll new_val) {
	if (l > u || r < u) return;
	if (l == u && r == u) {
		seg[n][0] = new_val;
		seg[n][1] = new_val;
		seg[n][2] = new_val;
		seg[n][3] = new_val;
		return;
	}

	int m = (l + r) >> 1;
	update(l, m, n * 2, u, new_val);
	update(m + 1, r, n * 2 + 1, u, new_val);

	seg[n][0] = max(seg[n * 2][0], seg[n * 2][2] + seg[n * 2 + 1][0]);
	seg[n][1] = max(seg[n * 2 + 1][1], seg[n * 2][1] + seg[n * 2 + 1][2]);
	seg[n][2] = seg[n * 2][2] + seg[n * 2 + 1][2];
	seg[n][3] = max({ seg[n * 2][3], seg[n * 2 + 1][3], seg[n * 2][1] + seg[n * 2 + 1][0] });
}

const ll INF = 1e9;
vector<ll> ssum(int l, int r, int n, int sl, int sr) {

	vector<ll> res(4);
	if (l > sr || r < sl) {
		res = { -INF, -INF, -INF, -INF };
		return res;
	}
	if (l >= sl && r <= sr) return seg[n];

	int m = (l + r) >> 1;

	vector<ll> v1 = ssum(l, m, n * 2, sl, sr);
	vector<ll> v2 = ssum(m + 1, r, n * 2 + 1, sl, sr);

	res[0] = max(v1[0], v1[2] + v2[0]);
	res[1] = max(v2[1], v1[1] + v2[2]);
	res[2] = max(-INF, v1[2] + v2[2]);
	res[3] = max({ v1[3], v2[3], v1[1] + v2[0] });
	return res;
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);

	int n;
	cin >> n;

	int sz = 1;
	while (sz < n) sz *= 2;
	seg = vector<vector<ll>>(sz * 2, vector<ll>(4));

	for (int i = 0; i < n; i++) {
		ll x;
		cin >> x;
		update(0, sz - 1, 1, i, x);
	}

	int q;
	cin >> q;
	while (q--) {

		int a, b;
		cin >> a >> b;

		a--, b--;
		vector<ll> res = ssum(0, sz - 1, 1, a, b);
		cout << res[3] << '\n';

	}

}