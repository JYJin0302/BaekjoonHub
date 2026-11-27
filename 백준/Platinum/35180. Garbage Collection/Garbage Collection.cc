#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using ld = long double;

#define mp make_pair
#define x first
#define y second
#define all(x) x.begin(), x.end()

ll seg[606060];
ll lazy[606060];

void goLazy(int l, int r, int n) {
	if (lazy[n]) {
		seg[n] += lazy[n];
		if (l != r) {
			lazy[n * 2] += lazy[n];
			lazy[n * 2 + 1] += lazy[n];
		}
		lazy[n] = 0;
	}
}

void update(int l, int r, int n, int sl, int sr, ll val) {
	goLazy(l, r, n);
	if (l > sr || r < sl) return;
	if (l >= sl && r <= sr) {
		lazy[n] += val;
		goLazy(l, r, n);
		return;
	}
	int md = (l + r) >> 1;
	update(l, md, n * 2, sl, sr, val);
	update(md + 1, r, n * 2 + 1, sl, sr, val);
	seg[n] = max(seg[n * 2], seg[n * 2 + 1]);
}

ll getS(int l, int r, int n, int sl, int sr) {
	goLazy(l, r, n);
	if (l > sr || r < sl) return 0;
	if (l >= sl && r <= sr) return seg[n];
	int md = (l + r) >> 1;
	return max(getS(l, md, n * 2, sl, sr), getS(md + 1, r, n * 2 + 1, sl, sr));
}

void solve() {
	int n;
	cin >> n;
	ll w, h;
	cin >> w >> h;

	vector<pair<int, int>> A(n);
	vector<int> W(n);
	vector<int> xpos;
	for (int i = 0; i < n; i++) {
		int a, b;
		cin >> a >> b >> W[i];
		A[i] = mp(a, b);
		xpos.push_back(a);
	}
	sort(all(xpos));
	xpos.erase(unique(all(xpos)), xpos.end());

	vector<array<ll, 4>> B;
	for (int i = 0; i < n; i++) {
		int l = lower_bound(all(xpos), A[i].x) - xpos.begin();
		int r = lower_bound(all(xpos), A[i].x + w) - xpos.begin() - 1;

		//cout << l << ' ' << r << ' ' << A[i].y << ' ' << A[i].y + h + 1 << " | " << W[i] << '\n';
		B.push_back({A[i].y, W[i], l, r});
		B.push_back({A[i].y + h, -W[i], l, r});
	}
	sort(all(B));

	int tn = (int)xpos.size();
	ll ans = 0;
	for (auto f : B) {
		int l = f[2], r = f[3];
		ll c = f[1];

		update(0, tn - 1, 1, l, r, c);
		if (c > 0) ans = max(ans, getS(0, tn - 1, 1, 0, tn - 1));
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