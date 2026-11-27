#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using ld = long double;

#define mp make_pair
#define x first
#define y second
#define all(x) x.begin(), x.end()

int A[202020];
set<int> iLst[22];

int segDistinct[606060];
void updateDistinct(int l, int r, int n, int ix, int val) {
	if (l > ix || r < ix) return;
	if (l == ix && r == ix) {
		segDistinct[n] = val;
		return;
	}
	int md = (l + r) >> 1;
	updateDistinct(l, md, n * 2, ix, val);
	updateDistinct(md + 1, r, n * 2 + 1, ix, val);
	segDistinct[n] = segDistinct[n * 2] | segDistinct[n * 2 + 1];
}

int getDistinct(int l, int r, int n, int sl, int sr) {
	if (l > sr || r < sl) return 0;
	if (l >= sl && r <= sr) { return segDistinct[n]; }
	int md = (l + r) >> 1;
	int v1 = getDistinct(l, md, n * 2, sl, sr);
	int v2 = getDistinct(md + 1, r, n * 2 + 1, sl, sr);
	return v1 | v2;
}

int D[202020];       // distinct 값들
int fw[21][202020];  // distinct 값이 x 인 index들에 fw[x][idx] = 1
void update(int ix, int val, int d) {
	while (ix <= 200020) {
		fw[val][ix] += d;
		ix += ix & -ix;
	}
}

int getS(int ix, int val) {
	int res = 0;
	while (ix) {
		res += fw[val][ix];
		ix -= ix & -ix;
	}
	return res;
}

void solve() {
	int n, q;
	cin >> n >> q;

	for (int i = 1; i <= n; i++) {
		cin >> A[i];
		iLst[A[i]].insert(i);
	}

	for (int j = 1; j <= 20; j++) iLst[j].insert(0);

	for (int i = 1; i <= n; i++) { updateDistinct(1, n, 1, i, (1 << A[i] - 1)); }
	for (int j = 1; j <= 20; j++) {
		auto iter = iLst[j].begin();
		while (1) {
			int cur = *iter;
			iter++;
			if (iter == iLst[j].end()) break;
			int nxt = *iter;
			D[nxt] = __builtin_popcount(getDistinct(1, n, 1, cur + 1, nxt - 1));
			update(nxt, D[nxt], 1);
		}
	}

	while (q--) {
		int t;
		cin >> t;
		if (t == 1) {
			int ix, x;
			cin >> ix >> x;

			if (A[ix] == x) continue;

			iLst[A[ix]].erase(ix);
			vector<int> upd(22, -1);
			for (int i = 1; i <= 20; i++) {
				auto iter = iLst[i].lower_bound(ix);
				if (iter == iLst[i].end()) {
				} else {
					upd[i] = *iter;
				}
			}

			A[ix] = x;
			updateDistinct(1, n, 1, ix, (1 << x - 1));
			iLst[x].insert(ix);
			// update ix
			auto iter = iLst[x].find(ix);
			int cur = ix;
			int pre = *(--iter);
			update(ix, D[ix], -1);
			D[ix] = __builtin_popcount(getDistinct(1, n, 1, pre + 1, cur - 1));
			update(ix, D[ix], 1);

			// update 1 ~ 20
			for (int j = 1; j <= 20; j++) {
				if (upd[j] == -1) continue;
				auto iter = iLst[j].find(upd[j]);
				int cur = *iter;
				int pre = *(--iter);

				update(cur, D[cur], -1);
				D[cur] = __builtin_popcount(getDistinct(1, n, 1, pre + 1, cur - 1));
				update(cur, D[cur], 1);
			}

		} else {
			int l, r, k;
			cin >> l >> r >> k;

			int ans = 0;
			vector<pair<int, int>> prev(22);
			for (int j = 1; j <= 20; j++) {
				auto iter = iLst[j].lower_bound(l);
				if (iter == iLst[j].end() || (*iter) > r) prev[j] = mp(-1, -1);
				else {
					int ix = *iter;
					prev[j] = mp(ix, D[ix]);

					// temporary
					int newV = getDistinct(1, n, 1, l, ix - 1);
					update(ix, D[ix], -1);
					ans++;
				}
			}

			for (int j = k; j <= 20; j++) { ans += getS(r, j) - getS(l - 1, j); }

			cout << ans << '\n';
			for (int j = 1; j <= 20; j++) {
				if(prev[j].x == -1) continue;

				auto[ix, val] = prev[j];
				D[ix] = val;
				update(ix, val, 1);
			}
		}
	}
}

int main() {
	std::ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	int t = 1;
	// cin >> t;
	while (t--) { solve(); }
	return 0;
}