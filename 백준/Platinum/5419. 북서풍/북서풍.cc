#include <bits/stdc++.h>
using ll = long long;
using namespace std;

int dx[] = { 0, -1, 0, 1 };
int dy[] = { 1, 0, -1, 0 };
#define INF 100000000
#define pb push_back
#define all(x) (x).begin(),(x).end()

bool cmp(pair<int, int> p1, pair<int, int> p2) {
	if (p1.first == p2.first) return p1.second > p2.second;
	return p1.first < p2.first;
}

vector<int> seg;

void update(int l, int r, int n, int u) {
	if (l > u || r < u) return;
	if (l == u && r == u) {
		seg[n]++;
		return;
	}

	int mid = (l + r) / 2;
	update(l, mid, n*2, u);
	update(mid + 1, r, n * 2 + 1, u);
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

		int n;
		cin >> n;

		int size = 1;
		while (size < n) size *= 2;

		seg = vector<int>(size * 2);
		vector<int> yc;
		vector<pair<int, int>> A;
		for (int i = 0; i < n; i++) {
			int a, b;
			cin >> a >> b;
			A.push_back({ a,b });
			yc.push_back(b);
		}

		sort(all(A), cmp);
		map<int, int> itov;

		sort(all(yc));
		int ind = 1;
		itov[yc[0]] = 0;
		for (int i = 1; i < n; i++) {
			if (yc[i] == yc[i - 1]) continue;
			itov[yc[i]] = ind++;
		}

		ll ans = 0;
		for (auto i : A) {
			int a, b;
			tie(a, b) = i;

			int ind = itov[b];
			ans += subsum(size, size * 2 - 1, 1, size + ind, size * 2 - 1);
			update(size, size * 2 - 1, 1, size + ind);
		}
		cout << ans << '\n';
	}
}