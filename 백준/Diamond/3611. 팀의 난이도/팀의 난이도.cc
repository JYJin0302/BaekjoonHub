#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using ld = long double;

#define mp make_pair
#define x first
#define y second
#define all(x) x.begin(), x.end()

const ll INF = 1e16;

struct maxflow {
	struct edge {
		int u, v;
		ll c, f = 0;
		edge(int u, int v, ll c) : u(u), v(v), c(c) {}
	};

	int N, M = 0, s, t;
	vector<edge> E;
	vector<int> level, see;
	vector<vector<int>> adj;
	queue<int> que;
	maxflow(int N) : N(N) {
		level.resize(N);
		see.resize(N);
		adj.resize(N);
	}
	void addEdge(int u, int v, ll c, bool undirected = 0) {
		if (undirected) {
			E.emplace_back(u, v, c);
			E.emplace_back(v, u, c);
		} else {
			E.emplace_back(u, v, c);
			E.emplace_back(v, u, 0);
		}
		adj[u].push_back(M);
		adj[v].push_back(M + 1);
		M += 2;
	}
	bool bfs() {
		fill(level.begin(), level.end(), -1);
		que.push(s);
		level[s] = 0;
		while (!que.empty()) {
			int u = que.front();
			que.pop();
			for (int& e : adj[u]) {
				int v = E[e].v;
				if (E[e].c - E[e].f > 0 && level[v] == -1) {
					level[v] = level[u] + 1;
					que.push(v);
				}
			}
		}

		return (level[t] != -1);
	}
	ll dfs(int u, ll flow) {
		if (u == t) { return flow; }
		if (flow == 0) { return 0; }
		for (int& i = see[u]; i < (int)adj[u].size(); i++) {
			int e = adj[u][i];
			ll sp = E[e].c - E[e].f;
			int v = E[e].v;
			if (sp > 0 && level[v] == level[u] + 1) {
				ll f = dfs(v, min(flow, sp));
				if (f > 0) {
					E[e].f += f;
					E[e ^ 1].f -= f;
					return f;
				}
			}
		}
		return 0;
	}
	ll query(int s, int t) {
		ll ans = 0;
		this->s = s;
		this->t = t;
		while (bfs()) {
			fill(see.begin(), see.end(), 0);
			while (ll flow = dfs(s, INF)) { ans += flow; }
		}
		return ans;
	}
};

int deg[101];

void solve() {
	int n, m;
	cin >> n >> m;

	vector<pair<int, int>> edg;
	for (int i = 0; i < m; i++) {
		int a, b;
		cin >> a >> b;
		edg.push_back(mp(a, b));
		deg[a]++;
		deg[b]++;
	}

	if (n == 1 || m == 0) {
		cout << "1\n1\n";
		return;
	}

	vector<pair<int, int>> tar;
	for (int i = 2; i <= n; i++) {
		for (int j = i - 1; j <= i * (i - 1) / 2; j++) {
			int g = gcd(j, i);
			tar.push_back(mp(j / g, i / g));
		}
	}

	tar.push_back(mp(0, 1));
	sort(all(tar), [&](pair<int, int> p1, pair<int, int> p2) { return p1.x * p2.y < p2.x * p1.y; });
	tar.erase(unique(all(tar)), tar.end());

	int l = 1, r = (int)tar.size() - 1;
	while (l <= r) {
		int md = (l + r) >> 1;

		int a = tar[md].x + tar[md - 1].x;
		int b = tar[md].y + tar[md - 1].y;
		// cout << "Test: " << a << '/' << b << '\n';
		//  test a/b
		maxflow mf(n + 2);
		int source = 0;
		int sink = n + 1;

		int tot = 2 * b * m;
		for (int i = 1; i <= n; i++) {
			mf.addEdge(source, i, 2 * a);
			mf.addEdge(i, sink, deg[i] * b);
		}

		for (auto [u, v] : edg) { mf.addEdge(u, v, b, 1); }

		ll res = mf.query(source, sink);
		// cout << tot << ' ' << res << '\n';
		// cout << "Used: ";
		//  for (int j = 1; j <= n; j++) {
		//  	if (mf.level[j] == -1) cout << j << ' ';
		//  }
		//  cout << '\n';
		if (tot - res > 0) {
			// ok
			l = md + 1;
		} else {
			r = md - 1;
		}
	}

	// cout << tar[r].x << ' ' << tar[r].y << '\n';
	auto [a, b] = tar[r];
	maxflow mf(n + 2);
	int source = 0;
	int sink = n + 1;

	int tot = 2 * b * m;
	for (int i = 1; i <= n; i++) {
		mf.addEdge(source, i, 2 * a);
		mf.addEdge(i, sink, deg[i] * b);
	}

	for (auto [u, v] : edg) { mf.addEdge(u, v, b, 1); }

	ll res = mf.query(source, sink);

	vector<int> ans;
	for (int i = 1; i <= n; i++) {
		if (mf.level[i] == -1) ans.push_back(i);
	}
	cout << (int)ans.size() << '\n';
	for (auto f : ans) cout << f << ' ';
	cout << '\n';
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