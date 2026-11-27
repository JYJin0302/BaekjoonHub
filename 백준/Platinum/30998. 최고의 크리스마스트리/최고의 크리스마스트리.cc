#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define mp make_pair

const ll mod = 998244353;

int n;
vector<int> adj[202020];

ll fastPow(ll b, ll ex) {
    ll res = 1;
    while (ex) {
        if (ex & 1) {
            res = res * b % mod;
        }
        ex >>= 1;
        b = b * b % mod;
    }
    return res;
}

ll F[202020], inv[202020];
ll dp[202020], sz[202020], ans[202020];

void dfs(int v, int pv = -1) {
    sz[v] = 1;
    dp[v] = 1;
    ll res = 1;
    for (auto f : adj[v]) if (f != pv) {
        dfs(f, v);
        dp[v] = dp[v] * dp[f] % mod;
        sz[v] += sz[f];
        res = res * inv[sz[f]] % mod;
    }
    res = res * F[sz[v]-1] % mod;
    dp[v] = dp[v] * res % mod;
}

void getAns(int v, int pv = -1, ll uDp = 1, ll uSz = 0) {
    ans[v] = F[n-1];
    ans[v] = ans[v] * inv[uSz] % mod;

    ll totDp = uDp;
    for (auto f : adj[v]) if (f != pv){
        totDp = totDp * dp[f] % mod;
        ans[v] = ans[v] * inv[sz[f]] % mod;
    }
    ans[v] = ans[v] * totDp % mod;

    //cout << "GET: " << v << ' ' << ans[v] << ' ' << totDp << '\n';

    for (auto f : adj[v]) if (f != pv) {
        ll newDp = ans[v];
        newDp = newDp * inv[n - 1] % mod;
        newDp = newDp * F[n - 1 - sz[f]] % mod;
        newDp = newDp * F[sz[f]] % mod;
        newDp = newDp * fastPow(dp[f], mod - 2) % mod;

        ll newSz = n - sz[f];
        getAns(f, v, newDp, newSz);
    }

}

void solve() {

    cin >> n;
    for (int i = 0; i < n - 1; i++) {
        int a, b;
        cin >> a >> b;
        adj[a].push_back(b);
        adj[b].push_back(a);
    }

    F[0] = 1;
    for (int i = 1; i <= n; i++) F[i] = F[i - 1] * i % mod;
    for (int i = 0; i <= n; i++) {
        inv[i] = fastPow(F[i], mod - 2);
    }

    dfs(1);
    ans[1] = dp[1];
    getAns(1);


    int q;
    cin >> q;
    while (q--) {
        int x;
        cin >> x;
        cout << ans[x] << '\n';
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout << fixed << setprecision(3);
    solve();
    return 0;
}
