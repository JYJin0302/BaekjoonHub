#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define mp make_pair
#define all(x) x.begin(), x.end()
#define x first
#define y second

int n;
vector<pair<ll, ll>> adj[505050];
vector<int> adjCent[505050];
bool vis[505050];
int sz[505050];
int p[505050];
int getCent(int v, int pv = -1, int tot = 0) {
    for (auto& [a, b] : adj[v]) if (a != pv && !vis[a]) {
        if (sz[a] > tot / 2) {
            return getCent(a, v, tot);
        }
    }
    return v;
}

void count(int v, int pv = -1) {
    sz[v] = 1;
    for (auto& [a, b] : adj[v]) if (a != pv && !vis[a]) {
        count(a, v);
        sz[v] += sz[a];
    }
}

int r = 0;
void init(int v, int pv = -1) {
    count(v, pv);
    int cen = getCent(v, pv, sz[v]);
    if (pv == -1) r = cen;
    p[cen] = pv;
    if (pv != -1) adjCent[pv].push_back(cen);
    vis[cen] = 1;
    for (auto& [a, b] : adj[cen]) {
        if (!vis[a]) {
            init(a, cen);
        }
    }
}

int col[505050];
ll dist[505050];
int dep[505050];
int spt[20][505050];
void dfs(int v, int pv = -1) {
    for (auto& [f, a] : adj[v]) if (f != pv) {
        dist[f] = dist[v] + a;
        dep[f] = dep[v] + 1;
        spt[0][f] = v;
        dfs(f, v);
    }
}
ll getDist(int u, int v) {
    if (dep[u] < dep[v]) swap(u, v);
    int dif = dep[u] - dep[v];
    ll ret = dist[u] + dist[v];
    for (int i = 0; i < 20; i++) {
        if (dif & (1 << i)) {
            u = spt[i][u];
        }
    }
    for (int i = 19; i >= 0; i--) {
        if (spt[i][u] != spt[i][v]) {
            u = spt[i][u];
            v = spt[i][v];
        }
    }

    if (u != v) u = spt[0][u];
    return ret - 2 * dist[u];
}

pair<ll, int> dp[505050];
void update(int v, int t) {
    while (1) {
        ll dst = getDist(v, t);
        dp[v] = min(dp[v], mp(dst, t));
        if (v == r) break;
        v = p[v];
    }
}

void rmv(int v, int t) {
    while (1) {
        if (dp[v].second == -1) return;
        dp[v] = mp(5e18, -1);
        if (v == r) break;
        v = p[v];
    }
}

ll getAns(int v) {
    ll res = 5e18;
    int tv = v;
    while (1) {

        auto& [a, b] = dp[v];
        if (b != -1) res = min(res, getDist(b, tv));

        if (v == r) break;
        v = p[v];
    }
    if (res == 5e18) res = -1;
    return res;
}

void solve() {

    int q;
    cin >> n >> q;

    for (int i = 0; i < n - 1; i++) {
        ll a, b, c;
        cin >> a >> b >> c;
        adj[a].push_back(mp(b, c));
        adj[b].push_back(mp(a, c));
    }

    init(0);
    dfs(r);
    for (int i = 1; i < 20; i++) {
        for (int j = 0; j < n; j++) {
            spt[i][j] = spt[i - 1][spt[i - 1][j]];
        }
    }

    for (int i = 0; i < n; i++) dp[i] = mp(5e18, -1);

    while (q--) {
        int w, z;
        cin >> w >> z;
        vector<int> A(w), B(z);
        for (auto& i : A) cin >> i;
        for (auto& i : B) cin >> i;

        if (A.size() > B.size()) swap(A, B);

        for (auto f : A) {
            update(f, f);
        }

        ll ans = 5e18;
        for (auto f : B) {
            ans = min(ans, getAns(f));
        }
        cout << ans << '\n';

        for (auto f : A) {
            rmv(f, f);
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