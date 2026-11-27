#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using ld = long double;

#define mp make_pair
#define x first
#define y second
#define all(x) x.begin(), x.end()

const ll INF = 1e16;

array<int, 4> decode(int ix);
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
					// cout << "Visite: ";
					// auto rr = decode(v);
					// for (int a = 0; a < 4; a++) cout << rr[a] << ' ';
					// cout << '\n';
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
			while (ll flow = dfs(s, INF)) {
				ans += flow;
			}
		}
		return ans;
	}
};

char G[55][55];
int dx[] = {-1, 0, 2, 0};
int dy[] = {0, 2, 0, -1};
int n;
bool inGrid(int x, int y) { return x >= 1 && x <= n && y >= 1 && y <= n; }
int getIdx(int x, int y, int dir, bool in) {
	// 0 : base, 1 : origin, 2 : U, 3 : L
	int ix = (x - 1) * n + y - 1;
	ix = (ix << 2) + dir;
	ix = (ix << 1) | in;
	return ix + 1;
}
array<int, 4> decode(int ix) {
	array<int, 4> res;
	ix--;
	res[3] = ix & 1;
	ix >>= 1;
	res[2] = ix & 3;
	ix >>= 2;
	res[1] = ix % n + 1;
	res[0] = ix / n + 1;
	return res;
}

void solve() {
	cin >> n;

	memset(G, 'H', sizeof G);
	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= n; j++) { cin >> G[i][j]; }
	}
	int base = n * n;
	int source = 0;
	maxflow mf(base * 8 + 1);

	int ex, ey;
	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= n; j++) {
			if (G[i][j] == '$') ex = i % 3, ey = j % 3;
		}
	}

	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= n; j++) {
			// base
			int curIn = getIdx(i, j, 0, 0);
			int curOut = getIdx(i, j, 0, 1);
			if (G[i][j] == '.') mf.addEdge(curIn, curOut, 1);
			else if (G[i][j] != 'H') mf.addEdge(curIn, curOut, INF);

			int tmpIn, tmpOut;
			// i, j, O

			if (i % 3 == ex && j % 3 == ey) {
				curIn = getIdx(i, j, 1, 0);
				curOut = getIdx(i, j, 1, 1);

				tmpIn = getIdx(i, j, 0, 0);
				tmpOut = getIdx(i, j, 0, 1);
				mf.addEdge(curIn, tmpIn, INF);
				mf.addEdge(tmpOut, curOut, INF);

				for (int f = 0; f < 4; f++) {
					int ni = i + dx[f];
					int nj = j + dy[f];
					if (inGrid(ni, nj)) {
						tmpIn = getIdx(ni, nj, (f & 1) + 2, 0);
						// int tmpOut = tmpIn ^ 1;
						mf.addEdge(curOut, tmpIn, INF);
					}
				}
			}

			// i, j, U
			if ((i + 1) % 3 == ex && j % 3 == ey) {
				curIn = getIdx(i, j, 2, 0);
				curOut = getIdx(i, j, 2, 1);

				tmpIn = getIdx(i, j, 0, 0);
				tmpOut = getIdx(i, j, 0, 1);
				mf.addEdge(curIn, tmpIn, INF);
				mf.addEdge(tmpOut, curOut, INF);
				if (i != 1) {
					tmpIn = getIdx(i - 1, j, 0, 0);
					tmpOut = getIdx(i - 1, j, 0, 1);
					mf.addEdge(curIn, tmpIn, INF);
					mf.addEdge(tmpOut, curOut, INF);
				}

				if (i - 2 >= 1) {
					// up
					tmpIn = getIdx(i - 2, j, 1, 0);
					mf.addEdge(curOut, tmpIn, INF);
				}
				if (i + 1 <= n) {
					// down
					tmpIn = getIdx(i + 1, j, 1, 0);
					mf.addEdge(curOut, tmpIn, INF);
				}
			}

			// i, j, L
			if (i % 3 == ex && (j + 1) % 3 == ey) {
				curIn = getIdx(i, j, 3, 0);
				curOut = getIdx(i, j, 3, 1);

				tmpIn = getIdx(i, j, 0, 0);
				tmpOut = getIdx(i, j, 0, 1);
				mf.addEdge(curIn, tmpIn, INF);
				mf.addEdge(tmpOut, curOut, INF);
				if (j != 1) {
					tmpIn = getIdx(i, j - 1, 0, 0);
					tmpOut = getIdx(i, j - 1, 0, 1);
					mf.addEdge(curIn, tmpIn, INF);
					mf.addEdge(tmpOut, curOut, INF);
				}

				if (j - 2 >= 1) {
					// left
					tmpIn = getIdx(i, j - 2, 1, 0);
					mf.addEdge(curOut, tmpIn, INF);
				}
				if (j + 1 <= n) {
					// right
					tmpIn = getIdx(i, j + 1, 1, 0);
					mf.addEdge(curOut, tmpIn, INF);
				}
			}
		}
	}

	int sink = -1;
	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= n; j++) {
			if (G[i][j] == 'b' && i % 3 == ex && j % 3 == ey) {
				int ix = getIdx(i, j, 1, 0);
				mf.addEdge(source, ix, INF);
			} else if (G[i][j] == '$') {
				sink = getIdx(i, j, 1, 1);
			}
		}
	}

	ll res = mf.query(source, sink);
	if (res == INF) res = -1;
	cout << res << '\n';
}

int main() {
	std::ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	int t = 1;
	// cin >> t;
	while (t--) { solve(); }
	return 0;
}