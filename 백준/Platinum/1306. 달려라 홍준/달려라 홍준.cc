#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int ans;
vector<int> seg;

void init(int l, int r, int n) {

	if (l == r) return;

	int mid = (l + r) / 2;
	init(l, mid, n * 2);
	init(mid + 1, r, n * 2 + 1);
	seg[n] = max(seg[n * 2], seg[n * 2 + 1]);
}

void update(int l, int r, int n, int u, int v) {

	if (l > u || r < u) return;
	if (l == u && r == u) {
		seg[n] += v;
		return;
	}

	int mid = (l + r) / 2;
	update(l, mid, n * 2, u, v);
	update(mid + 1, r, n * 2 + 1, u, v);

	seg[n] = max(seg[n * 2], seg[n * 2 + 1]);
}

int ssum(int l, int r, int n, int sl, int sr) {

	if (l > sr || r < sl) return 0;
	if (l >= sl && r <= sr) return seg[n];

	int mid = (l + r) / 2;
	return max(ssum(l, mid, n * 2, sl, sr) , ssum(mid + 1, r, n * 2 + 1, sl, sr));
}


int main() {

	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	int n, m;
	cin >> n >>m;

	int size = 1;
	while (size < n) size *= 2;
	seg = vector<int>(size * 2);

	for (int i = 0; i < n; i++) {
		cin >> seg[size + i];
	}

	init(size, size * 2 - 1, 1);

	for (int i = m - 1; i <= n - m; i++) {
		cout << ssum(size, size * 2 - 1, 1, size + i - m + 1, size + i + m - 1) << ' ';

	}
}