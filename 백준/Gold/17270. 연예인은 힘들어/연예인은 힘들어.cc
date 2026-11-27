#include <bits/stdc++.h>
using namespace std;

#define x first
#define y second

const int INF = 1e8;

vector<pair<int, int>> adj[101];

int dist_s[101];
int dist_d[101];

int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    
    int n, m;
    cin >> n >> m;
    
    for (int i = 0; i <= n; i++) {
        dist_s[i] = INF;
        dist_d[i] = INF;
    }
    
     for(int i = 0; i < m; i++){
         int a, b, c;
         cin >> a >> b >> c;
         
         adj[a].push_back({b, c});
         adj[b].push_back({a, c});
     }
    
    int s, d;
    cin >> s >> d;
    
    priority_queue<pair<int, int>> pq;
    pq.push({0, s});
    while(!pq.empty()){
        int a, b;
        tie(a, b) = pq.top();
        pq.pop();
        
        if (dist_s[b] != INF) continue;
        dist_s[b] = -a;
        
        for (auto i : adj[b]) if (dist_s[i.x] == INF){
            pq.push({a - i.y, i.x});
        }
    }
    
    pq.push({0, d});
    while(!pq.empty()){
        int a, b;
        tie(a, b) = pq.top();
        pq.pop();
        
        if (dist_d[b] != INF) continue;
        dist_d[b] = -a;
        
        for (auto i : adj[b]) if (dist_d[i.x] == INF){
            pq.push({a - i.y, i.x});
        }
    }
    
    vector<tuple<int, int, int>> ans;
    for (int i = 1; i <= n; i++){
        if (i == s || i == d) continue;
        ans.push_back({dist_s[i] + dist_d[i], dist_s[i], i});
    }
    
    sort(ans.begin(), ans.end());
    
    int ans_val = get<0>(ans[0]);
    
    for (auto i : ans){
        int a, b, c;
        tie(a, b, c) = i;
        
        if (dist_s[c] > dist_d[c]) continue;
        if (a != ans_val) continue;
        
        cout << c << ' ';
        return 0;
    }
    cout << -1;
    
}