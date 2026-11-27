#include <bits/stdc++.h>
using namespace std;
using ll = long long;

struct Platform {
	int l, r, h;

	bool operator<(Platform& o) {
		return h < o.h;
	}
};

vector<int> seg, lazy;

void go_lazy(int l, int r, int n) {
	if (lazy[n] != -1) {
		seg[n] = lazy[n];
		if (l != r) {
			lazy[n * 2] = lazy[n];
			lazy[n * 2 + 1] = lazy[n];
		}
	}
	lazy[n] = -1;
}

void update(int l, int r, int n, int sl, int sr, int v) {
	go_lazy(l, r, n);

	if (l > sr || r < sl) return;
	if (l >= sl && r <= sr) {
		lazy[n] = v;
		go_lazy(l, r, n);
		return;
	}

	int m = (l + r) >> 1;
	update(l, m, n * 2, sl, sr, v);
	update(m + 1, r, n * 2 + 1, sl, sr, v);
	seg[n] = min(seg[n * 2], seg[n * 2 + 1]);
}

int ssum(int l, int r, int n, int sl, int sr) {
	go_lazy(l, r, n);
	if (l > sr || r < sl) return 1e9;
	if (l >= sl && r <= sr) {
		return seg[n];
	}

	int m = (l + r) >> 1;
	return min(ssum(l, m, n * 2, sl, sr), ssum(m + 1, r, n * 2 + 1, sl, sr));
}

int main() {

	ios::sync_with_stdio(false);
	cin.tie(0);

	int n, k;
	cin >> n >> k;

	vector<int> pos;
	vector<Platform> p;

	for (int i = 0; i < n; i++) {
		int l, r, h;
		cin >> l >> r >> h;

		pos.push_back(l);
		pos.push_back(r);
		p.push_back({ l ,r ,h });
	}

	if (n == 1) {
		cout << 0;
		return 0;
	}

	sort(pos.begin(), pos.end());
	pos.erase(unique(pos.begin(), pos.end()), pos.end());

	for (auto& i : p) {
		i.l = lower_bound(pos.begin(), pos.end(), i.l) - pos.begin();
		i.r = lower_bound(pos.begin(), pos.end(), i.r) - pos.begin();
	}

	sort(p.begin(), p.end());

	int tn = pos.size();

	int sz = 1;
	while (sz < tn) sz *= 2;

	int ans = 1e9;
	seg = vector<int>(sz * 2, 1e9);
	lazy = vector<int>(sz * 2, -1);

	for (auto i : p) {
		if (i.h == 1) {
			update(0, sz - 1, 1, i.l, i.r, 0);
		}
		else {

			int dp_val = ssum(0, sz - 1, 1, i.l, i.r) + 1;
			dp_val = min(dp_val, (int)1e9);

			if (i.h == k) ans = min(ans, dp_val);
			update(0, sz - 1, 1, i.l, i.r, dp_val);
		}

	}
	
	if (ans == 1e9) ans = -1;
	cout << ans;
}