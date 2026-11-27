#include <bits/stdc++.h>
using namespace std;
using ll = long long;

#define x first
#define y second

vector<pair<ll, ll>> adj[5001];
ll dist[5001];

int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    
    ll n;
    cin >> n;
    
    for(int i = 0; i < n-1; i++){
        ll a, b, c;
        cin >> a >> b >> c;
        adj[a].push_back({b, c});
        adj[b].push_back({a, c});
    }
    
    memset(dist, -1, sizeof(dist));
    
    queue<int> q;
    q.push(1);
    dist[1] = 0;
    while(!q.empty()){
        int a = q.front();
        q.pop();
        
        for(auto i : adj[a]) if (dist[i.x] == -1){
            dist[i.x] = dist[a] + i.y;
            q.push(i.x);
        }
    }
    
    ll ans = 0;
    for(int i = 1; i <= n; i++) ans= max(ans, dist[i]);
    cout << ans;
}