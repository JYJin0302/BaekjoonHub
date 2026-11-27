#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define mp make_pair
#define all(x) x.begin(), x.end()
#define x first
#define y second

vector<int> adj[202020];
ll W[202020];
ll tot[202020];
ll dp[202020];

ll ans;

void dfs(int v, int pv = -1) {

    for (auto f : adj[v]) if (f != pv) {

        dfs(f, v);
        dp[v] += tot[f] + dp[f];
        tot[v] += tot[f];
    }
    tot[v] += W[v];
}

void dfs2(int v, int pv = -1, ll preDp = 0, ll preTot = 0) {

    preDp += preTot;
    ans = max(ans, dp[v] + preDp);
    //cout << "Cur: " << v << " | " << preDp << ' ' << preTot << '\n';
    ll tot1 = 0, dp1 = 0;
    for (auto f : adj[v]) if (f != pv) {
        tot1 += tot[f];
        dp1 += dp[f]+ tot[f];
    }
    for (auto f : adj[v]) if (f != pv) {
        tot1 -= tot[f];
        dp1 -= dp[f] + tot[f];

        dfs2(f, v, preDp + dp1, preTot + tot1 + W[v]);
        tot1 += tot[f];
        dp1 += dp[f] + tot[f];
    }
}
void solve() {

    int n;
    cin >> n;

    for (int i = 0; i < n - 1; i++) {
        int a, b;
        cin >> a >> b;
        adj[a].push_back(b);
        adj[b].push_back(a);
    }
    for (int i = 1; i <= n; i++) cin >> W[i];

    dfs(1);
    ans = dp[1];

    dfs2(1);
    cout << ans << '\n';
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    int t = 1;
    //cin >> t;
    while (t--) solve();
}