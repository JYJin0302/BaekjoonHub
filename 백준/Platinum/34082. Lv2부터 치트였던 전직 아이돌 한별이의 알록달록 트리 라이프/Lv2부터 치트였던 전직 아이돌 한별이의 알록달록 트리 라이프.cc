#include <bits/stdc++.h>
using namespace std;
using ll = long long;


#define x first
#define y second
#define all(x) x.begin(), x.end()
#define mp make_pair

int n, mod;
vector<int> adj[303030];
ll dp[303030][2];

void dfs(int v, int pv= -1){
    dp[v][0] = 1, dp[v][1] = 1;
    vector<pair<ll, ll>> res;
    for(auto f : adj[v]) if (f != pv){
        dfs(f, v);
        res.push_back(mp(dp[f][0], dp[f][1]));
    }
    if (res.empty()) return;

    // 1 : 하나 다르게 할 수 있음, 0: 전부 같게 해야함
    for(auto[a,b] : res){
        dp[v][0] = dp[v][0] * b % mod;
    }
    dp[v][1] = dp[v][0];
    int tn = (int)res.size();
    vector<ll> L(tn), R(tn);
    for(int i = 0; i < tn; i++){
        L[i] = res[i].y;
        if(i)L[i] = L[i-1] * L[i] % mod;
    }
    for(int i = tn-1; i >= 0; i--){
        R[i] = res[i].y;
        if (i != tn-1){
            R[i] = R[i+1] * R[i] % mod;
        }
    }

    for(int i =0 ; i <tn; i++){
        ll val = res[i].x;
        if (i) val = val * L[i-1] % mod;
        if (i != tn-1) val = val * R[i+1] % mod;
        dp[v][1] = (dp[v][1] + val) % mod;
    }

    //cout << "Dp: " << v << " | " << dp[v][0] << ' ' << dp[v][1] << '\n';
}
void solve(){

    cin >> n >> mod;

    for(int i =0 ; i < n-1; i++){
        int a, b;
        cin >> a>> b;
        adj[a].push_back(b);
        adj[b].push_back(a);
    }

    ll tot = 1;
    for(int i = 0; i < n;i++){
        tot = tot * 2 % mod;
    }

    dfs(1);

    ll ans = (tot - dp[1][1] * 2) % mod + mod;
    cout << ans % mod << '\n';
    
}
 
int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    int t = 1;
    //cin >> t;
    while(t--){
        solve();
    }
    return 0;
}