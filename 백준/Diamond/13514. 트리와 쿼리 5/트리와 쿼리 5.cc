#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define mp make_pair
#define all(x) x.begin(), x.end()
#define x first
#define y second

int n;
vector<int> adj[101010], adjCent[101010];
bool vis[101010];
int sz[101010];
int p[101010];
int getCent(int v, int pv = -1, int tot = 0) {
    for (auto& a : adj[v]) if (a != pv && !vis[a]) {
        if (sz[a] > tot / 2) {
            return getCent(a, v, tot);
        }
    }
    return v;
}

void count(int v, int pv = -1) {
    sz[v] = 1;
    for (auto a : adj[v]) if (a != pv && !vis[a]) {
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
    for (auto& a : adj[cen]) {
        if (!vis[a]) {
            init(a, cen);
        }
    }
}

int col[101010];
int dist[101010];
int spt[18][101010];
void dfs(int v, int pv = -1) {
    for (auto f : adj[v]) if (f != pv) {
        dist[f] = dist[v] + 1;
        spt[0][f] = v;
        dfs(f, v);
    }
}
int getDist(int u, int v) {
    if (dist[u] < dist[v]) swap(u, v);
    int dif = dist[u] - dist[v];
    int ret = 0;
    for (int i = 0; i < 18; i++) {
        if (dif & (1 << i)) {
            ret += 1 << i;
            u = spt[i][u];
        }
    }
    for (int i = 17; i >= 0; i--) {
        if (spt[i][u] != spt[i][v]) {
            u = spt[i][u];
            v = spt[i][v];
            ret += 2 << i;
        }
    }

    if (u != v) ret += 2;
    return ret;
}

set<pair<int, int>> dp[101010];
void update(int v, int t) {
    while (1) {
        int dst = getDist(v, t);
        dp[v].insert(mp(dst, t));
        if (v == r) break;
        v = p[v];
    }
}

int getAns(int v) {
    int res = n + 10;
    int tv = v;
    while (1) {
        while (!dp[v].empty()) {
            auto& [a, b] = *dp[v].begin();
            if (col[b] == 0) {
                dp[v].erase(dp[v].begin());
            }
            else break;
        }

        if (!dp[v].empty()) {
            auto& [a, b] = *dp[v].begin();
            res = min(res, getDist(b, tv));
        }

        if (v == r) break;
        v = p[v];
    }
    if (res == n + 10) res = -1;
    return res;
}

void solve() {

    cin >> n;

    for (int i = 0; i < n - 1; i++) {
        int a, b;
        cin >> a >> b;
        adj[a].push_back(b);
        adj[b].push_back(a);
    }

    init(1);
    dfs(r);
    for (int i = 1; i < 18; i++) {
        for (int j = 1; j <= n; j++) {
            spt[i][j] = spt[i - 1][spt[i - 1][j]];
        }
    }

    int q;
    cin >> q;
    while (q--) {
        int a, b;
        cin >> a >> b;

        if (a == 1) {
            col[b] ^= 1;
            if (col[b]) {
                update(b, b);
            }
        }
        else {
            cout << getAns(b) << '\n';
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