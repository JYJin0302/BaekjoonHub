#include <bits/stdc++.h>
using namespace std;

int n, m, logn;
vector<vector<int>> sparse, adj;
vector<int> dep;

void dfs(int v, int pv = 0, int d = 1){
    dep[v] = d;
    for(int i : adj[v]) if (i != pv){
        dfs(i, v, d+1);
        sparse[i][0] = v;
    }
}

int LCA(int u, int v){
    
    if (dep[u] > dep[v]) swap(u, v);
    
    int diff = dep[v] - dep[u];
    for(int i = 0; i < logn; i++){
        if (diff & (1 << i)) v = sparse[v][i];
    }
    
    for(int i = logn - 1; i >= 0; i--){
        if (sparse[u][i] != sparse[v][i]){
            u = sparse[u][i];
            v = sparse[v][i];
        }
    }
    
    if (u != v) u = sparse[u][0];
    
    return u;
}

int main(){
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
    cin >> n;
    logn = log2(n) + 1;
    
    adj = vector<vector<int>>(n+1);
    sparse = vector<vector<int>>(n+1, vector<int>(logn));
    dep = vector<int>(n+1);
    
    for(int i = 0; i < n-1; i++){
        int a, b;
        cin >> a >> b;
        adj[a].push_back(b);
        adj[b].push_back(a);
    }
    
    dfs(1);
    
    // set sparse table
    for(int i = 1; i < logn; i++){
        for(int j = 1; j <= n; j++){
            sparse[j][i] = sparse[sparse[j][i-1]][i-1];
        }
    }
    
    cin >> m;
    // query
    while(m--){
        int r, u, v;
        cin >> r >> u >> v;
        
        int ans = LCA(u, v);
        int t = LCA(r, u);
        if (dep[ans] < dep[t]) ans = t;
        
        t = LCA(r, v);
        if (dep[ans] < dep[t]) ans = t;
        
        cout << ans << '\n';
    }
}