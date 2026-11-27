#include <bits/stdc++.h>
using namespace std;
#define x first
#define y second

const int INF = 1000000000;

vector<pair<int, int>> adj[4001];
int dist_f[4001][2];
int dist_w[4001];

int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    
    int n, m;
    cin >> n >>  m;
    
    for (int i = 1; i <= n; i++){
        dist_f[i][0] = INF, dist_f[i][1] = INF;
        dist_w[i] = INF;
    }
    
    for(int i = 0; i < m; i++){
        
        int a, b, d;
        cin >> a >> b >> d;
        d*=2;
        
        adj[a].push_back({b, d});
        adj[b].push_back({a, d});
    }
    
    priority_queue<pair<int, int>> pq;
    pq.push({0, 1});
    while(!pq.empty()){
        
        int a, b;
        tie(a, b) = pq.top();
        pq.pop();
        a *= -1;
        
        if (dist_w[b] != INF) continue;
        dist_w[b] = a;
        
        for (auto i : adj[b]){
            if (dist_w[i.x] == INF){
                pq.push({-(a + i.y), i.x});
            }
        }        
    }
    
    priority_queue<tuple<int, int, int>> p;
    p.push({0, 1, 0});
    
    while(!p.empty()){
        
        int a, b, c;
        tie(a, b, c) = p.top();
        p.pop();
        
        a *= -1;
        if (dist_f[b][c] != INF) continue;
        dist_f[b][c] = a;
        
        int nc = 1 - c;
        for (auto i : adj[b]){
            if (dist_f[i.x][nc] == INF){
                int nd = a;
                if (c == 1) nd += i.y*2;
                else nd += i.y/2;
                
                p.push({-nd, i.x, nc});
            }
        }        
    }
    
    int cnt = 0;
    for (int i = 2; i <= n; i++){
       if(dist_w[i] < min(dist_f[i][0], dist_f[i][1])) cnt++;
    }
    
    cout << cnt;
    
}