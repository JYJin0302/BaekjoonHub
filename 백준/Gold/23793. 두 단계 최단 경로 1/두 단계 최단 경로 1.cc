#include <bits/stdc++.h>
using namespace std;
using ll = long long;

#define x first
#define y second

vector<pair<ll, ll>> adj[100001];

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
    }
    
    ll s, k, d;
    cin >> s >> k >> d;
    
    for (int i = 1; i <= n; i++){
        dist[i][0] = INF;
        dist[i][1] = INF;
    }
    
    priority_queue<tuple<ll, ll, bool>> pq;
    pq.push({0, s, (s == k)});
    while(!pq.empty()){
        
        ll a, b;
        bool p;
        tie(a, b, p) = pq.top();
        pq.pop();
        
        if (dist[b][p] != INF) continue;
        dist[b][p] = -a;
        
        for (auto tk : adj[b]) {
            ll nb, na;
            bool np;
            
            nb = tk.x;
            na = a - tk.y;
            np = p | (nb == k);
            
            if (dist[nb][np] == INF){
                pq.push({na, nb, np});
            }
        }
    }
    
    if (dist[d][1] != INF) cout << dist[d][1];
    else cout << -1;
    cout << ' ';
    if (dist[d][0] != INF) cout << dist[d][0];
    else cout << -1;
}