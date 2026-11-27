#include <bits/stdc++.h>
using namespace std;
using ll = long long;

vector<ll> seg;

void init(int l, int r, int n) {

	if (l == r) return;

	int mid = (l + r) / 2;
	init(l, mid, n * 2);
	init(mid + 1, r, n * 2 + 1);
	seg[n] = max(seg[n * 2], seg[n * 2 + 1]);
}

void update(int l, int r, int n, int u, ll v) {

	if (l > u || r < u) return;
	if (l == u && r == u) {
		seg[n] += v;
		return;
	}

	int mid = (l + r) / 2;
	update(l, mid, n * 2, u, v);
	update(mid + 1, r, n * 2 + 1, u, v);

	seg[n] = seg[n * 2] + seg[n * 2 + 1];
}

ll ssum(int l, int r, int n, int sl, int sr) {

	if (l > sr || r < sl) return 0;
	if (l >= sl && r <= sr) return seg[n];

	int mid = (l + r) / 2;
	return ssum(l, mid, n * 2, sl, sr) + ssum(mid + 1, r, n * 2 + 1, sl, sr);
}


int main() {

	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	int n, m;
	cin >> n >>m;

	int size = 1;
	while (size < n) size *= 2;
	seg = vector<ll>(size * 2);

	for (int i = 0; i < m; i++) {

		ll a, b, c;
		cin >> a >> b >> c;
		b--;
		if (a == 1) {
			update(size, size * 2 - 1, 1, size + b, c);
		}
		else {
			c--;
			cout << ssum(size, size * 2 - 1, 1, size + b, size + c) << '\n';

		}
	}
}