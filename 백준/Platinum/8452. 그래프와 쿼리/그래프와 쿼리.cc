#include <bits/stdc++.h>
using namespace std;

#define x first
#define y second
#define INF 1000000

int path[1001];  // path[x] : x에서 1까지의 거리

vector<vector<int>> adj;

void bfs(int v){
    
    queue<int> q;
    q.push(v);
    
    while(!q.empty()){
        
        int a = q.front(); q.pop();
        for (auto i : adj[a]) if (path[i] > path[a] + 1){
            path[i] = path[a] + 1;
            q.push(i);
        }
    }
    
}

int main(){
    
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    
    
    int n, m, q;
    cin >> n >> m >> q;
    
    for(int i = 1; i <= n; i++) path[i] = INF;
    path[1] = 0;
    
    vector<pair<int, int>> edge(m);
    adj = vector<vector<int>>(n+1);
    for(auto& i : edge) cin >> i.x >> i.y;
    
    vector<pair<char, int>> query(q);
    for(auto& i: query) cin >> i.x >> i.y;
    
    vector<bool> erase(m);
    for(auto i : query) if (i.x == 'U') erase[i.y - 1] = 1;
    
    for(int i = 0; i < m; i++){
        if (!erase[i]) {
            adj[edge[i].x].push_back(edge[i].y);
        }
    }
    
    bfs(1);
    
    reverse(query.begin(), query.end());
    vector<int> ans;
    for (auto i : query){
        
        if (i.x == 'E'){
            if (path[i.y] == INF) ans.push_back(-1);
            else ans.push_back(path[i.y]);
        }
        else{
            
            int a, b;
            tie(a, b) = edge[i.y - 1];
            
            adj[a].push_back(b);            
            bfs(a);
        }
    }
    
    reverse(ans.begin(), ans.end());
    
    for(auto i : ans) cout << i << '\n';
}