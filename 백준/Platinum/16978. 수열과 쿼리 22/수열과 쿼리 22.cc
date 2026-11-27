#include <bits/stdc++.h>
using namespace std;
using ll = long long;

vector<ll> seg;

void init(int l,int r, int n) {
	if (l == r) return;

	int mid = (l + r) / 2;
	init(l, mid, n * 2);
	init(mid + 1, r, n * 2 + 1);
	
	seg[n] = seg[n * 2] + seg[n * 2 + 1];
}

void update(int l, int r, int n, int u, ll v) {

	if (l > u || r < u) return;
	if (l == u && r == u) {
		seg[n] = v;
		return;
	}

	int mid = (l + r) / 2;

	update(l, mid, n * 2, u, v);
	update(mid + 1, r, n * 2 + 1, u, v);

	seg[n] = seg[n * 2] + seg[n * 2 + 1];
}

ll subsum(int l, int r, int n, int sl, int sr) {

	if (l > sr || r < sl) return 0;
	if (l >= sl && r <= sr) return seg[n];

	int mid = (l + r) / 2;

	return subsum(l, mid, n * 2, sl, sr) + subsum(mid + 1, r, n * 2 + 1, sl, sr);

}



int main() {
ios::sync_with_stdio(false);
cin.tie(nullptr);
	int n;
	cin >> n;

	int size = 1;
	while (size < n) size *= 2;

	seg = vector<ll>(size * 2);

	for (int i = 0; i < n; i++) {
		cin >> seg[size + i];
	}

	init(size, size * 2 - 1, 1);

	int q;
	cin >> q;

	vector<pair<ll, ll>> q1;
	vector<tuple<ll, ll, ll, ll>> q2;

	int ind = 0;

	for (int i = 0; i < q; i++) {
		ll k, a, b, c;
		cin >> k;
		if (k == 1) {
			cin >> a >> b;
			q1.push_back({ a, b });
		}
		else {
			cin >> a >> b >> c;
			q2.push_back({ a, b, c, ind });
			ind++;
		}
	}

	sort(q2.begin(), q2.end());

	int cnt = 0;
	vector<ll> ans(ind);

	for (int i = 0; i < ind; i++) {
		int a, b, c, d;
		tie(a, b, c, d) = q2[i];

		while (cnt < a) {
			int x, y;
			tie(x, y) = q1[cnt];

			update(size, size * 2 - 1, 1, size + x - 1, y);
			cnt++;
		}

		ans[d] = subsum(size, size * 2 - 1, 1, size + b - 1, size + c - 1);
	}

	for (ll i : ans) cout << i << '\n';

}