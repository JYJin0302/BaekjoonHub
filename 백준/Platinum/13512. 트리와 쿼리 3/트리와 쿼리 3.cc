#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using ld = long double;
#define mp make_pair
#define all(x) x.begin(), x.end()

int dx[] = { -1, 0, 1, 0 };
int dy[] = { 0, 1, 0, -1 };

const int INF = 1e8;

int n;
vector<int> seg;
void update(int ix) {
    //cout << "upd : " << ix << ' ' << val << '\n';
    int val = ix;
    if (seg[ix + n] == ix) val = INF;
    for (seg[ix += n] = val; ix; ix >>= 1) {
        seg[ix >> 1] = min(seg[ix], seg[ix ^ 1]);
    }
}

int getMax(int l, int r) {
    r++;
    int res = INF;
    for (l += n, r += n; l < r; l >>= 1, r >>= 1) {
        if (l & 1) res = min(res, seg[l++]);
        if (r & 1) res = min(res, seg[--r]);
    }
    return res;
}

struct HLD {
    int N, cnt;
    vector<int> h, par, pos, head, heavy, posVal;
    vector<vector<int>> g;
    HLD(int n) {
        N = n; cnt = 0;
        h.resize(n, -1);
        par.resize(n, -1);
        pos.resize(n, -1);
        head.resize(n, -1);
        heavy.resize(n, -1);
        g.resize(n);
        posVal.resize(n);
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
        posVal[cnt] = u;
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
    int query(int u, int v) {
        int ret = INF;
        while (head[u] != head[v]) {
            if (h[head[u]] > h[head[v]]) { swap(u, v); }
            ret = min(ret, getMax(pos[head[v]], pos[v]));
            // ret = seg.query(pos[head[v]],pos[v]);
            // define ds + operation
            v = par[head[v]];
        }
        if (h[u] > h[v]) { swap(u, v); }
        ret = min(ret, getMax(pos[u], pos[v]));
        // ret = seg.query(pos[u]+1,pos[v]); (edge query)
        // ret = seg.query(pos[u],pos[v]); (vertex query)
        // Above line depends on type of query (edge ? vertex)

        if (ret == INF) ret = -1;
        else ret = posVal[ret];
        return ret;
    }

};

void solve() {

    cin >> n;
    seg = vector<int>(n * 2 + 10, INF);
    HLD hld(n + 1);

    for (int i = 0; i < n - 1; i++) {
        int a, b;
        cin >> a >> b;
        hld.g[a].push_back(b);
        hld.g[b].push_back(a);
    }

    hld.init(1);

    int q;
    cin >> q;
    while (q--) {

        int t, a;
        cin >> t >> a;
        
        if (t == 1) {
            int pos = hld.pos[a];
            update(pos);
        }
        else {
            cout << hld.query(1, a) << '\n';
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