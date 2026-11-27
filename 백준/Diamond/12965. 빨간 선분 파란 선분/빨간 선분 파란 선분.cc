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

int rCost[22][22];
int bCost[22][22];

pair<int, int> operator-(pair<int, int> p1, pair<int, int> p2) { return mp(p1.x - p2.x, p1.y - p2.y); }
int cross(pair<int, int> p1, pair<int, int> p2) { return p1.x * p2.y - p1.y * p2.x; }
int dot(pair<int, int> p1, pair<int, int> p2) { return p1.x * p2.x + p1.y * p2.y; }
int sgn(int x) { return (x > 0) - (x < 0); }

bool onSegment(pair<int, int> s, pair<int, int> e, pair<int, int> p) {
	return cross(s - p, e - p) == 0 && dot(s - p, e - p) <= 0;
}
bool intersect(pair<int, int> a, pair<int, int> b, pair<int, int> c, pair<int, int> d) {
	int oc = cross(b - a, c - a), od = cross(b - a, d - a);
	int oa = cross(d - c, a - c), ob = cross(d - c, b - c);

	if (sgn(oa) * sgn(ob) < 0 && sgn(oc) * sgn(od) < 0) return 1;
	if (onSegment(a, b, c)) return 1;
	if (onSegment(a, b, d)) return 1;
	if (onSegment(c, d, a)) return 1;
	if (onSegment(c, d, b)) return 1;
	return 0;
}

void solve() {
	int n;
	cin >> n;

	vector<pair<int, int>> A(n);
	for (auto& [a, b] : A) cin >> a >> b;

	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) { cin >> rCost[i][j]; }
	}
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) { cin >> bCost[i][j]; }
	}

	vector<pair<int, int>> edg;
	for (int i = 0; i < n; i++) {
		for (int j = i + 1; j < n; j++) { edg.push_back(mp(i, j)); }
	}

	int eSz = (int)edg.size();

	int source = 0;
	int sink = 2 * eSz + 1;
	maxflow mf(eSz * 2 + 2);

	for (int j = 0; j < eSz; j++) {
		auto [a, b] = edg[j];
		mf.addEdge(source, j + 1, bCost[a][b]);
		mf.addEdge(j + 1, j + 1 + eSz, rCost[a][b] + bCost[a][b]);
		mf.addEdge(j + 1 + eSz, sink, rCost[a][b]);
	}

	for (int i = 0; i < eSz; i++) {
		auto [a, b] = edg[i];
		for (int j = i + 1; j < eSz; j++) {
			// intersection check
			auto [c, d] = edg[j];
			if (intersect(A[a], A[b], A[c], A[d])) {
				mf.addEdge(i + 1 + eSz, j + 1, INF);
				mf.addEdge(j + 1 + eSz, i + 1, INF);
			}
		}
	}

	int res = mf.query(source, sink);

	int tot = 0;
	for (int i = 0; i < n; i++) {
		for (int j = i + 1; j < n; j++) { tot += rCost[i][j] + bCost[i][j]; }
	}
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