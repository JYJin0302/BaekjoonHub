#include <bits/stdc++.h>
using namespace std;

vector<int> A;

vector<int> adj[200001];

int ans = 0;

void dfs(int v, int pv = 0){
    for (auto i : adj[v]) if (i != pv){
        if (A[v] != A[i]) ans++;
        dfs(i, v);
    }
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    
    int n;
    cin >> n;
    
    A = vector<int>(n+1);
    for(int i = 1; i <= n; i++) cin >> A[i];
    
    for(int i = 0; i < n-1; i++){
        
        int a, b;
        cin >> a >> b;
        
        adj[a].push_back(b);
        adj[b].push_back(a);
    }
    
    if (A[1] != 0) ans++;
    dfs(1);
    cout << ans;
}