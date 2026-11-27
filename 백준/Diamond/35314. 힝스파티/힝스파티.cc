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

char G[155][155];

int dx[] = {-1, 0, 1, 0};
int dy[] = {0, 1, 0, -1};

void solve() {
	int n, m;
	cin >> n >> m;

	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) { cin >> G[i][j]; }
	}

	int source = 0;
	int ccnt = 0;
	if (n > 2) ccnt += (n - 2) * m;
	if (m > 2) ccnt += n * (m - 2);
	int sink = n * m + ccnt + 1;

	int tot = ccnt;
	maxflow mf(sink + 1);

	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			char c = G[i][j];
			int ix = i * m + j + 1;
			if ((i + j) & 1) {
				if (c == '.') {
				} else if (c == '-') {
					mf.addEdge(source, ix, INF);
				} else if (c == '^') {
					mf.addEdge(ix, sink, INF);
				}
			} else {
				if (c == '.') {
				} else if (c == '^') {
					mf.addEdge(source, ix, INF);
				} else if (c == '-') {
					mf.addEdge(ix, sink, INF);
				}
			}
		}
	}

	int o = n * m + 1;
	// vertical
	for (int i = 1; i < n - 1; i++) {
		for (int j = 0; j < m; j++) {
			int ix = i * m + j + 1;
			int ixU = ix - m;
			int ixD = ix + m;
			if ((i + j) & 1) {
				mf.addEdge(ix, o, INF);
				mf.addEdge(ixU, o, INF);
				mf.addEdge(ixD, o, INF);
				mf.addEdge(o, sink, 1);
			} else {
				mf.addEdge(o, ix, INF);
				mf.addEdge(o, ixU, INF);
				mf.addEdge(o, ixD, INF);
				mf.addEdge(source, o, 1);
			}
			o++;
		}
	}

	// horiz
	for (int j = 1; j < m - 1; j++) {
		for (int i = 0; i < n; i++) {
			int ix = i * m + j + 1;
			int ixU = ix - 1;
			int ixD = ix + 1;
			if ((i + j) & 1) {
				mf.addEdge(ix, o, INF);
				mf.addEdge(ixU, o, INF);
				mf.addEdge(ixD, o, INF);
				mf.addEdge(o, sink, 1);
			} else {
				mf.addEdge(o, ix, INF);
				mf.addEdge(o, ixU, INF);
				mf.addEdge(o, ixD, INF);
				mf.addEdge(source, o, 1);
			}
			o++;
		}
	}

	ll res = mf.query(source, sink);
	cout << tot - res << '\n';
}

int main() {
	std::ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	int t = 1;
	// cin >> t;
	while (t--) { solve(); }
	return 0;
}