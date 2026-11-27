#include <bits/stdc++.h>
using namespace std;

vector<int> adj[100001];
int c[100001], p[100001];
int ans = 0;

void dfs(int v, int pv = 0){
    int r = 0;
    for (auto i : adj[v]) if (i != pv){
        dfs(i, v);
        r = max(r, c[i]);
    }
    c[v] = r+1;
}

void dfs2(int v, int pv = 0){
    int r = 1;
    r = max(r, p[v]);
    
    vector<int> tmp = {r, 1, 1};
    
    for (auto i : adj[v]) if (i != pv){
        tmp.push_back(c[i] + 1);
    }
    sort(tmp.rbegin(), tmp.rend());
    
    if (adj[v].size() >= 3) ans= max(ans, tmp[0] + tmp[1] + tmp[2] - 2);
    
    for (auto i : adj[v]) if (i != pv){
        if (c[i] + 1 == tmp[0]) p[i] = tmp[1] + 1;
        else p[i] = tmp[0] + 1;
        dfs2(i, v);
    }
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    
    int n;
    cin >> n;
    
    for (int i = 0; i < n-1; i++){
        int a, b;
        cin >> a>> b;
        adj[a].push_back(b);
        adj[b].push_back(a);
    }
    
    dfs(1);
    dfs2(1);
    
    cout << ans;
}