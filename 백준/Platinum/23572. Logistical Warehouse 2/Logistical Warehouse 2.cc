#include <bits/stdc++.h>
using namespace std;

int n, k, ans;
vector<int> adj[100001];
int d[100001];

void dfs(int v, int pv = 0){
    
    int mv = k+10, Mv = -k-10;
    for(auto i : adj[v]) if (i != pv){
        dfs(i, v);
        mv = min(mv, d[i]+1);
        Mv = max(Mv, d[i]+1);
    }
    
    if (adj[v].size() == 1 && pv != 0) {
        d[v] = 0;
        return;
    }
    
    if (mv >= 0) d[v] = Mv;
    else if (Mv < 0) d[v] = mv;
    else {
        if (abs(mv) - 1 >= Mv) d[v] = mv;
        else d[v] = Mv;
    }
    
    if (d[v] == -n) d[v] = 0;
    else if (d[v] == k) {
        ans++;
        d[v] = -k-1;
    }
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    
    cin >> n >> k;
    
    for(int i = 0; i < n-1; i++){
        int a, b;
        cin >> a>> b;
        adj[a].push_back(b);
        adj[b].push_back(a);
    }
    
    for (int i = 1; i <= n; i++) d[i] = -n;
    
    ans = 0;
    dfs(1);
    if (d[1] >= 0) ans++;
    cout << ans;
}