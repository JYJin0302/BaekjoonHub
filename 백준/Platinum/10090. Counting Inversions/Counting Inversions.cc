#include <bits/stdc++.h>
using namespace std;
using ll = long long;

vector<int> seg;

void update(int l, int r, int n, int u) {
	if (l > u || r < u) return;
	if (l == u && r == u) {
		seg[n] = 1;
		return;
	}
	int mid = (l+r)/2;

	update(l, mid, n * 2, u);
	update(mid + 1, r, n * 2 + 1, u);

	seg[n] = seg[n * 2] + seg[n * 2 + 1];
}

int subsum(int l, int r, int n, int sl, int sr) {
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
	seg = vector<int>(size * 2);

	ll ans = 0;
	for (int i = 0; i < n; i++) {
		int x;
		cin >> x;
		ans += subsum(size, size * 2 - 1, 1, size + x, size * 2 - 1);
		update(size, size * 2 - 1, 1, size + x - 1);
	}

	cout << ans;
}