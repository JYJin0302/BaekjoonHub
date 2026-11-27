#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define mp make_pair
#define all(x) x.begin(), x.end()
#define x first
#define y second

struct D {    
    pair<ll, ll> d1[5], d2[5];

    void insert(ll v1, ll v2, ll pos) {
        if (v1) {
            d1[4] = mp(v1, pos);
            sort(d1, d1 + 5, greater<pair<ll, ll>>());
            d1[4] = mp(0, 0);
        }
        if (v2) {
            v2 = max(v2, v1);
            d2[4] = mp(v2, pos);
            sort(d2, d2 + 5, greater<pair<ll, ll>>());
            d2[4] = mp(0, 0);
        }
    }   
};
vector<pair<ll, ll>> adj[101010];
ll dp[2][101010];
ll dpU[2][101010];
// maxLen, maxSub
int spt[20][101010];
int dep[101010];

D sdp[20][101010];

void dfs(int v, int pv = -1) {
    vector<ll> res;
    for (auto [a, b] : adj[v]) if (a != pv) {
        spt[0][a] = v;
        dep[a] = dep[v] + 1;
        dfs(a, v);
        res.push_back(dp[0][a] + b);
        dp[1][v] = max(dp[1][v], dp[1][a]);
    }
    while (res.size() < 2) res.push_back(0);
    sort(res.rbegin(), res.rend());
    dp[0][v] = res[0];
    dp[1][v] = max(res[0] + res[1], dp[1][v]);
    dp[1][v] = max(dp[1][v], dp[0][v]);
}

void dfs2(int v, int pv = 0) {
    vector<pair<ll, ll>> res, res2;
    for (auto [a, b] : adj[v]) if (a != pv) {
        res.push_back(mp(dp[0][a] + b, a));
        res2.push_back(mp(dp[1][a], a));
    }
    res.push_back(mp(dpU[0][v], pv));
    res2.push_back(mp(dpU[1][v], pv));
    while (res.size() < 3) res.push_back(mp(0, 0));
    while (res2.size() < 3) res2.push_back(mp(0, 0));
    sort(res.rbegin(), res.rend());
    sort(res2.rbegin(), res2.rend());

    for (auto [a, b] : adj[v]) if (a != pv) {
        ll v0 = 0, v1 = 0;
        int cnt = 0;
        for (int j = 0; j < 3 && cnt < 2; j++) {
            if (res[j].second != a) {
                cnt++;
                v1 += res[j].first;
                v0 = max(v0, res[j].first);
            }
        }

        cnt = 0;
        for (int j = 0; j < 2 && cnt < 1; j++) {
            if (res2[j].second != a) {
                cnt++;
                v1 = max(v1, res2[j].first);
            }
        }
        v0 += b;
        v1 = max(v1, v0);
        dpU[0][a] = v0;
        dpU[1][a] = v1;
        dfs2(a, v);
    }
}

int getLca(int u, int v) {
    if (dep[u] < dep[v]) swap(u, v);
    int dif = dep[u] - dep[v];
    for (int j = 0; j < 20; j++) {
        if (dif & (1 << j)) u = spt[j][u];
    }

    for (int i = 19; i >= 0; i--) {
        if (spt[i][u] != spt[i][v]) {
            u = spt[i][u];
            v = spt[i][v];
        }
    }
    if (u != v) u = spt[0][u];
    return u;
}
int getPos(int u, int v) {
    if (dep[u] > dep[v]) swap(u, v);
    int dif = dep[v] - dep[u] - 1;
    for (int i = 0; i < 20; i++) {
        if (dif & (1 << i)) {
            v = spt[i][v];
        }
    }

    if (spt[0][v] != u) return 0;
    return v;
}


D merge(D& d1, D& d2, int invalid = -1) {
    /*cout << "Go merge " << invalid << "\n";
    for (auto f : d1.d1) cout << "(" << f.x << ", " << f.y << ") ";
    cout << " + ";
    for (auto f : d1.d2) cout << "(" << f.x << ", " << f.y << ") ";
    cout << '\n';
    for (auto f : d2.d1) cout << "(" << f.x << ", " << f.y << ") ";
    cout << " + ";
    for (auto f : d2.d2) cout << "(" << f.x << ", " << f.y << ") ";
    cout << '\n';*/
    D res = d1;
    for (int i = 0; i < 5; i++) {
        if (res.d1[i].y == invalid) {
            res.d1[i] = mp(0, 0);
            sort(res.d1, res.d1 + 5, greater<pair<ll, ll>>());
        }
        if (res.d2[i].y == invalid) {
            res.d2[i] = mp(0, 0);
            sort(res.d2, res.d2 + 5, greater<pair<ll, ll>>());
        }
    }

    for (int i = 0; i < 5; i++) {
        res.insert(d2.d1[i].x, 0, d2.d1[i].y);
        res.insert(0, d2.d2[i].x, d2.d2[i].y);
    }
    /*cout << "Result: \n";
    for (auto f : res.d1) cout << "(" << f.x << ", " << f.y << ") ";
    cout << " + ";
    for (auto f : res.d2) cout << "(" << f.x << ", " << f.y << ") ";
    cout << '\n';*/
    return res;
}
void solve() {

    int n, q;
    cin >> n;

    for (int i = 0; i < n - 1; i++) {
        ll a, b, c;
        cin >> a >> b >> c;
        adj[a].push_back(mp(b, c));
        adj[b].push_back(mp(a, c));
    }

    int r = n;
    dfs(r);
    dfs2(r);

    /*for (int i = 1; i <= n; i++) {
        cout << i << " | " << dp[0][i] << ' ' << dp[1][i] << " + " << dpU[0][i] << ' ' << dpU[1][i] << '\n';
    }*/

    for (int i = 1; i < 20; i++) {
        for (int j = 1; j <= n; j++) {
            spt[i][j] = spt[i - 1][spt[i - 1][j]];
        }
    }

    for (int i = 1; i <= n; i++) {
        for (auto [u, v] : adj[i]) if (spt[0][i] != u) {
            sdp[0][i].insert(dp[0][u] + v, dp[1][u], u);
        }
    }

    for (int j = 1; j < 20; j++) {
        for (int i = 1; i <= n; i++) {
            if (spt[j-1][i] == 0) continue;
            int v = spt[j-1][i];
            int tv = getPos(v, i);
           // cout << "Go: " << v << ' ' << i << '\n';
            sdp[j][i] = merge(sdp[j - 1][v], sdp[j - 1][i], tv);
        }
    }

    cin >> q;
    while (q--) {
        //cout << "Query: ";
        int u, v;
        cin >> u >> v;

        int tu = u, tv = v;
        int l = getLca(u, v);
        D res;
        int dif = dep[u] - dep[l];
        for (int i = 0; i < 20; i++) {
            if (dif & (1 << i)) {
                res = merge(sdp[i][tu], res, getPos(tu, u));
                tu = spt[i][tu];
            }
        }

        dif = dep[v] - dep[l];
        for (int i = 0; i < 20; i++) {
            if (dif & (1 << i)) {
                res = merge(sdp[i][tv], res, getPos(tv, v));
                tv = spt[i][tv];
            }
        }

        res.insert(dpU[0][l], dpU[1][l], l);
        int inv1 = getPos(l, u);
        int inv2 = getPos(l, v);
        for (int i = 0; i < 5; i++) {
            if (sdp[0][l].d1[i].y == inv1 || sdp[0][l].d1[i].y == inv2) {}
            else {
                res.insert(sdp[0][l].d1[i].x, 0, sdp[0][l].d1[i].y);
            }
            if (sdp[0][l].d2[i].y == inv1 || sdp[0][l].d2[i].y == inv2) {}
            else {
                res.insert(0, sdp[0][l].d2[i].x, sdp[0][l].d2[i].y);
            }
        }

        ll v1 = 0, v2 = 0;
        for (int i = 0; i < 2; i++) {
            v1 += res.d1[i].x;
            v2 = max(v2, res.d2[i].x);
        }
        cout << max(v1, v2) << '\n';
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    int t = 1;
    // cin >> t;
    while (t--) solve();
}