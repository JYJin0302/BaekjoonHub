#include <bits/stdc++.h>
using namespace std;

int n, s, d;
int ans = 0;

int dist[100001];
vector<int> adj[100001];

void dfs(int v, int pv = -1){
    
    for(auto i : adj[v]) if (i != pv){
        dfs(i, v);
        dist[v] = max(dist[v], dist[i] + 1);
    }
}

int dfs1(int v, int pv= -1){
    
    if (dist[v] <= d) return 0;
    
    int res = 0;
    for (auto i : adj[v]) if (i != pv){
        
        if (dist[i] > d) res += dfs1(i, v) + 1;
    }
    
    return res;
}
int main(){
    
    ios::sync_with_stdio(false);
    cin.tie(0);
    
    
    cin >> n >> s >> d;
    for(int i = 0; i < n-1; i++){
        int a, b;
        cin >> a >> b;
        adj[a].push_back(b);
        adj[b].push_back(a);
    }
    
    for (int i = 1; i <= n; i++) dist[i] = 1;
    
    dfs(s);
    
    cout << dfs1(s) * 2;
    
}