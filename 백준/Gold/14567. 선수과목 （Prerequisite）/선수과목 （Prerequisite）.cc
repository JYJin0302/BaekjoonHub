#include <bits/stdc++.h>
using namespace std;

int main(){
    
    int n, m;
    cin >> n >> m;
    
    vector<vector<int>> adj(n+1);
    vector<int> topo(n+1);
    for(int i = 0; i < m; i++){
        int a, b;
        cin >> a >> b;
        topo[b]++;
        adj[a].push_back(b);
    }
    
    queue<int> q;
    vector<int> ans(n+1);
    for(int i = 1; i <= n; i++){
        if (topo[i] == 0) {
            ans[i] = 1;
            q.push(i);
        }
    }
    
    while(!q.empty()){
        int a = q.front();
        q.pop();
        
        for(int i : adj[a]){
            topo[i]--;
            if (topo[i] == 0){
                ans[i] = ans[a] + 1;
                q.push(i);
            }
        }
    }
    
    for(int i = 1; i <= n; i++) cout << ans[i] << ' ';
    
}