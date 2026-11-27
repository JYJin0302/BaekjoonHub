#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using pii = pair<ll, ll>;
#define mp make_pair
#define all(x) x.begin(), x.end()

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
    vector<int> getAns(int n) {
        vector<int> res;
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
        for (int i = 1; i <= n; i++) {
            if (level[i*2-1] != -1 && level[i * 2] == -1) res.push_back(i);
        }

        return res;
    }
};

void solve() {

    int n, m, s, e;
    cin >> n >> m >> s >> e;

    maxflow g(n * 2 + 10);
    for (int i = 1; i <= n; i++) {
        ll x;
        cin >> x;
        g.addEdge(i * 2 - 1, i * 2, x, 0);
    }
    
    while (m--) {
        int a, b;
        cin >> a >> b;

        g.addEdge(a * 2, b * 2 - 1, LLINF, 0);
        g.addEdge(b * 2, a * 2 - 1, LLINF, 0);
    }

    ll res = g.query(s*2-1, e*2);
    vector<int> ans = g.getAns(n);
    for (auto f : ans) cout << f << ' ';
    cout << '\n';
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    int t = 1;
    //cin >> t;
    while (t--) solve();
}