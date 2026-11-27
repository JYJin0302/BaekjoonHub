#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using ld = long double;

#define mp make_pair
#define x first
#define y second
#define all(x) x.begin(), x.end()

const ll INF = 1e16;
int n, K;

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

int A[55][55];
int B[55][55];
int dx[] = {-1, 0, 1, 0};
int dy[] = {0, 1, 0, -1};
bool inGrid(int x, int y) { return x >= 0 && x < n && y >= 0 && y < n; }
int cost[55][55][3];

void solve() {
	cin >> n >> K;

	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) { cin >> A[i][j]; }
	}
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) { cin >> B[i][j]; }
	}

	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			// 0, 1 ,2 : pos, 0, neg
			cost[i][j][0] = B[i][j] * max(0, 1 - A[i][j]);
			cost[i][j][1] = B[i][j] * abs(A[i][j]);
			cost[i][j][2] = B[i][j] * max(0, A[i][j] + 1);
		}
	}

	int source = 0;
	int sink = n * n * 2 + 1;
	maxflow mf(n * n * 2 + 2);

	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			int ix1 = i * n + j + 1;
			int ix2 = ix1 + n * n;
			int adjCnt = 4;
			if (i == 0) adjCnt--;
			if (i == n - 1) adjCnt--;
			if (j == 0) adjCnt--;
			if (j == n - 1) adjCnt--;

			mf.addEdge(ix2, ix1, INF);
			if ((i + j) & 1) {
				mf.addEdge(source, ix1, cost[i][j][2]);
				mf.addEdge(ix1, ix2, cost[i][j][1] + adjCnt * 3 * K);
				mf.addEdge(ix2, sink, cost[i][j][0]);
			} else {
				mf.addEdge(source, ix1, cost[i][j][0]);
				mf.addEdge(ix1, ix2, cost[i][j][1] + adjCnt * 3 * K);
				mf.addEdge(ix2, sink, cost[i][j][2]);

				for (int d = 0; d < 4; d++) {
					int ni = i + dx[d];
					int nj = j + dy[d];
					if (inGrid(ni, nj)) {
						int tx1 = ni * n + nj + 1;
						int tx2 = tx1 + n * n;

						mf.addEdge(ix1, tx1, 1 * K, 1);
						mf.addEdge(ix2, tx2, 1 * K, 1);
						mf.addEdge(ix2, tx1, 6 * K);
						mf.addEdge(tx2, ix1, 6 * K);
					}
				}
			}
		}
	}

	int tot = 2 * n * (n - 1) * 4 * K;
	int res = mf.query(source, sink);
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