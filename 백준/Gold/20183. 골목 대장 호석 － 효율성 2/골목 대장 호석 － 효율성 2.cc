#include <bits/stdc++.h>
using namespace std;
using ll = long long;

const ll INF = 1e18;
vector<pair<ll, ll>> adj[100001];

int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    
    ll n, m, a, b, c;
    cin >> n >> m >> a >> b >> c;
    
    for(int i = 0; i < m; i++){
        
        ll x, y, z;
        cin >> x >> y >> z;
        adj[x].push_back({y, z});
        adj[y].push_back({x, z});
    }
    
    ll L = 1, R = 1e9, ans = -1;
    while(L <= R){
        
        ll mid = (L+R)/2;
        
        vector<ll> dist(n+1, INF);        
        priority_queue<pair<ll, ll>> pq;
        pq.push({0, a});
        
        while(!pq.empty()){
            
            ll x, y;
            tie(x, y) = pq.top();
            pq.pop();
            
            if (dist[y] != INF) continue;
            dist[y] = -x;
            
            for(auto i : adj[y]){
                ll nx, ny;
                tie(nx, ny) = i;
                
                if (dist[nx] == INF && ny <= mid){
                    pq.push({x - ny, nx});
                }
            }
        }
        
        if (dist[b] <= c){
            ans = mid;
            R = mid-1;
        }
        else L = mid+1;
    }
    
    cout << ans;
}