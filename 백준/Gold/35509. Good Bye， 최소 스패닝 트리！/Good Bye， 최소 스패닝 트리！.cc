#include <bits/stdc++.h>
using namespace std;
using ll = long long;

#define mp make_pair
#define x first
#define y second
#define all(x) x.begin(), x.end()

int root[101010];
int find(int n) {
	if (root[n] == n) return n;
	return root[n] = find(root[n]);
}

void solve() {
	int n, m;
	cin >> n >> m;

	vector<array<int, 4>> edg;

	vector<int> eW(m + 1);
	for (int i = 1; i <= m; i++) {
		int w, a, b;
		cin >> a >> b >> w;
		eW[i] = w;
		edg.push_back({w, a, b, i});
	}
	sort(all(edg));

	// mst not mbst
	cout << "NO\n";

	// mst
	for (int i = 1; i <= n; i++) root[i] = i;

	int maxW = 0;

	ll ans1 = 0;

	vector<bool> used(m + 1);
	for (auto f : edg) {
		int u = f[1], v = f[2];
		int w = f[0], idx = f[3];

		int fu = find(u), fv = find(v);
		if (fu != fv) {
			root[fu] = fv;
			maxW = w;
			ans1 += w;
		}
	}

	ll ans2 = 0;
	reverse(all(edg));
	for (int i = 1; i <= n; i++) root[i] = i;
	for (auto f : edg) {
		int u = f[1], v = f[2];
		int w = f[0], idx = f[3];

		if (w > maxW) continue;

		int fu = find(u), fv = find(v);
		if (fu != fv) {
			root[fu] = fv;
			ans2 += w;
			used[idx] = 1;
		}
	}

	// mbst not mst
	if (ans1 != ans2) {
		cout << "YES\n";
		for (int i = 1; i <= m; i++)
			if (used[i]) cout << i << '\n';
	} else cout << "NO\n";
}

int main() {
	std::ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	int t = 1;
	// cin >> t;
	while (t--) { solve(); }
	return 0;
}