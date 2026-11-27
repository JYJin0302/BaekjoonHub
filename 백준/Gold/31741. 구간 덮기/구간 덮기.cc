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

    int n, s, e;
    cin >> n >> s >> e;

    vector<pair<int, int>> A;
    for (int i = 0; i < n; i++) {
        int a, b;
        cin >> a >> b;
        A.push_back(mp(a, b));
    }

    vector<ll> pre, suf;
    for (int i = 0; i < n; i++) {
        if (A[i].x <= s && A[i].y >= s) pre.push_back(A[i].y);
        if (A[i].x <= e && A[i].y >= e) suf.push_back(A[i].x);
    }

    sort(all(pre));
    sort(all(suf));

    ll ans = -1;
    for(int i = 0; i < n; i++){
        int ok = 0;
        ll res = 0;
        if (A[i].y >= e) ok++;
        else {
            int pos = lower_bound(all(suf), A[i].y) - suf.begin();
            if (pos < suf.size() && suf[pos] == A[i].y) ok++;
            else if (pos > 0 && pos - 1 < suf.size()) {
                ok++;
                res += A[i].y - suf[pos - 1];
            }
        }

        if (A[i].x <= s) ok++;
        else {
            int pos = lower_bound(all(pre), A[i].x) - pre.begin();
            if (pos < pre.size()) {
                ok++;
                res += pre[pos] - A[i].x;
            }
        }

        if (ok == 2) {
            if (ans == -1) ans = res;
            else ans = min(ans, res);
        }
    }
    cout << ans;



}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    int t = 1;
    // cin >> t;
    while (t--) solve();
}