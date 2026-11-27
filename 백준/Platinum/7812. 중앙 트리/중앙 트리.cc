#include <bits/stdc++.h>
using namespace std;
using ll = long long;

#define x first
#define y second

ll n;
vector<pair<ll, ll>> adj[10001];
ll num[10001];
ll dp[10001];
ll tdp[10001];
ll ans = 1e15;

void dfs(int v, int pv = -1){
    for (auto i : adj[v]) if (i.x != pv){
        dfs(i.x, v);
        num[v] += num[i.x];
        dp[v] += dp[i.x]+num[i.x]*i.y;
    }
}

void solve(int v, int pv = -1){
    for (auto i : adj[v]) if (i.x != pv){
        tdp[i.x] += (tdp[v] + dp[v] - (dp[i.x]+num[i.x]*i.y)) + (n - num[i.x])*i.y;
        solve(i.x, v);
    }
    ans = min(ans, tdp[v] + dp[v]);
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    
    cin >> n;
    
    while(n){
        
        for (int i = 0; i < n; i++) {
            num[i] = 1, dp[i] = 0, tdp[i] = 0;
            adj[i].clear();
        }
        
        for (int i = 0; i < n-1; i++){
            ll a, b, c;
            cin >> a>> b >> c;
            adj[a].push_back({b, c});
            adj[b].push_back({a, c});
        }
        
        dfs(0);
        
        ans = dp[0];
        solve(0);
        
        cout << ans << '\n';
        cin >> n;
    }
}