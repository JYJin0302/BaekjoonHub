#include <bits/stdc++.h>
using namespace std;
using ll = long long;

#define x first
#define y second
#define INF 2000100000

int n;
vector<ll> path, path2;
vector<bool> isR;
vector<vector<pair<ll, ll>>> adj;

void bfs(int v){
    
    path = vector<ll>(n+1, INF);
    path[v] = 0;
    
    queue<int> q;
    q.push(v);
    while(!q.empty()){
        
        int a = q.front();
        q.pop();
        
        for (auto k : adj[a]) if (path[k.x] == INF){
            path[k.x] = path[a] + k.y;
            q.push(k.x);
        }
    }
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    
    cin >> n;
    
    path = vector<ll>(n+1, INF);
    isR = vector<bool>(n+1);
    adj = vector<vector<pair<ll, ll>>> (n+1);
    for (int i = 0; i < n-1; i++){
        
        ll a, b, c;
        cin >> a >> b >> c;
        
        adj[a].push_back({b, c});
        adj[b].push_back({a, c});
    }
    
    bfs(1);
    int v = max_element(path.begin() + 1, path.end()) - path.begin();
    bfs(v);
    int nv = max_element(path.begin() + 1, path.end()) - path.begin();
    
    path2 = path;
    bfs(nv);
    
    for (int i = 1; i <= n; i++){
        cout << max(path[i], path2[i]) << '\n';
    }
    
}