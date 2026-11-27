#include <bits/stdc++.h>
using namespace std;
using ll = long long;

const ll INF = 1e18;

#define x first
#define y second

ll dist[101];
vector<pair<ll, ll>> adj[101];
vector<ll> rev[101];

int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    
    int n, m, s, d;
    cin >> n >> s >> d >> m;
    
    for (int i = 0; i < n; i++) dist[i] = INF;
    
    dist[s] = 0;
    
    for (int i = 0; i < m; i++){
        ll a, b, c;
        cin >> a >> b >> c;
        
        adj[a].push_back({b, c});
        rev[b].push_back(a);
    }
    
    vector<ll> cc(n);
    for(int i = 0; i < n; i++) cin >> cc[i];
    
    vector<bool> inf(n+1);
    for (int i = 1; i <= m; i++){
        for (int j = 0; j < n; j++){
            if (dist[j] == INF) continue;
            for (auto k : adj[j]){
                if (dist[k.x] > dist[j] + k.y - cc[k.x]){
                    dist[k.x] = dist[j] + k.y - cc[k.x];
                    
                    if (i == m) inf[k.x] = 1;
                }
            }
            
        }
    }
    
    vector<bool> v(n);
    v[d] = 1;
    queue<int> q;
    q.push(d);
    while(!q.empty()){
        int a = q.front();
        q.pop();
        
        for (auto k : rev[a]) if (!v[k]){
            v[k] = 1;
            q.push(k);
        }
    }
    
    bool maxMoney = 0;
    for (int i = 0; i < n; i++){
        if (inf[i] && v[i]) maxMoney = 1;
    }
    
    if (dist[d] == INF) cout << "gg";
    else if (maxMoney) cout << "Gee";
    else cout << -dist[d] + cc[s];
}