#include <bits/stdc++.h>
using namespace std;
using ll = long long;

vector<ll> seg;

void update(int l, int r, int n, int u) {

	if (l > u || r < u) return;
	if (l == u && r == u) {
		seg[n] = 1;
		return;
	}
	int mid = (l + r) / 2;
	update(l, mid, n * 2, u);
	update(mid + 1, r, n * 2 + 1, u);
	seg[n] = seg[n * 2] + seg[n * 2 + 1];
}

ll subsum(int l, int r, int n, int sl, int sr) {

	if (l > sr || r < sl)return 0;
	if (l >= sl && r <= sr) return seg[n];

	int mid = (l + r) / 2;
	return subsum(l, mid, n * 2, sl, sr) + subsum(mid + 1, r, n * 2 + 1, sl, sr);
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	ll n;
	cin >> n;

	ll size = 1;
	while(size < n) size *= 2;
	seg = vector<ll>(size * 2);

	vector<pair<ll, ll>> A(n);
	for (ll i = 0; i < n; i++) {
		ll x;
		cin >> x;
		A[i] = { x, i };
	}

	sort(A.begin(), A.end());

	vector<ll> ans(n);

	int pv = 1, pi = 0;
	for (auto i : A) {

		int a, b;
		tie(a, b) = i;

		if (a == pv) {
			ans[b] = ans[pi] + b - pi + 1 - subsum(size, size * 2 - 1, 1, size + pi, size + b);
			update(size, size*2 - 1, 1, size + b);
		}
		else {

			ll tt = ans[pi] + n - pi - subsum(size, size * 2 - 1, 1, size + pi, size * 2 - 1);
			tt += (a - pv - 1) * (n - subsum(size, size * 2 - 1, 1, size, size * 2 - 1));
			tt += b + 1 - subsum(size, size * 2 - 1, 1, size, size + b);

			ans[b] = tt;
			update(size, size * 2 - 1, 1, size + b);
		}

		pv = a;
		pi = b;
	}

	for (ll i : ans) cout << i << '\n';
}