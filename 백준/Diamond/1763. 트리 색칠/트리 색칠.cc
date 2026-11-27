#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define mp make_pair

vector<int> adj[1010], ord[1010];
ll cost[1010], sz[1010];


ll dp[1010][1010];

void dfs(int v) {
    sz[v] = 0;
  //  ord[v].push_back(cost[v]);

    for (auto f : adj[v]) {

        dfs(f);
        
        int a = sz[v];
        int b = sz[f];

        for (int i = 0; i <= a; i++) {
            for (int j = 0; j <= b; j++) dp[i][j] = 0;
        }

        vector<ll> sfA(a), sfB(b);
        for (int i = a - 1; i >= 0; i--) {
            sfA[i] = ord[v][i];
            if (i + 1 < a) sfA[i] += sfA[i + 1];
        }
        for (int i = b - 1; i >= 0; i--) {
            sfB[i] = ord[f][i];
            if (i + 1 < b) sfB[i] += sfB[i + 1];
        }

        for (int i = a - 1; i >= 0; i--) {
            dp[i][b] = sfA[i];
            if (i + 1 < a) dp[i][b] += dp[i + 1][b];
        }
        for (int i = b - 1; i >= 0; i--) {
            dp[a][i] = sfB[i];
            if (i + 1 < b) dp[a][i] += dp[a][i + 1];
        }

        for (int i = a-1; i >= 0; i--) {
            for (int j = b-1; j >= 0; j--) {
                ll mx = min(dp[i][j + 1], dp[i + 1][j]);
                dp[i][j] = mx + sfA[i] + sfB[j];
            }
        }

        vector<int> newOrd;
        int ta = 0, tb = 0;
        while (ta < a && tb < b) {
            if (dp[ta + 1][tb] > dp[ta][tb + 1]) newOrd.push_back(ord[f][tb++]);
            else newOrd.push_back(ord[v][ta++]);
        }
        while (ta < a) {
            newOrd.push_back(ord[v][ta++]);
        }
        while (tb < b) {
            newOrd.push_back(ord[f][tb++]);
        }

        ord[v] = newOrd;

        sz[v] += sz[f];
    }
    sz[v]++;
    reverse(ord[v].begin(), ord[v].end());
    ord[v].push_back(cost[v]);
    reverse(ord[v].begin(), ord[v].end());

    //cout << "Curr: " << v << " : ";
    //for (auto f : ord[v]) cout << f << ' ';
    //cout << '\n';
}

void solve() {

    int n, r;
    cin >> n >> r;

    for (int i = 1; i <= n; i++) cin >> cost[i];
    for (int i = 0; i < n - 1; i++) {
        int a, b; cin >> a >> b;
        adj[a].push_back(b);
    }

    dfs(r);

    ll ans = 0, cur = 0;
    for (int i = sz[r] - 1; i >= 0; i--) {
        cur += ord[r][i];
        ans += cur;
    }
    cout << ans << '\n';

}


int main() {

    ios::sync_with_stdio(false);
    cin.tie(0);


    int t = 1;
    //cin >> t;
    while (t--) {
        solve();
    }
}