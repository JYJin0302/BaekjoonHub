#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define mp make_pair
#define all(x) x.begin(), x.end()

const int INF = 1e9 + 9;

struct D {
    int sL, sR, tot, mVal;
    D() : sL(0), sR(0), tot(0), mVal(0) {}
    D(int _sL, int _sR, int _tot, int _mVal) : sL(_sL), sR(_sR), tot(_tot), mVal(_mVal) {}

    const D operator+(const D& o) {
        //cout << *this << " + " << o << " => ";
        int nL = max(sL, tot + o.sL);
        int nR = max(o.sR, sR + o.tot);
        int ntot = tot + o.tot;
        int nmVal = max({ mVal, o.mVal, nL, nR, ntot , sR + o.sL});
        D newV(nL, nR, ntot, nmVal);
        //cout << newV << '\n';
        return D(nL, nR, ntot, nmVal);
    }

    friend ostream& operator<<(ostream& os, D cur) {
        return os << "{" << cur.sL << ' ' << cur.sR << ' ' << cur.tot << ' ' << cur.mVal << "}";
    }
};


vector<int> lazy;
vector<D> seg;
int n, sn;

void goLazy(int l, int r, int n) {
    if (lazy[n] != -INF) {
        int len = r - l + 1;
        int val = lazy[n];
        seg[n] = D(len * val, len * val, len * val, len * val);
        if (l != r) {
            lazy[n * 2] = val;
            lazy[n * 2 + 1] = val;
        }
        lazy[n] = -INF;
    }
}

void update(int l, int r, int n, int ul, int ur, int val) {
    goLazy(l, r, n);
    if (l > ur || r < ul)return;
    if (l >= ul && r <= ur) {
        lazy[n] = val;
        goLazy(l, r, n);
        return;
    }
    int m = (l + r) >> 1;
    update(l, m, n * 2, ul, ur, val);
    update(m + 1, r, n * 2 + 1, ul, ur, val);
    seg[n] = seg[n * 2] + seg[n * 2 + 1];
}

D getVal(int l, int r, int n, int sl, int sr) {
    goLazy(l, r, n);
    if (l > sr || r < sl) return D();
    if (l >= sl && r <= sr) return seg[n];
    int m = (l + r) >> 1;
    return getVal(l, m, n * 2, sl, sr) + getVal(m + 1, r, n * 2 + 1, sl, sr);
}

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
        for (int& v : g[u]) {
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
        pos[u] = cnt; ++cnt; head[u] = h;
        if (heavy[u] != -1) {
            decompose(heavy[u], h);
        }
        for (int& v : g[u]) {
            if (par[u] == v) { continue; }
            if (v == heavy[u]) { continue; }
            decompose(v, v);
        }
    }
    int getAns(int u, int v) {
        D uD, vD;
       // cout << "getans : " << u << ' ' << v << '\n';
        while (head[u] != head[v]) {
            if (h[head[u]] > h[head[v]]) { swap(u, v); swap(uD, vD); }
            // ret = seg.query(pos[head[v]],pos[v]);
            D res = getVal(0, sn - 1, 1, pos[head[v]], pos[v]);
            vD = res + vD;
           // cout << "Upd: " << head[v] << " - " << v << " => " << vD << '\n';
            // define ds + operation
            v = par[head[v]];
        }
        if (h[u] > h[v]) { swap(u, v); swap(uD, vD); }
        // ret = seg.query(pos[u]+1,pos[v]); (edge query)
        // ret = seg.query(pos[u],pos[v])l (vertex query)
        D res = getVal(0, sn - 1, 1, pos[u], pos[v]);
       // cout << "res: " << res << '\n';
       // cout << "vD " << vD << " | uD " << uD << '\n';
        res = res + vD;
        swap(uD.sL, uD.sR);
        res = uD + res;
        // Above line depends on type of query (edge ? vertex)
        return max(0, res.mVal);
    }

    void upd(int u, int v, int val) {
        while (head[u] != head[v]) {
            if (h[head[u]] > h[head[v]]) { swap(u, v); }
            // ret = seg.query(pos[head[v]],pos[v]);
            update(0, sn - 1, 1, pos[head[v]], pos[v], val);
            // define ds + operation
            v = par[head[v]];
        }
        if (h[u] > h[v]) { swap(u, v); }
        // ret = seg.query(pos[u]+1,pos[v]); (edge query)
        // ret = seg.query(pos[u],pos[v])l (vertex query)
        update(0, sn - 1, 1, pos[u], pos[v], val);
        // Above line depends on type of query (edge ? vertex)
    }
};

void solve() {

    cin >> n;

    HLD hld(n + 1);
    vector<int> val(n + 1);
    for (int i = 1; i <= n; i++) {
        cin >> val[i];
    }

    for (int i = 0; i < n - 1; i++) {
        int a, b;
        cin >> a >> b;
        hld.g[a].push_back(b);
        hld.g[b].push_back(a);
    }

    sn = 1;
    while (sn < n) sn *= 2;
    seg = vector<D>(sn * 2);
    lazy = vector<int>(sn * 2, -INF);

    hld.init(1);
    for (int i = 1; i <= n; i++) {
        //cout << "Upd: " << i << ' ' << hld.pos[i] << '\n';
        hld.upd(i, i, val[i]);
    }

    int q;
    cin >> q;
    while (q--) {
        int t;
        cin >> t;
        if (t == 1) {
            int a, b;
            cin >> a >> b;
            cout << hld.getAns(a, b) << '\n';
        }
        else {
            int a, b, c;
            cin >> a >> b >> c;
            hld.upd(a, b, c);
        }
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    int t = 1;
    // cin >> t;
    while (t--) solve();
}