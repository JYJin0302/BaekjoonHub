#include <bits/stdc++.h>
using namespace std;

vector<int>seg;

void init(int l, int r, int n) {

	if (l == r) return;

	int mid = (l + r) / 2;
	init(l, mid, n * 2);
	init(mid + 1, r, n * 2 + 1);
	seg[n] = seg[n * 2] + seg[n * 2 + 1];
}

void update(int l, int r, int n, int u, int dx) {
	if (l > u || r < u) return;

	if (l == u && r == u) {
		seg[n] = (dx == 1);
		return;
	}
	int mid = (l + r) / 2;
	update(l, mid, n * 2, u, dx);
	update(mid + 1, r, n * 2 + 1, u, dx);
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
	int t;
	cin >> t;
	while (t--) {

		int n, m;
		cin >> n >> m;
		int size = 1;
		while (size < n + m) size *= 2;
		seg = vector<int>(size * 2);

		vector<int> pos(n + 1);
		for (int i = 1; i <= n; i++) {
			pos[i] = n - i;
			seg[size + n - i] = 1;
		}

		init(size, size * 2 - 1, 1);

		for (int i = 0; i < m; i++) {
			int a;
			cin >> a;

			cout << subsum(size, size * 2 - 1, 1, size + pos[a] + 1, size * 2 - 1) << ' ';

			update(size, size * 2 - 1, 1, size + pos[a], -1);
			update(size, size * 2 - 1, 1, size + n + i, 1);
			pos[a] = n + i;
		}
		cout << '\n';
	}
}