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

bool K[404][404];
int A[404];
int B[404];

void solve() {
	int n, m, k;
	cin >> n >> m >> k;
	while (k--) {
		int a, b;
		cin >> a >> b;
		K[a][b] = 1;
	}

	maxflow mf(n + m + 2);
	int source = 0;
	int sink = n + m + 1;

	ll tot = 0;
	for (int i = 1; i <= n; i++) {
		int x;
		cin >> x;
		tot += x;
		mf.addEdge(i, sink, x);
	}
	for (int j = 1; j <= m; j++) {
		int x;
		cin >> x;
		tot += x;
		mf.addEdge(source, n + j, x);
	}

	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= m; j++) {
			if (!K[i][j]) { mf.addEdge(n + j, i, INF); }
		}
	}

	ll res = mf.query(source, sink);
	cout << tot - res << '\n';

	vector<int> ans1, ans2;
	for (int i = 1; i <= n; i++) {
		if (mf.level[i] == -1) ans1.push_back(i);
	}
	for (int j = 1; j <= m; j++) {
		if (mf.level[n + j] != -1) ans2.push_back(j);
	}

	cout << (int)ans1.size() << '\n';
	for (auto f : ans1) cout << f << ' ';
	cout << '\n';
	cout << (int)ans2.size() << '\n';
	for (auto f : ans2) cout << f << ' ';
	cout << '\n';
}

int main() {
	std::ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	int t = 1;
	// cin >> t;
	while (t--) { solve(); }
	return 0;
}