#include <bits/stdc++.h>
using namespace std;
using ll = long long;

#define x first
#define y second

ll n, m, k, s, d, val;
const ll INF = 1e9;

vector<pair<ll, ll>> adj[1001];

ll dist[1001][1001]; // dist[i][j] : s에서 i까지 j개의 간선을 거치고 가는 최단거리


int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    cin >> n >> m >> k;
    cin >> s >> d;
    
    for (int i = 0; i < m;i++){
        int a, b, c;
        cin >> a >> b >> c;
        
        adj[a].push_back({b, c});
        adj[b].push_back({a, c});
    }
    
    for (int i = 1; i <= n; i++){
        for (int j = 0; j <= n; j++){
            dist[i][j] = INF;
        }
    }
    
    priority_queue<tuple<int, int, int>> pq;
    pq.push({-0, -0, s}); // 횟수, 거리
    
    while(!pq.empty()){
        ll a, b, c;
        tie(b, a, c) = pq.top();
        pq.pop();
        
        a *= -1, b *= -1;
        if (b >= n || dist[c][b] != INF) continue;
        dist[c][b] = a;
        
        for (auto i : adj[c]) {
            if (dist[b+1][i.x] == INF){
                pq.push({-(b+1), -(a + i.y), i.x});
            }
        }
    }
    
    ll tmp = INF;
    val = 0;
    for (int i = 1; i <= n; i++){
        tmp= min(tmp, dist[d][i] + i*val);
    }
    cout << tmp << '\n';
    
    while(k--){
        ll x;
        cin >> x;
        val += x;
        
        ll res = INF;
        for (int i = 1; i <= n; i++){
            res= min(res, dist[d][i] + i*val);
        }
        cout << res << '\n';
    }
}