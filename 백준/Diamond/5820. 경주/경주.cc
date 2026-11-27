#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define mp make_pair
#define all(x) x.begin(), x.end()
#define x first
#define y second

ll n, k;
vector<pair<ll, ll>> adj[202020];
bool vis[202020];
int sz[202020];
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

int dist[1001010];
ll ans;
vector<pair<ll, ll>> ret;

void getDist(int v, int pv, ll d = 0, int cnt = 0) {
    if (d > k) return;
    ret.push_back(mp(d, cnt));
    for (auto& [a, b] : adj[v]) if (a != pv && !vis[a]) {
        getDist(a, v, d + b, cnt + 1);
    }
}

void dfs(int v, int pv = -1) {
    count(v, pv);
    int cen = getCent(v, pv, sz[v]);
    // process

    vector<int> track;    
    for (auto& [a, b] : adj[cen]) {
        if (!vis[a]) {
            ret.clear();
            getDist(a, cen, b, 1);

            for (auto& [x, y] : ret){
                track.push_back(x);
                ans = min(ans, dist[k - x] + y);
            }

            for (auto& [x, y] : ret) {
                dist[x] = min(dist[x], (int)y);
            }
        }
    }

    for (auto f : track) dist[f] = n + 10;

    vis[cen] = 1;
    for (auto& [a, b] : adj[cen]) {
        if (!vis[a]) {
            dfs(a, v);
        }
    }
}


void solve() {

    cin >> n >> k;

    for (int i = 0; i < n - 1; i++) {
        ll a, b, c;
        cin >> a >> b >> c;
        adj[a].push_back(mp(b, c));
        adj[b].push_back(mp(a, c));
    }

    ans = n + 1;
    for (int i = 0; i <= k; i++) dist[i] = n + 10;
    dist[0] = 0;
    dfs(0);
    
    if (ans == n + 1) ans = -1;
    cout << ans;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    int t = 1;
    // cin >> t;
    while (t--) solve();
}