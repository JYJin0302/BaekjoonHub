#include <bits/stdc++.h>
using namespace std;

vector<int> adj[10001];
int dis[10001];
int vis[10001];
bool isCut[10001];

int cnt = 1;
int dfs(int v, bool isroot){
    
    vis[v] = cnt++;
    int res_dis = vis[v];
    int c_cnt = 0;
    
    for (auto i : adj[v]) {
        if (vis[i] == 0){
            c_cnt++;
            int tv = dfs(i, 0);
            if (!isroot && tv >= vis[v]) {
                isCut[v] = 1;
            }
            
            res_dis = min(res_dis, tv);
        }
        else res_dis = min(res_dis, vis[i]);
    }
    
    if (isroot && c_cnt >= 2) isCut[v] = 1;
    
    return res_dis;
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    
    int n, m;
    cin >> n >> m;
    
    for(int i = 0; i < m; i++){
        int a, b;
        cin >> a>> b;
        adj[a].push_back(b);
        adj[b].push_back(a);
    }
    
    for (int i = 1; i <= n; i++){
        if (vis[i] == 0){
            dfs(i, 1);
        }
    }
    
    vector<int> ans;
    for (int i = 1; i <= n; i++) if (isCut[i]) ans.push_back(i);
    
    cout << ans.size() << '\n';
    for (int i : ans)cout << i << ' ';
    
}