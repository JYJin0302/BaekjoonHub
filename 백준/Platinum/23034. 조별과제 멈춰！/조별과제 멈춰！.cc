#include <bits/stdc++.h>
using namespace std;

#define x first
#define y second

vector<pair<int, int>> adj[1001];

int root[1001], L[1001], p[1001], dep[1001];

int t[1001][1001];

int find(int n){
    if (root[n] == n) return n;
    return root[n] = find(root[n]);
}

void dfs(int v, int pv = 0, int d = 1){
    dep[v] = d;
    for (auto i : adj[v]) if (i.x != pv){
        p[i.x] = v;
        L[i.x] = i.y;
        dfs(i.x, v, d+1);
    }
}

int solve(int l, int r){
    if (t[l][r] != -1) return t[l][r];
    if (l == r) return t[l][r] = 0;
    
    if (dep[l] > dep[r]) swap(l, r);
    
    t[l][r] = max(L[r], solve(p[r], l));
    t[r][l] = t[l][r];
    return t[l][r];
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    
    int n, m;
    cin >> n >> m;
    
    for(int i = 1; i <= n; i++) root[i] = i;
    for(int i =1 ; i <= n; i++) for (int j = 1; j <= n; j++) t[i][j] = -1;
    
    vector<tuple<int, int, int>> edge(m);
    
    for(int i= 0; i < m; i++){
        int a, b, c;
        cin >> a >> b >> c;
        edge[i] = {c, a, b};
    }
    
    sort(edge.begin(), edge.end());
    
    int val = 0;
    for(auto i : edge){
        int a, b, c;
        tie(a, b, c) = i;
        
        find(b), find(c);
        if (root[b] != root[c]){
            val += a;
            root[root[b]] = root[c];
            adj[b].push_back({c, a});
            adj[c].push_back({b, a});
        }
    }
    
    dfs(1);
    
    int q;
    cin >> q;
    while(q--){
        int a, b;
        cin >> a >> b;
        
        cout << val - solve(a, b) << '\n';
    }
}