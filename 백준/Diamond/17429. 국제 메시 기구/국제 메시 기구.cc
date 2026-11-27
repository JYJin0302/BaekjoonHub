#include <bits/stdc++.h>
using namespace std;
using ll = unsigned long long;
#define mp make_pair
#define all(x) x.begin(), x.end()

const ll mod = 1ll << 32;

vector<pair<ll, ll>> lazy;
vector<ll> seg;
int n, sn, q;

void goLazy(int l, int r, int n) {
    if (lazy[n] != mp((ll)1, (ll)0)) {
        ll len = r - l + 1;
        ll mul = lazy[n].first;
        ll ad = lazy[n].second;
        seg[n] = seg[n] * mul % mod + len * ad % mod; seg[n] %= mod;        
        if (l != r) {
            lazy[n * 2] = mp(lazy[n * 2].first * mul % mod, (lazy[n * 2].second * mul % mod + ad) % mod);
            lazy[n * 2 + 1] = mp(lazy[n * 2 + 1].first * mul % mod, (lazy[n * 2 + 1].second * mul % mod + ad) % mod);
        }
        lazy[n] = mp(1, 0);
    }
}

void update(int l, int r, int n, int ul, int ur, ll mul, ll ad) {
    goLazy(l, r, n);
    if (l > ur || r < ul) return;
    if (l >= ul && r <= ur) {
        lazy[n] = mp(lazy[n].first * mul % mod, (lazy[n].second * mul % mod + ad) % mod);
        goLazy(l, r, n);
        return;
    }
    int m = (l + r) >> 1;
    update(l, m, n * 2, ul, ur, mul, ad);
    update(m + 1, r, n * 2 + 1, ul, ur, mul, ad);
    seg[n] = (seg[n * 2] + seg[n * 2 + 1]) % mod;
}

ll getVal(int l, int r, int n, int sl, int sr) {
    goLazy(l, r, n);
    if (l > sr || r < sl) return 0;
    if (l >= sl && r <= sr) return seg[n];
    int m = (l + r) >> 1;
    return (getVal(l, m, n * 2, sl, sr) + getVal(m + 1, r, n * 2 + 1, sl, sr)) % mod;
}

struct HLD {
    int N, cnt;
    vector<int> h, par, pos, head, heavy, tail;
    vector<vector<int>> g;
    HLD(int n) {
        N = n; cnt = 0;
        h.resize(n, -1);
        par.resize(n, -1);
        pos.resize(n, -1);
        head.resize(n, -1);
        tail.resize(n, -1);
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
        tail[u] = cnt - 1;
    }
    void upd(int u, int v, ll mul, ll ad) {
        // cout << "getans : " << u << ' ' << v << '\n';
        while (head[u] != head[v]) {
            if (h[head[u]] > h[head[v]]) { swap(u, v); }
            // ret = seg.query(pos[head[v]],pos[v]);
            update(0, sn - 1, 1, pos[head[v]], pos[v], mul, ad);
            // cout << "Upd: " << head[v] << " - " << v << " => " << vD << '\n';
             // define ds + operation
            v = par[head[v]];
        }
        if (h[u] > h[v]) { swap(u, v); }
        // ret = seg.query(pos[u]+1,pos[v]); (edge query)
        // ret = seg.query(pos[u],pos[v]); (vertex query)
        update(0, sn - 1, 1, pos[u], pos[v], mul, ad);
    }

    ll getAns(int u, int v) {
        ll ret = 0;
        while (head[u] != head[v]) {
            if (h[head[u]] > h[head[v]]) { swap(u, v); }
            // ret = seg.query(pos[head[v]],pos[v]);
            ret += getVal(0, sn - 1, 1, pos[head[v]], pos[v]);
            ret %= mod;
             // define ds + operation
            v = par[head[v]];
        }
        if (h[u] > h[v]) { swap(u, v); }
        // ret = seg.query(pos[u]+1,pos[v]); (edge query)
        // ret = seg.query(pos[u],pos[v]); (vertex query)
        ret += getVal(0, sn - 1, 1, pos[u], pos[v]);
        ret %= mod;
        return ret;
    }

};

void solve() {

    cin >> n >> q;

    HLD hld(n + 1);

    for (int i = 0; i < n - 1; i++) {
        int a, b;
        cin >> a >> b;
        hld.g[a].push_back(b);
        hld.g[b].push_back(a);
    }

    sn = 1;
    while (sn < n) sn *= 2;
    seg = vector<ll>(sn * 2);
    lazy = vector<pair<ll, ll>>(sn * 2, mp(1, 0));
    hld.init(1);

    while (q--) {
        int t;
        cin >> t;

        int x, y;
        ll v, ans;

        if (t == 1) {
            cin >> x >> v;
            update(0, sn - 1, 1, hld.pos[x], hld.tail[x], 1, v);
        }
        else if (t == 2) {
            cin >> x >> y >> v;
            hld.upd(x, y, 1, v);
        }
        else if (t == 3) {
            cin >> x >> v;
            update(0, sn - 1, 1, hld.pos[x], hld.tail[x], v, 0);
        }
        else if (t == 4) {
            cin >> x >> y >> v;
            hld.upd(x, y, v, 0);
        }
        else if (t == 5) {
            cin >> x;
            ans = getVal(0, sn - 1, 1, hld.pos[x], hld.tail[x]);
            cout << ans << '\n';
        }
        else {
            cin >> x >> y;
            ans = hld.getAns(x, y);
            cout << ans << '\n';
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