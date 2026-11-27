#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using ld = long double;

#define mp make_pair
#define x first
#define y second
#define all(x) x.begin(), x.end()

pair<ll, int> seg[303030];  // sum, count

void init(int l, int r, int n) {
	seg[n] = mp(0, 0);
	if (l == r) return;
	int md = (l + r) >> 1;
	init(l, md, n * 2);
	init(md + 1, r, n * 2 + 1);
}

void update(int l, int r, int n, int ix, ll val) {
	if (l > ix || r < ix) return;
	if (l == ix && r == ix) {
		seg[n].x += val;
		seg[n].y++;
		return;
	}

	int md = (l + r) >> 1;
	update(l, md, n * 2, ix, val);
	update(md + 1, r, n * 2 + 1, ix, val);
	seg[n] = mp(seg[n * 2].x + seg[n * 2 + 1].x, seg[n * 2].y + seg[n * 2 + 1].y);
}

ll getS(int l, int r, int n, ll cnt) {
	if (seg[n].y <= cnt) return seg[n].x;
	if (l == r) {
		ll mul = seg[n].x / seg[n].y;
		return mul * cnt;
	}
	int md = (l + r) >> 1;
	if (seg[n * 2 + 1].y >= cnt) return getS(md + 1, r, n * 2 + 1, cnt);
	return seg[n * 2 + 1].x + getS(l, md, n * 2, cnt - seg[n * 2 + 1].y);
}

vector<int> P[101010];

void solve() {
	int n;
	cin >> n;

	vector<ll> ypos;
	vector<pair<ll, ll>> A(n);
	for (auto& [a, b] : A) {
		cin >> a >> b;
		ypos.push_back(b);
	}
	sort(all(A));
	sort(all(ypos));
	ypos.erase(unique(all(ypos)), ypos.end());
	int tn = (int)ypos.size();

	int q;
	cin >> q;

	vector<pair<ll, ll>> Q;
	for (int i = 0; i < q; i++) {
		ll x, y;
		cin >> x >> y;
		Q.push_back(mp(x, y));
	}

	vector<int> L(q, 1), R(q, n);

	while (1) {
		bool ok = 1;
		for (int i = 0; i < q; i++) {
			if (L[i] <= R[i]) {
				int md = (L[i] + R[i]) >> 1;
				P[md].push_back(i);
				ok = 0;
			}
		}
		if (ok) break;

		init(0, tn - 1, 1);
		ll totX = 0, totY = 0;
		for (int i = 0; i < n; i++) {
			totX += A[i].x;
			totY += A[i].y;
			int ix = lower_bound(all(ypos), A[i].y) - ypos.begin();
			update(0, tn - 1, 1, ix, A[i].y);

			for (auto f : P[i + 1]) {
				// query
				auto [x, y] = Q[f];
				if (totX > x) {
					R[f] = i;
				} else {
					ll rem = x - totX;
					ll res = getS(0, tn - 1, 1, rem);
					
					if (totY - res <= y) L[f] = i + 2;
					else R[f] = i;
				}
			}
			P[i + 1].clear();
		}
	}

	for (int i = 0; i < q; i++) cout << R[i] << '\n';
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