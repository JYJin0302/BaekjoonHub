#include <bits/stdc++.h>
using namespace std;
using ll = long long;

#define x first
#define y second

vector<pair<ll, ll>> adj[100001];
bool isP[100001];

ll dist[100001][2];

const ll INF = 1e18;

int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    
    ll n, m;
    cin >> n >> m;
    
    for(int i = 0; i < m;i++){
        ll a, b, c;
        cin >> a >> b >> c;
        adj[a].push_back({b, c});
        adj[b].push_back({a, c});
    }
    
    int s, d;
    cin >> s >> d;
    
    int k;
    cin >> k;
    while(k--){
        int a;
        cin >> a;
        isP[a] = 1;
    }
    
    for (int i = 1; i <= n; i++){
        dist[i][0] = INF;
        dist[i][1] = INF;
    }
    
    priority_queue<tuple<ll, ll, bool>> pq;
    pq.push({0, s, isP[s]});
    while(!pq.empty()){
        
        ll a, b;
        bool p;
        tie(a, b, p) = pq.top();
        pq.pop();
        
        if (dist[b][p] != INF) continue;
        dist[b][p] = -a;
        
        for (auto k : adj[b]) {
            ll nb, na;
            bool np;
            
            nb = k.x;
            na = a - k.y;
            np = p | isP[nb];
            
            if (dist[nb][np] == INF){
                pq.push({na, nb, np});
            }
        }
    }
    if (dist[d][1] != INF) cout << dist[d][1];
    else cout << -1;
}