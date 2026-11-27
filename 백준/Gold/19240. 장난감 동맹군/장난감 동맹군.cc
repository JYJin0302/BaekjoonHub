#include <bits/stdc++.h>
using namespace std;

vector<vector<int>> adj;
vector<int> team; // 0: 미정, 팀1: 1, 팀2: 2
bool valid;

void dfs(int v, int t = 1){
    
    for (int i : adj[v]) {
        
        if (team[i] == team[v]) {
            valid = 0;
            return;
        }
        
        if (team[i] == 0){
            team[i] = 3 - t;
            dfs(i, 3 - t);
        }
    }
}

int main(){
    
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    
    int T;
    cin >> T;
    while(T--){
        
        int n, m;
        cin >> n >> m;
        
        adj = vector<vector<int>>(n+1);
        team = vector<int>(n+1);
        valid = 1;
        
        for (int i = 0; i < m; i++){
            int a, b;
            cin >> a >> b;
            
            adj[a].push_back(b);
            adj[b].push_back(a);
        }
        
        for (int i = 1; i <= n; i++){
            if (team[i] == 0){
                team[i] = 1;
                dfs(i);
            }
        }
        
        if (valid) cout << "YES\n";
        else cout << "NO\n";
    }
}