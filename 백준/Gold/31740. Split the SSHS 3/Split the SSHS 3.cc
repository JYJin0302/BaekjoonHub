#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define mp make_pair
#define all(x) x.begin(), x.end()
#define x first
#define y second

vector<int> adj[101010];
ll W[101010];
ll dp[101010];
ll tot = 0;

ll ansv = 1e18;
int au, av;

void dfs(int v, int pv = -1) {
    dp[v] = W[v];
    for (auto f : adj[v]) if (f != pv) {
        dfs(f, v);
        dp[v] += dp[f];
    }
}

void goSolve(int v, int pv = -1) {
    for (auto f : adj[v]) if (f != pv) {
        ll tans = abs(tot - 2 * dp[f]);
        if (tans <= ansv) {
            ansv = tans;
            au = f;
            av = v;
        }

        goSolve(f, v);
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
    tot = dp[1];

    goSolve(1);
    cout << ansv << '\n' << au << ' ' << av << '\n';

}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    int t = 1;
    // cin >> t;
    while (t--) solve();
}