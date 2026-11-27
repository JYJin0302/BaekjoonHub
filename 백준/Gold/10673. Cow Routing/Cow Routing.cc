#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main(){
    
    ll a, b, n;
    cin >> a >> b >> n;
    
    vector<bool> v(1001);
    
    vector<vector<tuple<ll, ll, ll>>> adj(1001);
    
    for (int i = 0; i < n; i++){
        
        ll c, m;
        cin >> c >> m;
        
        vector<ll> t(m);
        for(auto& i : t) cin >> i;
        
        for (ll j = 0; j < m; j++){
            for (ll k = j + 1; k < m; k++){
                ll s = t[j], d = t[k];
                adj[s].push_back({c, k - j, d});
            }
        }
    }
    
    priority_queue<tuple<ll, ll, ll>> pq; // 비용, 이용 횟수
    pq.push({0, 0, a});
    
    while(!pq.empty()){
        ll x, y, z;
        tie(x, y, z) = pq.top();
        pq.pop();
        
        if (v[z]) continue;
        v[z] = 1;
        
        x *= -1;
        y *= -1;
        if (z == b) {
            cout << x << ' ' << y;
            return 0;
        }
        
        for (auto i : adj[z]){
            
            ll x1, y1, z1;
            tie(x1, y1, z1) = i;
            
            if (v[z1]) continue;
            
            pq.push({-(x + x1), -(y + y1), z1});
        }
    }
    
    cout << "-1 -1";
    
}