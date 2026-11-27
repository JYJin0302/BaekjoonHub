#include <bits/stdc++.h>
using namespace std;
using ll = long long;

#define x first
#define y second

int n;
vector<pair<ll, ll>> adj[300001];
ll dp[300001];
ll num[300001];

ll dp_T[300001];

void dfs(int v, int pv = -1){
    num[v] = 1;
    for(auto i : adj[v]) if (i.x != pv){
        dfs(i.x, v);
        dp[v] += dp[i.x] + num[i.x]*i.y;
        num[v] += num[i.x];
    }
}

void solve(int v, int pv = -1){
    for(auto i : adj[v]) if (i.x != pv){
        dp_T[i.x] = dp[v] - (dp[i.x] + num[i.x]*i.y) + dp_T[v] + i.y* (n - num[i.x]);
        solve(i.x, v);
    }
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    
    cin >> n;
    
    for(int i =0 ; i <n -1; i++){
        ll a, b, d;
        cin >> a >> b >> d;
        adj[a].push_back({b, d});
        adj[b].push_back({a, d});
    }
    
    dfs(1);
    solve(1);
    for(int i =1 ; i <= n; i++) cout << dp[i] + dp_T[i] << '\n';
}