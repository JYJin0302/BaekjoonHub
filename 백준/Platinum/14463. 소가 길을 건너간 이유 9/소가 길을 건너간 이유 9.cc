#include <bits/stdc++.h>
using namespace std;
using ll = long long;

vector<ll> seg;

void update(int l, int r, int n, int u, int v) {

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
	while(size < n*2) size *= 2;
	seg = vector<ll>(size * 2);

	ll ans = 0;
	vector<int> ind(n+1, -1);
	for (int i = 0; i < n*2; i++) {
		int x;
		cin >> x;

		if (ind[x] == -1) {
			ind[x] = i;
			update(size, size * 2 - 1,1, size + i, 1);
		}
		else {
			int a = ind[x];

			update(size, size * 2 - 1, 1, size + a, -1);

			ans += subsum(size, size * 2 - 1, 1, size + a, size + i);
		}
	}

	cout << ans;
}