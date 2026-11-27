#include <bits/stdc++.h>
using namespace std;
using ll = long long;

ll n, m, k;
ll s, d, cnt;
vector<ll> adj[100001];
bool visited[100001];

void dfs(ll v, ll pv){
    for (auto i : adj[v]) if (i != pv && !visited[i]){
        visited[i] = 1;
        cnt++;
        dfs(i, v);
    }
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    
    cin >> n >> m >> k;
    cnt = 0;
    
    for (ll i = 1; i <= m; i++){
        int a, b;
        cin >> a >> b;
        adj[a].push_back(b);
        adj[b].push_back(a);
        
        if (i == k) s = a, d = b;
    }
    
    visited[s] = 1;
    dfs(s, d);
    
    if (visited[d]) {
        cout << 0;
        return 0;
    }
    
    ll a1 = cnt;
    cnt = 0;
    visited[d] = 1;
    dfs(d, s);
    
    cout << (a1+1ll) * (cnt+1ll);
    
}