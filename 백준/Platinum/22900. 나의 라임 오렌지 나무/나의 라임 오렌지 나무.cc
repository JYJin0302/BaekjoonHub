#include <bits/stdc++.h>
using namespace std;

#define x first
#define y second

bool p[300001];
int w[300001];
vector<pair<int, int>> adj[300001];

void dfs(int v, int pv = 0){
    
    int win_cnt = 0;
    for(auto i : adj[v]) if (i.x != pv){
        dfs(i.x, v);
        if (w[i.x] == 0) win_cnt++;
    }
    
    w[v] = win_cnt;
}

void dfs2(int v, int pv = 0){
    for(auto i : adj[v]) if (i.x != pv){
        if (!p[v] && (w[v] == 0 || (w[i.x] == 0 && w[v] == 1))) p[i.x] = 1;
        dfs2(i.x, v);
    }
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    
    int n;
    cin >> n;
    
    for(int i = 0; i < n-1; i++){
        int a, b, c;
        cin >> a >> b >> c;
        adj[a].push_back({b, c});
        adj[b].push_back({a, c});
    }
    
    dfs(1);
    dfs2(1);
    
    for(int i = 1; i <= n; i++){
        if (w[i] > 0 || p[i]) cout << "Zeze\n";
        else cout << "Portuga\n";
    }
    
}