#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using ld = long double;

#define mp make_pair
#define x first
#define y second
#define all(x) x.begin(), x.end()

int fw[303030];
void update(int ix, int val) {
	while (ix <= 300030) {
		fw[ix] += val;
		ix += ix & -ix;
	}
}
int getS(int ix) {
	int res = 0;
	while (ix) {
		res += fw[ix];
		ix -= ix & -ix;
	}
	return res;
}

pair<ll, ll> seg[1202020];
int cnt[303030];
void init(int l, int r, int n) {
	if (l == r) {
		seg[n] = mp(cnt[l], 1);
		return;
	}
	int md = (l + r) >> 1;
	init(l, md, n * 2);
	init(md + 1, r, n * 2 + 1);
	seg[n] = mp(seg[n * 2].x + seg[n * 2 + 1].x, seg[n * 2].y + seg[n * 2 + 1].y);
}

void update(int l, int r, int n, int u) {
	if (l > u || r < u) return;
	if (l == u && r == u) {
		seg[n] = mp(0, 0);
		return;
	}
	int md = (l + r) >> 1;
	update(l, md, n * 2, u);
	update(md + 1, r, n * 2 + 1, u);
	seg[n] = mp(seg[n * 2].x + seg[n * 2 + 1].x, seg[n * 2].y + seg[n * 2 + 1].y);
}

pair<ll, ll> getS(int l, int r, int n, int sl, int sr) {
	if (l > sr || r < sl) return mp(0, 0);
	if (l >= sl && r <= sr) return seg[n];
	int md = (l + r) >> 1;
	pair<ll, ll> p1 = getS(l, md, n * 2, sl, sr);
	pair<ll, ll> p2 = getS(md + 1, r, n * 2 + 1, sl, sr);
	return mp(p1.x + p2.x, p1.y + p2.y);
}

void solve() {
	int n;
	cin >> n;

	vector<pair<int, int>> A(n);
	vector<int> ypos;
	for (auto& [a, b] : A) {
		cin >> a >> b;
		ypos.push_back(b);
	}
	sort(all(ypos));

	sort(all(A));
	vector<int> B(n);
	for (int i = 0; i < n; i++) { B[i] = lower_bound(all(ypos), A[i].y) - ypos.begin(); }

	for (int i = n - 1; i >= 0; i--) {
		int val = B[i] + 1;
		cnt[i] = n - i - 1 - getS(val);
		update(val, 1);
	}

	vector<pair<int, int>> C(n);
	for (int i = 0; i < n; i++) { C[i] = mp(B[i], i); }
	sort(all(C));

	init(0, n - 1, 1);

	ll ans = 0;
	for (auto f : C) {
		int ix = f.y;
		pair<ll, ll> res = getS(0, n - 1, 1, ix + 1, n - 1);

		ans += res.y * (res.y - 1) / 2 - res.x;
		update(0, n - 1, 1, ix);
	}
	cout << ans << '\n';
}

int main() {
	std::ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	int t = 1;
	// cin >> t;
	for (int i = 1; i <= t; i++) {
		// cout << "Case #" << i << ": ";
		solve();
	}
	return 0;
}