#include <bits/stdc++.h>
using namespace std;

vector<vector<int>> adj;
vector<bool> check;
bool ok;

void dfs(int v, int cnt = 1){
    
    if (cnt == 5){
        ok = true;
        return;
    }
    
    for (int i : adj[v]){
        if (!check[i]){
            check[i] = 1;
            dfs(i, cnt+1);
            check[i] = 0;
        }
    }
}


int main(){
    ios::sync_with_stdio(false);
cin.tie(nullptr);
    int n, m;
    cin >> n >> m;
    
    adj = vector<vector<int>>(n);
    check = vector<bool>(n);
    
    for (int i = 0; i < m; i++){
        int a, b;
        cin >> a>>b;
        adj[a].push_back(b);
        adj[b].push_back(a);
    }
    
    ok = false;
    for (int i = 0; i < n; i++){
        
        check[i] = 1;
        dfs(i);
        check[i] = 0;
        if (ok){
            cout << 1;
            return 0;
        }
    }
    cout << 0;
}