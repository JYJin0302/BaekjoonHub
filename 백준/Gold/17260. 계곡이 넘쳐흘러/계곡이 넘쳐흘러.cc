#include <bits/stdc++.h>
using namespace std;
using ll = long long;

ll n, k;
ll A[200001];
vector<int> adj[200001];

bool dfs(int v, int pv = 0){
    
    bool ok = 0;
    ll val = A[v];
    for(auto i : adj[v]) if(i != pv){
        dfs(i, v);
        val = max(val, max(0ll, A[i]-A[v]) / 2 + A[v]);
        ok |= (A[i] >= A[v]);
    }
    A[v] = val;
    return ok;
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    
    cin >> n >> k;
    
    for(int i = 1; i <= n; i++) cin >> A[i];
    
    for(int i = 0; i < n-1; i++){
        int a, b;
        cin >> a >> b;
        
        adj[a].push_back(b);
        adj[b].push_back(a);
    }
        
    cout << dfs(k);
}