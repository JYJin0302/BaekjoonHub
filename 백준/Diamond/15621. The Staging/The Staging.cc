#include <bits/stdc++.h>
using namespace std;

using ll = unsigned long long;
using ld = long double;

#define all(x) begin(x), end(x)
#define x first
#define y second
#define mp make_pair

int P[202020];
int T[202020];
int O[202020];  // cycle 순서대로 배치

int G[202020];
int Pos[202020];

const int INF = 1e9 + 10;
pair<int, int> groupRange[202020];
set<pair<int, int>> groupTime[202020];

array<int, 4> seg[606060];
// 가장 왼쪽의 사람이 총을 쏘는 경우 {총 사격 횟수, 가장 오른쪽 사람의 총 쏘는 시간 ; 죽었으면 INF}
// ''             총을 못 쏘는 경우

array<int, 4> merge(array<int, 4> a1, array<int, 4> a2, int gunTime) {  // a2의 가장 왼쪽 사람의 총 쏘는 시간
	array<int, 4> ret = {0, 0, 0, 0};
	if (a1[1] < gunTime) {
		ret[0] = a1[0] + a2[2];
		ret[1] = a2[3];
	} else {
		ret[0] = a1[0] + a2[0];
		ret[1] = a2[1];
	}

	if (a1[3] < gunTime) {
		ret[2] = a1[2] + a2[2];
		ret[3] = a2[3];
	} else {
		ret[2] = a1[2] + a2[0];
		ret[3] = a2[1];
	}
	return ret;
}

void init(int l, int r, int n) {
	if (l == r) {
		int v = O[l];
		seg[n] = {1, T[v], 0, INF};
		return;
	}
	int md = (l + r) >> 1;
	init(l, md, n * 2);
	init(md + 1, r, n * 2 + 1);
	seg[n] = merge(seg[n * 2], seg[n * 2 + 1], T[O[md + 1]]);
}

void update(int l, int r, int n, int ix) {
	if (l > ix || r < ix) return;
	if (l == ix && r == ix) {
		int v = O[l];
		seg[n] = {1, T[v], 0, INF};
		return;
	}
	int md = (l + r) >> 1;
	update(l, md, n * 2, ix);
	update(md + 1, r, n * 2 + 1, ix);
	seg[n] = seg[n] = merge(seg[n * 2], seg[n * 2 + 1], T[O[md + 1]]);
}

array<int, 4> getS(int l, int r, int n, int sl, int sr) {
	if (l > sr || r < sl) return {-1, -1, -1, -1};
	if (l >= sl && r <= sr) return seg[n];

	int md = (l + r) >> 1;
	if (md < sl) return getS(md + 1, r, n * 2 + 1, sl, sr);
	if (md + 1 > sr) return getS(l, md, n * 2, sl, sr);
	return merge(getS(l, md, n * 2, sl, sr), getS(md + 1, r, n * 2 + 1, sl, sr), T[O[md + 1]]);
}

void solve() {
	int n;
	cin >> n;
	for (int i = 1; i <= n; i++) cin >> P[i];
	for (int i = 1; i <= n; i++) cin >> T[i];

	// set group
	int p = 1;
	for (int i = 1; i <= n; i++) {
		if (G[i] != 0) continue;
		int cur = i;
		int L = p;

		while (G[cur] == 0) {
			G[cur] = i;
			O[p] = cur;
			Pos[cur] = p++;
			cur = P[cur];
		}

		groupRange[i] = mp(L, p - 1);
	}

	for (int i = 1; i <= n; i++) {
		int g = G[i];
		groupTime[g].insert(mp(T[i], i));
	}

	init(1, n, 1);

	vector<int> groupAns(n + 1);
	int ans = 0;
	for (int i = 1; i <= n; i++) {
		if (G[i] == i) {
			// cout << " GO :" << i << '\n';
			auto [l, r] = groupRange[i];
			int f = (*groupTime[i].begin()).y;

			array<int, 4> ret;
			if (Pos[f] == l) ret = getS(1, n, 1, l, r);
			else ret = merge(getS(1, n, 1, Pos[f], r), getS(1, n, 1, l, Pos[f] - 1), T[O[l]]);

			// cout << ret[0] << ' ' << ret[1] << ' ' << ret[2] << ' ' << ret[3] << '\n';
			ans += ret[0];
			groupAns[i] = ret[0];
		}
	}

	cout << n - ans << '\n';

	int q;
	cin >> q;
	while (q--) {
		int x, t;
		cin >> x >> t;

		int gNum = G[x];
		ans -= groupAns[gNum];

		int pos = Pos[x];

		groupTime[gNum].erase(mp(T[x], x));
		T[x] = t;
		groupTime[gNum].insert(mp(T[x], x));

		// cout << " Phase 1" << endl;
		//  update
		update(1, n, 1, pos);
		// cout << " p2 " << endl;

		// get answer for gNum
		auto [l, r] = groupRange[gNum];
		int f = (*groupTime[gNum].begin()).y;

		array<int, 4> ret;
		if (Pos[f] == l) ret = getS(1, n, 1, l, r);
		else ret = merge(getS(1, n, 1, Pos[f], r), getS(1, n, 1, l, Pos[f] - 1), T[O[l]]);

		// cout << ret[0] << ' ' << ret[1] << ' ' << ret[2] << ' ' << ret[3] << '\n';
		ans += ret[0];
		groupAns[gNum] = ret[0];

		cout << n - ans << '\n';
	}
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);

	int t = 1;
	// cin >> t;
	for (int i = 0; i < t; i++) { solve(); }
	return 0;
}