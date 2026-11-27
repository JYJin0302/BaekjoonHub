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

int n, m;
bool inGrid(int x, int y) { return x >= 0 && x < n && y >= 0 && y < m; }
char A[101][101], B[101][101];
int dx[] = {-1, 0, 1,0};
int dy[] = {0, 1, 0, -1};

int G[101][101];
int T[10101];
array<int, 2> rec[10101];

int gCnt = 0;
void solve() {
	cin >> n >> m;

	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) { cin >> A[i][j]; }
	}
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) { cin >> B[i][j]; }
	}

	memset(G, -1, sizeof G);
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			if (G[i][j] != -1) continue;

			array<int, 2> cnt = {0, 0};
			queue<pair<int, int>> q;
			G[i][j] = ++gCnt;
			T[gCnt] = A[i][j] - '0';
			q.push(mp(i, j));
			while (!q.empty()) {
				auto [a, b] = q.front();
				q.pop();
				cnt[B[a][b] - '0']++;
				for (int d = 0; d < 4; d++) {
					int ni = i + dx[d];
					int nj = j + dy[d];
					if (inGrid(ni, nj) && A[ni][nj] == A[a][b] && G[ni][nj] == -1) {
						G[ni][nj] = gCnt;
						q.push(mp(ni, nj));
					}
				}
			}
			rec[gCnt] = cnt;
		}
	}

	vector<pair<int, int>> edg;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			for (int d = 0; d < 4; d++) {
				int ni = i + dx[d];
				int nj = j + dy[d];
				if (inGrid(ni, nj) && G[i][j] != G[ni][nj]) { edg.push_back(mp(G[i][j], G[ni][nj])); }
			}
		}
	}
	sort(all(edg));
	edg.erase(unique(all(edg)), edg.end());

	maxflow mf(gCnt + 2);
	int source = 0;
	int sink = gCnt + 1;

	for(int i = 1; i <= gCnt; i++){
		if(T[i]){
			mf.addEdge(source, i, rec[i][0]);
			mf.addEdge(i, sink, rec[i][1]);
		} else {
			mf.addEdge(source, i, rec[i][0]);
			mf.addEdge(i, sink, rec[i][1]);
		}
	}
	for(auto [a,b] : edg){
		if(T[a] == 0) swap(a, b);
		mf.addEdge(a, b, INF);
	}

	int v = mf.query(source, sink);
	cout << v<< '\n';
}

int main() {
	std::ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	int t = 1;
	// cin >> t;
	while (t--) { solve(); }
	return 0;
}