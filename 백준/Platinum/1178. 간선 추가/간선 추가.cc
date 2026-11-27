#include <bits/stdc++.h>
using namespace std;

vector<int> adj[1001];
bool vis[1001];

int cnt = 0;
void dfs(int v, int pv = -1){
    vis[v] = 1;
    cnt += (adj[v].size() % 2);
    for (auto i : adj[v]) if (i != pv && !vis[i]){
        dfs(i, v);
    }
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    
    int v, e;
    cin >> v>> e;
    
    for(int i = 0; i < e; i++){
        int a, b;
        cin >> a >> b;
        adj[a].push_back(b);
        adj[b].push_back(a);
    }
    
    vector<int> A;
    for(int i = 1; i <= v; i++){
        if (!vis[i]){
            cnt = 0;
            dfs(i);
            A.push_back(cnt);
        }
    }
    
    int ans = 0;
    int cnt0 = 0;
    for(int i : A) {
        cnt0 += (i == 0);
        if (i > 2) ans += (i - 2) / 2;
    }
    int cnt2 = A.size() - cnt0;
    
    ans += max(0, cnt2 - 1);
    cnt2 = min(1, cnt2);
    
    ans += max(0, cnt0-1);
    if (cnt0 != 0) ans += cnt2;
    
    cout << ans;
}