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

int G[55][55];

int dx[] = {-1, -1, 1, 1, 0};
int dy[] = {-1, 1, -1, 1, 0};

void solve() {
	int n, k;
	cin >> n >> k;

	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) { cin >> G[i][j]; }
	}

	int source = 0;
	int kCnt = 0;
	if (n >= 2) kCnt = (n - 2) * (n - 2);
	int sink = n * n + kCnt + 1;
	maxflow mf(sink + 1);

	int ans = kCnt * k;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			int ix = i * n + j + 1;
			if ((i + j) & 1) {
				if (G[i][j] > 0) {
					mf.addEdge(ix, sink, G[i][j]);
					ans += G[i][j];
				} else if (G[i][j] < 0) {
					mf.addEdge(source, ix, -G[i][j]);
				}
			} else {
				if (G[i][j] > 0) {
					mf.addEdge(source, ix, G[i][j]);
					ans += G[i][j];
				} else if (G[i][j] < 0) {
					mf.addEdge(ix, sink, -G[i][j]);
				}
			}
		}
	}

	// adjecent
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			if ((i + j) & 1) continue;
			int ix = i * n + j + 1;

			if (j != n - 1) {
				int ix2 = ix + 1;
				mf.addEdge(ix, ix2, INF);
			}
			if (j != 0) {
				int ix2 = ix - 1;
				mf.addEdge(ix, ix2, INF);
			}

			if (i != n - 1) {
				int ix2 = ix + n;
				mf.addEdge(ix, ix2, INF);
			}
			if (i != 0) {
				int ix2 = ix - n;
				mf.addEdge(ix, ix2, INF);
			}
		}
	}

	// K
	for (int i = 1; i < n - 1; i++) {
		for (int j = 1; j < n - 1; j++) {
			if ((i + j) & 1) {
				int idx = (i - 1) * (n - 2) + (j - 1) + n * n + 1;

				mf.addEdge(idx, sink, k);
				for (int d = 0; d < 5; d++) {
					int ni = i + dx[d];
					int nj = j + dy[d];

					int idx2 = ni * n + nj + 1;
					mf.addEdge(idx2, idx, INF);
				}

			} else {
				int idx = (i - 1) * (n - 2) + (j - 1) + n * n + 1;

				mf.addEdge(source, idx, k);
				for (int d = 0; d < 5; d++) {
					int ni = i + dx[d];
					int nj = j + dy[d];

					int idx2 = ni * n + nj + 1;
					mf.addEdge(idx, idx2, INF);
				}
			}
		}
	}

	// cout << "EDGe list\n";
	// for (auto f : mf.E) { cout << f.u << ' ' << f.v << ' ' << f.c << '\n'; }

	ll res = mf.query(source, sink);

	cout << ans - res << '\n';
}

int main() {
	std::ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	int t = 1;
	// cin >> t;
	while (t--) { solve(); }
	return 0;
}