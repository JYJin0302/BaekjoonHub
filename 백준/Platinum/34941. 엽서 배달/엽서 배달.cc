#include <bits/stdc++.h>
using namespace std;
using ll = long long;

#define mp make_pair
#define x first
#define y second
#define all(x) x.begin(), x.end()

vector<array<int, 3>> adj[303030];

int n;
int sz[303030];
ll dp[303030];
void dfs(int v, int pv = -1){
    sz[v] = 1;
    for(auto f : adj[v]) if (f[0] != pv){
        dfs(f[0], v);
        sz[v] += sz[f[0]];
        dp[v] += dp[f[0]] + 1ll * f[1] * sz[f[0]];
    }
}

ll ans = 0;
void dfs2(int v, int pv = -1, int szU = 0, ll dpU = 0){

    ll curAns = dp[v] + dpU;
    int curSize = n;
    ans = min(ans, curAns);
    for(auto f : adj[v]) if (f[0] != pv){
        // try go f[0]
        curSize = n - sz[f[0]];
        curAns -= dp[f[0]] + 1ll * f[1] * sz[f[0]];

        ll nDpU = curAns + 1ll * f[2] * curSize;
        dfs2(f[0], v, curSize, nDpU);
        curAns += dp[f[0]] + 1ll * f[1] * sz[f[0]];
    }

}

void solve(){
    
    cin >> n;
    for(int i =0 ;i < n-1; i++){
        int u, v, w1, w2;
        cin >> u >> v>> w1 >> w2;
        adj[u].push_back({v, w1, w2});
        adj[v].push_back({u, w2, w1});
    }

    dfs(1);

    ans = dp[1];
    dfs2(1);

    cout << ans << '\n';
}



int main(){
    std::ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int t = 1;
    //cin >> t;
    while(t--){
        solve();
    }
    return 0;
}