#include <bits/stdc++.h>
using namespace std;
using ll = long long;

vector<ll> seg;

void init(int l, int r, int n) {
	if (l == r) return;
	int mid = (l + r) / 2;
	init(l, mid, n * 2), init(mid + 1, r, n * 2 + 1);
	seg[n] = seg[n * 2] + seg[n * 2 + 1];
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

	vector<int> ind1(n + 1), inp1(n);

	for (int i = 0; i < n; i++) {
		seg[size + i] = 1;
		int a;
		cin >> a;
		ind1[a] = i;
		inp1[i] = a;
	}

	init(size, size * 2 - 1, 1);

	ll ans = 0;
	vector<int> ind2(n+1), inp2(n);
	for (int i = 0; i < n; i++) {
		int a;
		cin >> a;
		ind2[a] = i;
		inp2[i] = a;
		ans += subsum(size, size * 2 - 1, 1, size, size + ind1[a]) - 1;
		update(size, size * 2 - 1, 1, size + ind1[a], -1);
	}

	ll tans = ans;
	// 오른쪽
	ll temp = tans;
	for (int i = n - 1; i >= 0; i--) {

		temp -= (ll)n - 1 - ind1[inp2[i]];
		temp += ind1[inp2[i]];
		ans = min(ans, temp);
	}

	// 왼쪽
	temp = tans;
	for (int i = n - 1; i >= 0; i--) {

		temp -= (ll)n - 1 - ind2[inp1[i]];
		temp += ind2[inp1[i]];
		ans = min(ans, temp);
	}
	cout << ans;
}