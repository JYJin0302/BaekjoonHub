#include <bits/stdc++.h>
using namespace std;

vector<int> adj[200001];
int p[200001];

int ans = 0;
void dfs(int v, int pv = -1){
    
    if (adj[v].size() == 0){
        ans++;
        return;
    }
    if (pv != -1 && adj[v].size() == 1){
        p[v] = 1;
        return;
    }
    
    int val = -1;
    bool ok = 0;
    for (auto i : adj[v]) if (i != pv){
        dfs(i, v);
        val = max(val, p[i]+1);
        if (p[i] == -1) ok = 1;
    }
    
    if (val == 2) {
        val = -1;
        ans++;
    }
    else if (ok) val = 0;
    
    p[v] = val;
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    
    int n, m;
    cin >> n >> m;
    
    for(int i =1; i <= n; i++) p[i] = -10;
    
    while(m--){
        int a, b;
        cin >> a >> b;
        
        adj[a].push_back(b);
        adj[b].push_back(a);
    }
    
    for(int i = 1; i<= n; i++){
        if (p[i] == -10) {
            dfs(i);
            if (p[i] == 1) ans++;
        }
    }
    cout << ans;
}