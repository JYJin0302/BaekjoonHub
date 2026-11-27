#include <bits/stdc++.h>
using namespace std;
using ll = long long;

const ll MAX_N = 50005;
const ll INF = 100000000000;
vector<pair<ll, ll>> adj[MAX_N];
ll dist_s[MAX_N];
ll dist_t[MAX_N];

#define x first
#define y second

int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    
    ll n, m, f, s, t;
    cin >> n >> m >> f >> s >> t; 
    
    for (int i = 0; i < m; i++){
        ll a, b, c;
        cin >> a >> b >> c;
        
        adj[a].push_back({b, c});
        adj[b].push_back({a, c});
    }
    
    vector<pair<ll, ll>> ff(f);
    for (int i = 0; i < f; i++){
        ll a, b;
        cin >> a >> b;
        ff[i] = {a, b};
    }
    
    for (int i = 0; i < MAX_N; i++) dist_s[i] = INF, dist_t[i] = INF;
    
    // from start
    priority_queue<pair<ll, ll>> pq;
    pq.push({0, s});
    while(!pq.empty()){
        
        ll a, b;
        tie(a, b) = pq.top();
        pq.pop();


        if (dist_s[b] != INF) continue;
        dist_s[b] = -a;
        for (auto i : adj[b]){
            if (dist_s[i.x] == INF){
                pq.push({a - i.y, i.x});
            }
        }
    }
    
    // from end
    pq.push({0, t});
    while(!pq.empty()){
        
        ll a, b;
        tie(a, b) = pq.top();
        pq.pop();


        if (dist_t[b] != INF) continue;
        dist_t[b] = -a;
        for (auto i : adj[b]){
            if (dist_t[i.x] == INF){
                pq.push({a - i.y, i.x});
            }
        }
    }
    
    ll ans = INF;
    for (int i = 0; i < n; i++) ans = min(ans, dist_s[i] + dist_t[i]);
    
    for (auto i : ff){
        ans = min(ans, dist_s[i.x] + dist_t[i.y]);
    }
    
    cout<< ans;
}