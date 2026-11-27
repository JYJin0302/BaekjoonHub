#include <bits/stdc++.h>
using namespace std;
using ll = long long;

vector<ll> adj[1010];

int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);

    int n;
    cin >> n;
    
    for(int i =0 ; i < n*(n-1)/2; i++){
        int a, b;
        ll w;
        cin >> a >> b >> w;
        
        adj[a].push_back(w);
        adj[b].push_back(w);
    }
    
    ll ans = 0;
    for(int i = 1; i <= n; i++){
        sort(adj[i].rbegin(), adj[i].rend());
        
        for(int j = 0; j < n-1; j += 2) ans += adj[i][j];
    }
    
    cout << ans;
}
