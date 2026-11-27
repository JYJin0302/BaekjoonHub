#include <bits/stdc++.h>
using namespace std;

#define x first
#define y second

vector<int> seg;

void update(int l, int r, int n, int u, int v) {
	if (l == u && r == u) {
		seg[n] = v;
		return;
	}
	if (l > u || r < u) return;

	int m = (l + r) / 2;
	update(l, m, n * 2, u, v);
	update(m + 1, r, n * 2 + 1, u, v);
	seg[n] = max(seg[n * 2], seg[n * 2 + 1]);
}

int ssum(int l, int r, int n, int sl, int sr) {
	if (l > sr || r < sl) return -1;
	if (l >= sl && r <= sr) return seg[n];

	int m = (l + r) / 2;
	return max(ssum(l, m, n * 2, sl, sr), ssum(m + 1, r, n * 2 + 1, sl, sr));
}

int main() {

	ios::sync_with_stdio(false);
	cin.tie(0);

	int n;
	cin >> n;
	vector<int> A(n), B(n), C(n);
	for (auto& i : A) {
		cin >> i;
		i--;
	}

	for (int i = 0; i < n; i++){
		int a;
		cin >> a;
		B[a - 1] = n - i;
	}
	for (int i= 0; i < n; i++){
		int a;
		cin >> a;
		C[a - 1] = n - i;
	}

	int sn = 1;
	while (sn < n) sn *= 2;

	seg = vector<int>(sn * 2, -1);

	int ans = 0;
	for (int i = 0; i < n; i++) {
		int ix = A[i];

		int mv = ssum(0, sn - 1, 1, B[ix], sn - 1);
		if (mv < C[ix]) ans++;

		update(0, sn - 1, 1, B[ix], C[ix]);
	}
	cout << ans;
}