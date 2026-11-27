#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define mp make_pair
#define all(x) x.begin(), x.end()
#define x first
#define y second

const int mod = 1e9 + 7;
vector<int> adj[202020];

int n;
int A[202020];
int sz[202020];
ll dp[202020];


void dfs(int v, int pv = -1) {
    sz[v] = 1;
    for (auto f : adj[v]) if (f != pv) {
        dfs(f, v);
        sz[v] += sz[f];
        (dp[v] += dp[f] * 10 % mod) %= mod;
    }
    (dp[v] += 1ll * A[v] * sz[v] % mod) %= mod;
}


ll ans = 0;
void dfs2(int v, int pv = -1, ll pVal = 0, ll pCnt = 0) {

    ll totVal = 0, totCnt = 0;
    totVal += (pVal * 10 + A[v] * pCnt) % mod;
    (totVal += dp[v]) %= mod;
    totCnt = n;
    ans = (ans + totVal) % mod;

    for (auto f : adj[v]) if (f != pv) {
        ll tCnt = totCnt - sz[f];
        ll tVal = totVal - (dp[f] * 10 + 1ll * A[v] * sz[f]) % mod;
        tVal = (tVal + mod) % mod;

        dfs2(f, v, tVal, tCnt);
    }
}

void solve() {
    
    cin >> n;

    for (int i = 1; i <= n; i++) cin >> A[i];
    for (int i = 0; i < n - 1; i++) {
        int a, b;
        cin >> a >> b;
        adj[a].push_back(b);
        adj[b].push_back(a);
    }

    dfs(1);
    dfs2(1);
    cout << ans << '\n';
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    int t = 1;
    // cin >> t;
    while (t--) solve();
}