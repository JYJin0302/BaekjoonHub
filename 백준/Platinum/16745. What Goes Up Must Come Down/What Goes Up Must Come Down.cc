#include <bits/stdc++.h>
#define ll long long
using namespace std;


vector<ll> seg;

void update(int l, int r, int n, int u, int v) {
	if (l > u | r < u) return;
	if (l == u && r == u) {
		seg[n] = v;
		return;
	}

	int m = (l + r) >> 1;
	update(l, m, n * 2, u, v);
	update(m + 1, r, n * 2 + 1, u, v);
	seg[n] = seg[n * 2] + seg[n * 2 + 1];
}

ll ssum(int l, int r, int n, int sl, int sr) {
	if (l > sr || r < sl) return 0;
	if (l >= sl && r <= sr) return seg[n];

	int m = (l + r) >> 1;
	return ssum(l, m, n * 2, sl, sr) + ssum(m + 1, r, n * 2 + 1, sl, sr);
}

vector<int> idx[100001];

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int n;
	cin >> n;

	for (int i = 0; i < n; i++) {
		int x;
		cin >> x;

		idx[x].push_back(i);
	}

	int sz = 1;
	while (sz < n) sz *= 2;
	seg = vector<ll>(sz * 2);

	for (int i = 0; i < n; i++) {
		update(0, sz - 1, 1, i, 1);
	}
	ll ans = 0;

	for (int i = 1; i <= 100000; i++) {
		if (idx[i].empty()) continue;

		int l = 0, r = idx[i].size()-1;

		while (l <= r) {

			// val l, val r compare
			int lx = idx[i][l], rx = idx[i][r];

			ll suml = ssum(0, sz - 1, 1, 0, lx);
			ll sumr = ssum(0, sz - 1, 1, rx, sz - 1);

			if (suml <= sumr) {
				ans += suml - 1;
				update(0, sz - 1, 1, lx, 0);
				l++;
			}
			else {
				ans += sumr - 1;
				update(0, sz - 1, 1, rx, 0);
				r--;
			}
		}
	}
	cout << ans;

}