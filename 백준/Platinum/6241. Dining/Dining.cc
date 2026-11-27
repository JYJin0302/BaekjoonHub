#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define mp make_pair
#define all(x) x.begin(), x.end()
#define x first
#define y second

const ll LLINF = 1e18;
struct maxflow {
    struct edge {
        int u, v;
        ll c, f = 0;
        edge(int u, int v, ll c) :u(u), v(v), c(c) {}
    };
    int N, M = 0, s, t;
    vector<edge> E;
    vector<int> level, see;
    vector<vector<int>> adj;
    queue<int> que;
    maxflow(int N) :N(N) {
        level.resize(N); see.resize(N); adj.resize(N);
    }
    void addEdge(int u, int v, ll c, bool undirected = 0) {
        if (undirected) {
            E.emplace_back(u, v, c);
            E.emplace_back(v, u, c);
        }
        else {
            E.emplace_back(u, v, c);
            E.emplace_back(v, u, 0);
        }
        adj[u].push_back(M);
        adj[v].push_back(M + 1);
        M += 2;
    }
    bool bfs() {
        fill(level.begin(), level.end(), -1);
        que.push(s); level[s] = 0;
        while (!que.empty()) {
            int u = que.front(); que.pop();
            for (int& e : adj[u]) {
                int v = E[e].v;
                if (E[e].c - E[e].f > 0 && level[v] == -1) {
                    level[v] = level[u] + 1; que.push(v);
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
        this->s = s; this->t = t;
        while (bfs()) {
            fill(see.begin(), see.end(), 0);
            while (ll flow = dfs(s, LLINF)) {
                ans += flow;
            }
        }
        return ans;
    }
};

void solve() {

    int n, f, d;
    cin >> n >> f >> d;


    int t = 2*n + d + f + 1;
    maxflow g(t+2);
    for (int i = 1; i <= f; i++) {
        g.addEdge(0, 2*n + i, 1);
    }
    for (int i = 1; i <= d; i++) {
        g.addEdge(2*n + f + i, t, 1);
    }
    for (int i = 1; i <= n; i++) {
        g.addEdge(i, i + n, 1);
    }

    for (int i = 1; i <= n; i++) {
        int a, b;
        cin >> a >> b;
        while (a--) {
            int x;
            cin >> x;
            g.addEdge(2*n + x, i, 1);
        }
        while (b--) {
            int x;
            cin >> x;
            g.addEdge(i + n, 2*n + f + x, 1);
        }
    }

    ll ans = g.query(0, t);
    cout << ans;

}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    int t = 1;
    // cin >> t;
    while (t--) solve();
}