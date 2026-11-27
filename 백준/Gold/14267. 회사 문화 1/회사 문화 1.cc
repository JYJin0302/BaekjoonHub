#include <bits/stdc++.h>
using namespace std;

vector<vector<int>> adj;
vector<int> ans;

void dfs(int v){
    
    for (int i : adj[v]){
        ans[i] += ans[v];
        dfs(i);
    }
}
int main(){
    
    int n, m;
    cin >> n >> m;
    
    adj = vector<vector<int>>(n+1);
    ans = vector<int>(n+1);
    for (int i = 1; i <= n; i++){
        int a;
        cin >> a;
        if (a != -1){
            adj[a].push_back(i);
        }
    }
    
    for (int i = 0; i < m; i++){
        int a, b;
        cin >> a >> b;
        ans[a] += b;
    }
    
    dfs(1);
    
    for (int i = 1; i <= n; i++) cout << ans[i] << ' ';
}