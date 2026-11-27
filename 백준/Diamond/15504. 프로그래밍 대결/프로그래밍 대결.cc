#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define mp make_pair
#define all(x) x.begin(), x.end()
#define pii pair<ll, ll>

const ll LLINF = 1e17;

struct mcmf {
    struct edge {
        int u, v;
        ll c, w, f = 0;
        edge(int u, int v, ll c, ll w) :u(u), v(v), c(c), w(w) {}
    };
    int N, s, t, M = 0;
    vector<edge> E;
    vector<int> back;
    vector<ll> dis, flow;
    vector<vector<int>> adj;
    queue<int> que;
    mcmf(int N) :N(N) {
        adj.resize(N);
        back.resize(N);
        flow.resize(N);
        dis.resize(N);
    }
    void addEdge(int u, int v, ll c, ll w) {
        E.emplace_back(u, v, c, w);
        E.emplace_back(v, u, 0, -w);
        adj[u].push_back(M);
        adj[v].push_back(M + 1);
        M += 2;
    }
    void spfa() {
        fill(back.begin(), back.end(), -1);
        fill(flow.begin(), flow.end(), 0);
        fill(dis.begin(), dis.end(), LLINF);
        dis[s] = 0; que.push(s); flow[s] = LLINF;
        while (!que.empty()) {
            int u = que.front(); que.pop();
            for (int& e : adj[u]) {
                int v = E[e].v;
                ll sp = E[e].c - E[e].f;
                ll w = E[e].w;
                if (sp > 0 && dis[v] > dis[u] + w) {
                    back[v] = e;
                    flow[v] = min(flow[u], sp);
                    dis[v] = dis[u] + w;
                    que.push(v);
                }
            }
        }
    }
    pii query(int s, int t) {
        pii ans = { 0,0 };
        this->s = s; this->t = t;
        while (true) {
            spfa();
            if (flow[t] == 0) { return ans; }
            int u = t;
            ll f = flow[t];
            ans.first += f;
            while (u != s) {
                int e = back[u];
                E[e].f += f;
                E[e ^ 1].f -= f;
                ll w = E[e].w;
                ans.second += w * f;
                u = E[e].u;
            }
        }
    }
};

void solve() {

    int n;
    cin >> n;

    vector<ll> A(n), H(n), L(n);
    for (auto& i : A) cin >> i;
    for (auto& i : H) cin >> i;
    for (auto& i : L) cin >> i;

    mcmf g(n*2+2);
    int mx = *max_element(all(A));
    int s = 0, t = n * 2 + 1;

    for (int i = 0; i < n; i++) {
        if (A[i] == mx) {
            g.addEdge(s, i + 1, L[i], H[i]);
        }
        else {
            if (L[i] > 0) g.addEdge(s, i + 1, L[i] - 1, H[i]);
            g.addEdge(i + 1 + n, t, 1, H[i]);
        }
    }
    for (int i = 0; i < n; i++) {
        for (int j = i + 1; j < n; j++) {
            if (A[i] > A[j]) {
                g.addEdge(i + 1, j + 1 + n, 1, -(A[i] ^ A[j]));
            }
            else {
                g.addEdge(j + 1, i + 1 + n, 1, -(A[i] ^ A[j]));
            }
        }
    }

    pii ans = g.query(s, t);
    cout << -ans.second;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    int t = 1;
    // cin >> t;
    while (t--) solve();
}