#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using ld = long double;
#define mp make_pair
#define all(x) x.begin(), x.end()

int dx[] = { -1, 0, 1, 0 };
int dy[] = { 0, 1, 0, -1 };

const int INF = 1e8;

int n, m, sn;
vector<int> seg;
vector<int> lazy;

void goLazy(int l, int r, int n) {
    if (lazy[n] != INF) {
        seg[n] = min(seg[n], lazy[n]);
        if (l != r) {
            lazy[n * 2] = min(lazy[n * 2], lazy[n]);
            lazy[n * 2 + 1] = min(lazy[n * 2 + 1], lazy[n]);
        }
        lazy[n] = INF;
    }
}

void update(int l, int r, int n, int ul, int ur, int val) {
    goLazy(l, r, n);
    if (l > ur || r < ul) return;
    if (l >= ul && r <= ur) {
        lazy[n] = min(lazy[n], val);
        goLazy(l, r, n);
        return;
    }
    int m = (l + r) >> 1;
    update(l, m, n * 2, ul, ur, val);
    update(m + 1, r, n * 2 + 1, ul, ur, val);
    seg[n] = min(seg[n * 2], seg[n * 2 + 1]);
}

int getMin(int l, int r, int n, int sl, int sr) {
    goLazy(l, r, n);
    if (l > sr || r < sl) return INF;
    if (l >= sl && r <= sr) return seg[n];
    int m = (l + r) >> 1;
    return min(getMin(l, m, n * 2, sl, sr), getMin(m + 1, r, n * 2 + 1, sl, sr));
}

struct Edg {
    int u, v, w;
    int idx;

    bool operator<(Edg& e) {
        return w < e.w;
    }
};

struct HLD {
    int N, cnt;
    vector<int> h, par, pos, head, heavy;
    vector<vector<int>> g;
    HLD(int n) {
        N = n; cnt = 0;
        h.resize(n, -1);
        par.resize(n, -1);
        pos.resize(n, -1);
        head.resize(n, -1);
        heavy.resize(n, -1);
        g.resize(n);
    }
    void init(int r) {
        h[r] = 0;
        dfs(r);
        decompose(r, r);
    }
    int dfs(int u) {
        int ret = 1;
        int m, c; m = c = -1;
        for (auto& v : g[u]) {
            if (par[u] == v) { continue; }
            h[v] = h[u] + 1;
            par[v] = u;
            int sub = dfs(v);
            ret += sub;
            if (sub > m) {
                m = sub; heavy[u] = v;
            }
        }
        return ret;
    }
    void decompose(int u, int h) {
        pos[u] = cnt;
        ++cnt; head[u] = h;
        if (heavy[u] != -1) {
            decompose(heavy[u], h);
        }
        for (auto& v : g[u]) {
            if (par[u] == v) { continue; }
            if (v == heavy[u]) { continue; }
            decompose(v, v);
        }
    }
    void query(int u, int v, int val) {
        while (head[u] != head[v]) {
            if (h[head[u]] > h[head[v]]) { swap(u, v); }
            update(0, sn - 1, 1, pos[head[v]], pos[v], val);
            // ret = seg.query(pos[head[v]],pos[v]);
            // define ds + operation
            v = par[head[v]];
        }
        if (h[u] > h[v]) { swap(u, v); }
        update(0, sn - 1, 1, pos[u] + 1, pos[v], val);
        // ret = seg.query(pos[u]+1,pos[v]); (edge query)
        // ret = seg.query(pos[u],pos[v]); (vertex query)
        // Above line depends on type of query (edge ? vertex)
    }

};

int root[101010];
int find(int n) {
    if (root[n] == n) return n;
    return root[n] = find(root[n]);
}

void solve() {

    cin >> n >> m;
    sn = 1;
    while (sn < n) sn *= 2;

    seg = vector<int>(sn * 2, INF);
    lazy = vector<int>(sn * 2, INF);
    HLD hld(n + 1);
    for (int i = 1; i <= n; i++) root[i] = i;

    vector<Edg> edg;
    for (int i = 0; i < m; i++) {
        int a, b, c;
        cin >> a >> b >> c;
        edg.push_back({ a, b, c, i });
    }
    sort(all(edg));

    vector<bool> used(m + 1);
    ll tot = 0;
    vector<Edg> needUpd;
    for (auto& f : edg) {
        int u = find(f.u);
        int v = find(f.v);
        if (u == v) {
            needUpd.push_back(f);
        }
        else {
            used[f.idx] = 1;
            root[u] = v;
            tot += f.w;
            hld.g[f.u].push_back(f.v);
            hld.g[f.v].push_back(f.u);
        }
    }
    hld.init(1);
    if (hld.cnt != n) {
        for (int i = 0; i < m; i++) cout << -1 << '\n';
        return;
    }

    for (auto& f : needUpd) {
        hld.query(f.u, f.v, f.w);
    }
    
    vector<ll> ans(m);
    for (int i = 0; i < m; i++) {
        if (!used[edg[i].idx]) {
            ans[edg[i].idx] = tot;
        }
        else {
            int u = edg[i].u, v = edg[i].v;
            if (hld.h[u] < hld.h[v]) swap(u, v);
            ll val = getMin(0, sn - 1, 1, hld.pos[u], hld.pos[u]);
            if (val == INF) ans[edg[i].idx] = -1;
            else ans[edg[i].idx] = tot - edg[i].w + val;
        }
    }

    for (auto f : ans) cout << f << '\n';

}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    int t = 1;
    //cin >> t;
    while (t--) solve();
}