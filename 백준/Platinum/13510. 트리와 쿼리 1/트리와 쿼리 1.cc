#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using ld = long double;
#define mp make_pair
#define all(x) x.begin(), x.end()

int dx[] = { -1, 0, 1, 0 };
int dy[] = { 0, 1, 0, -1 };

int n;
vector<int> seg;
void update(int ix, int val) {
    //cout << "upd : " << ix << ' ' << val << '\n';
    for (seg[ix += n] = val; ix; ix >>= 1) {
        seg[ix >> 1] = max(seg[ix], seg[ix ^ 1]);
    }
}

int getMax(int l, int r) {
    r++;
    int res = 0;
    for (l += n, r += n; l < r; l >>= 1, r >>= 1) {
        if (l & 1) res = max(res, seg[l++]);
        if (r & 1) res = max(res, seg[--r]);
    }
    return res;
}

struct HLD {
    int N, cnt;
    vector<int> h, par, pos, head, heavy, parVal;
    vector<vector<pair<int, int>>> g;
    HLD(int n) {
        N = n; cnt = 0;
        h.resize(n, -1);
        par.resize(n, -1);
        pos.resize(n, -1);
        head.resize(n, -1);
        heavy.resize(n, -1);
        g.resize(n);
        parVal.resize(n);
    }
    void init(int r) {
        h[r] = 0;
        dfs(r);
        decompose(r, r);
    }
    int dfs(int u) {
        int ret = 1;
        int m, c; m = c = -1;
        for (auto& [v, c] : g[u]) {
            if (par[u] == v) { continue; }
            h[v] = h[u] + 1;
            par[v] = u;
            parVal[v] = c;
            int sub = dfs(v);
            ret += sub;
            if (sub > m) {
                m = sub; heavy[u] = v;
            }
        }
        return ret;
    }
    void decompose(int u, int h) {
        pos[u] = cnt; update(cnt, parVal[u]);
        ++cnt; head[u] = h;
        if (heavy[u] != -1) {
            decompose(heavy[u], h);
        }
        for (auto& [v, c] : g[u]) {
            if (par[u] == v) { continue; }
            if (v == heavy[u]) { continue; }
            decompose(v, v);
        }
    }
    int query(int u, int v) {
        int ret = 0;
        while (head[u] != head[v]) {
            if (h[head[u]] > h[head[v]]) { swap(u, v); }
            ret = max(ret, getMax(pos[head[v]], pos[v]));
            // ret = seg.query(pos[head[v]],pos[v]);
            // define ds + operation
            v = par[head[v]];
        }
        if (h[u] > h[v]) { swap(u, v); }
        ret = max(ret, getMax(pos[u] + 1, pos[v]));
        // ret = seg.query(pos[u]+1,pos[v]); (edge query)
        // ret = seg.query(pos[u],pos[v]); (vertex query)
        // Above line depends on type of query (edge ? vertex)
        return ret;
    }

};

void solve() {

    cin >> n;
    seg = vector<int>(n * 2 + 10);
    HLD hld(n + 1);

    vector<pair<int, int>> edg;
    for (int i = 0; i < n - 1; i++) {
        int a, b, c;
        cin >> a >> b >> c;
        edg.push_back(mp(a, b));
        hld.g[a].push_back(mp(b, c));
        hld.g[b].push_back(mp(a, c));
    }

    hld.init(1);

    int q;
    cin >> q;
    while (q--) {

        int t, a, b;
        cin >> t >> a >> b;
        
        if (t == 1) {
            auto& [u, v] = edg[a - 1];
            if (hld.h[u] < hld.h[v]) swap(u, v);
            int pos = hld.pos[u];
            update(pos, b);
        }
        else {
            cout << hld.query(a, b) << '\n';
        }

    }

}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    int t = 1;
    //cin >> t;
    while (t--) solve();
}