#include <bits/stdc++.h>
using namespace std;
using ll = long long;

vector<int> adj[130000];
ll val[130000];


void dfs(int v){
    for(auto i : adj[v]){
        dfs(i);
        val[v] += val[i];
    }
    
    val[v] = max(0ll, val[v]);
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    
    int n;
    cin >> n;
    
    for(int i = 2; i <= n; i++){
        char c;
        ll a, b;
        cin >> c >> a >> b;
        
        adj[b].push_back(i);
        if (c == 'S') val[i] = a;
        else val[i] = -a;
    }
    dfs(1);
    
    cout << val[1];
}