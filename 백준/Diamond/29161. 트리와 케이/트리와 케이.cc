#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define mp make_pair
#define all(x) x.begin(), x.end()
#define x first
#define y second

vector<pair<ll, ll>> adj[202020];
int dep[202020];
int spt[20][202020];
int sz[202020];
int par[202020];
bool vis[202020];
ll dist[202020];

int count(int v, int pv = -1) {
    sz[v] = 1;
    for (auto &[a, b] : adj[v]) if (a != pv && !vis[a]){
        sz[v] += count(a, v);
    }
    return sz[v];
}

int getCent(int v, int pv, int tot) {
    for (auto& [a, b] : adj[v]) if (a != pv && !vis[a]) {
        if (2 * sz[a] > tot) return getCent(a, v, tot);
    }
    return v;
}

int r = -1;
void init(int v, int pv = -1) {
    int tot = count(v);
    int cen = getCent(v, pv, tot);
    vis[cen] = 1;
    par[cen] = pv;
    if (pv == -1) r = cen;
    for (auto& [a, b] : adj[cen]) {
        if (!vis[a]) {
            init(a, cen);
        }
    }
}

int getLca(int u, int v) {
    if (dep[u] < dep[v]) swap(u, v);
    int dif = dep[u] - dep[v];
    for (int i = 0; i < 20; i++) {
        if (dif & (1 << i)) {
            u = spt[i][u];
        }
    }
    for (int i = 19; i >= 0; i--) {
        if (spt[i][u] != spt[i][v]) {
            u = spt[i][u], v = spt[i][v];
        }
    }
    if (u != v) u = spt[0][u];
    return u;
}

ll getDist(int u, int v) {
    int p = getLca(u, v);
    return dist[u] + dist[v] - 2 * dist[p];
}

void dfs(int v, int pv = -1) {
    for (auto& [a, b] : adj[v]) {
        if (a != pv) {
            dep[a] = dep[v] + 1;
            spt[0][a] = v;
            dist[a] = dist[v] + b;
            dfs(a, v);
        }
    }
}

vector<pair<pair<ll, ll>, int>> tmp[202020];
bool cmp(const pair<pair<ll, ll>, int>& v1, const pair<pair<ll, ll>, int>& v2) {
    if (v1.x != v2.x) return v1.x < v2.x;
    return v1.y < v2.y;
}
vector<int> dp[202020];
void solve() {
    
    int n, m;
    cin >> n >> m;

    for (int i = 0; i < n - 1; i++) {
        ll a, b, c;
        cin >> a >> b >> c;
        adj[a].push_back(mp(b, c));
        adj[b].push_back(mp(a, c));
    }

    init(1);
    dfs(r);

    for (int i = 1; i < 20; i++) {
        for (int j = 1; j <= n; j++) {
            spt[i][j] = spt[i - 1][spt[i - 1][j]];
        }
    }

    for (int i = 1; i <= n; i++) {
        int ti = i;
        int pv = -1;
        while (ti != -1) {
            tmp[ti].push_back(mp(mp(getDist(ti, i), pv), i));
            pv = ti;
            ti = par[ti];
        }
    }

    for (int i = 1; i <= n; i++) {
        sort(all(tmp[i]), cmp);
        int sz = tmp[i].size();


        vector<int> t1(sz);
        t1[0] = tmp[i][0].y;
        for (int j = 1; j < sz; j++) {
            t1[j] = t1[j - 1] ^ tmp[i][j].y;
        }
        dp[i] = t1;
    }

    while (m--) {

        ll x, d;
        cin >> x >> d;

        int ans = 0;
        int cur = x;
        int pv = -1;
        while (cur != -1) {
            ll newD = d - getDist(cur, x);
            if (newD >= 0) {
                int l = lower_bound(all(tmp[cur]), mp(mp(newD, -1), -1), cmp) - tmp[cur].begin();
                int r = lower_bound(all(tmp[cur]), mp(mp(newD + 1, -1), -1), cmp) - tmp[cur].begin() - 1;
                if (l <= r) ans ^= dp[cur][r] ^ (l ? dp[cur][l - 1] : 0);

                if (pv != -1) {
                    int l = lower_bound(all(tmp[cur]), mp(mp(newD, pv), -1), cmp) - tmp[cur].begin();
                    int r = lower_bound(all(tmp[cur]), mp(mp(newD, pv + 1), -1), cmp) - tmp[cur].begin() - 1;
                    if (l <= r) ans ^= dp[cur][r] ^ (l ? dp[cur][l - 1] : 0);
                }
            }

            pv = cur;
            cur = par[cur];
        }

        cout << ans << '\n';
    }

}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    int t = 1;
    // cin >> t;
    while (t--) solve();
}