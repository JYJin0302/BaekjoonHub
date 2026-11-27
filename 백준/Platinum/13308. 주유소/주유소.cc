#include <bits/stdc++.h>
using namespace std;
using ll = long long;

const ll INF = 1e18;

ll c[2501][2501];


int main(){
    
    ios::sync_with_stdio(false);
    cin.tie(0);
    
    for (int i = 0; i < 2501; i++){
        for (int j = 0; j < 2501; j++){
            c[i][j] = INF;
        }
    }
    int n, m;
    cin >> n >> m;
    
    vector<ll> cost(n+1);
    for(int i = 1; i <= n; i++) cin >> cost[i];
    
    vector<vector<pair<ll ,ll>>> adj(n+1);
    for (int i = 0; i < m; i ++){
        
        ll a, b, d;
        cin >> a >> b >> d;
        
        adj[a].push_back({b, d});
        adj[b].push_back({a, d});
    }
    
    priority_queue<tuple<ll, ll, ll>> pq;
    pq.push({0, -cost[1], 1});
    while(!pq.empty()){
        
        ll a, b, d;
        tie(a, b, d) = pq.top();
        pq.pop();
        
        a *= -1;
        b *= -1;
        
        if (c[d][b] != INF) continue;
        c[d][b] = a;
        if (d == n){
            cout << a;
            return 0;
        }
        
        for (auto i : adj[d]){
            ll x, y;
            tie(x, y) = i;
            
            ll na = a + b * y;
            ll z = min(b, cost[x]);
            if (c[x][z] == INF){
                pq.push({-na, -z, x});
            }
        }
    }
}