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

int C[505][505];

void solve() {
	int n;
	cin >> n;

	vector<int> A(n);
	for (auto& i : A) cin >> i;

	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) { cin >> C[i][j]; }
	}

	int source = 0;
	int sink = n + 1;

	maxflow mf(n + 2);
	for (int i = 0; i < n; i++) {
		if (A[i] == 1) {
			mf.addEdge(i + 1, sink, INF);
		} else if (A[i] == 2) {
			mf.addEdge(source, i + 1, INF);
		}
	}

	for (int i = 0; i < n; i++) {
		for (int j = i + 1; j < n; j++) {
			int c = C[i][j];
			if (c) mf.addEdge(i + 1, j + 1, c, 1);
		}
	}

	ll res = mf.query(source, sink);
	cout << res << '\n';

	mf.bfs();
	vector<int> ansA, ansB;
	for (int i = 1; i <= n; i++) {
		if (mf.level[i] != -1) ansB.push_back(i);
		else ansA.push_back(i);
	}

	for (auto f : ansA) cout << f << ' ';
	cout << '\n';
	for (auto f : ansB) cout << f << ' ';
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