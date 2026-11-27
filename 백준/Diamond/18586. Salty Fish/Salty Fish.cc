#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using ld = long double;

#define mp make_pair
#define x first
#define y second
#define all(x) x.begin(), x.end()

vector<int> adj[303030];
ll A[303030];
vector<pair<ll, ll>> cam[303030];
int D[303030];

multiset<pair<ll, ll>> st[303030];
ll res;
void dfs(int v) {
	st[v].clear();

	for (auto f : adj[v]) {
		D[f] = D[v] + 1;
		dfs(f);
		// merge
		if ((int)st[v].size() < (int)st[f].size()) { swap(st[v], st[f]); }
		for (auto d : st[f]) st[v].insert(d);
	}

	st[v].insert(mp(D[v], A[v]));

	// cout << "V : " << v << " => ";
	// for (auto [a, b] : st[v]) cout << a << ' ' << b << " | ";
	// cout << '\n';

	// go match
	for (auto [a, b] : cam[v]) {
		a += D[v];
		auto iter = st[v].lower_bound(mp(a + 1, -1));
		while (iter != st[v].begin()) {
			iter--;
			auto [c, d] = *iter;
			iter = st[v].erase(iter);

			//cout << "Go match: " << a << ' ' << b << ' ' << c << ' ' << d << '\n';
			ll val = min(b, d);
			res += val;
			b -= val;
			d -= val;

			if (d) { st[v].insert(mp(c, d)); }
			if (!b) break;
		}
	}
}

void solve() {
	int n, m;
	cin >> n >> m;

	for (int i = 1; i <= n; i++) {
		adj[i].clear();
		cam[i].clear();
	}

	for (int i = 2; i <= n; i++) {
		int p;
		cin >> p;
		adj[p].push_back(i);
	}

	for (int i = 1; i <= n; i++) cin >> A[i];

	while (m--) {
		int a, b, c;
		cin >> a >> b >> c;
		cam[a].push_back(mp(b, c));
	}

	ll tot = 0;
	for (int i = 1; i <= n; i++) tot += A[i];
	res = 0;
	dfs(1);

	cout << tot - res << '\n';
}

int main() {
	std::ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	int t = 1;
	cin >> t;
	for (int i = 1; i <= t; i++) {
		// cout << "Case #" << i << ": ";
		solve();
	}
	return 0;
}